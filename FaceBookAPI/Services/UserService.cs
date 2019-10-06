using System;
using System.Collections.Generic;
using System.Linq;
using FaceBookApi.Entities;
using FaceBookApi.Helpers;

namespace FaceBookApi.Services
{
    public interface IUserService
    {
        FBUser Authenticate(string username, string password);
        IEnumerable<FBUser> GetAll();
        FBUser GetById(int id);
        FBUser Create(FBUser user, string password);
    }

    public class UserService : IUserService
    {
        private FBDataContext context_;

        public UserService(FBDataContext context)
        {
            context_ = context;
        }

        public FBUser Authenticate(string username, string password)
        {
            if (string.IsNullOrEmpty(username) || string.IsNullOrEmpty(password))
                return null;

            var user = context_.Users.SingleOrDefault(x => x.Username == username);

            if (user == null)
                return null;

            if (!VerifyPasswordHash(password, user.PasswordHash, user.PasswordSalt))
                return null;

            return user;
        }

        public IEnumerable<FBUser> GetAll()
        {
            return context_.Users;
        }

        public FBUser GetById(int id)
        {
            return context_.Users.Find(id);
        }

        public FBUser Create(FBUser user, string password)
        {
            if (string.IsNullOrWhiteSpace(password))
                throw new Exception("Password cannot be empty");

            if (context_.Users.Any(x => x.Username == user.Username))
                throw new Exception("Username \"" + user.Username + "\" is already existing");

            byte[] passwordHash, passwordSalt;
            CreatePasswordHash(password, out passwordHash, out passwordSalt);

            user.PasswordHash = passwordHash;
            user.PasswordSalt = passwordSalt;

            context_.Users.Add(user);
            context_.SaveChanges();

            return user;
        }

        private static void CreatePasswordHash(string password, out byte[] passwordHash, out byte[] passwordSalt)
        {
            if (password == null)
                throw new ArgumentNullException("Password is null");
            if (string.IsNullOrWhiteSpace(password)) 
                throw new ArgumentException("Password is empty");

            using (var hmac = new System.Security.Cryptography.HMACSHA512())
            {
                passwordSalt = hmac.Key;
                passwordHash = hmac.ComputeHash(System.Text.Encoding.UTF8.GetBytes(password));
            }
        }

        private static bool VerifyPasswordHash(string password, byte[] storedHash, byte[] storedSalt)
        {
            if (password == null) 
                throw new ArgumentNullException("Password is null");
            if (string.IsNullOrWhiteSpace(password)) 
                throw new ArgumentException("Password is empty");
            

            using (var hmac = new System.Security.Cryptography.HMACSHA512(storedSalt))
            {
                var computedHash = hmac.ComputeHash(System.Text.Encoding.UTF8.GetBytes(password));
                for (int i = 0; i < computedHash.Length; i++)
                {
                    if (computedHash[i] != storedHash[i])
                        return false;
                }
            }

            return true;
        }
    }
}