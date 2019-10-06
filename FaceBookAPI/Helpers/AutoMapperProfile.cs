using AutoMapper;
using FaceBookApi.Dtos;
using FaceBookApi.Entities;

namespace FaceBookApi.Helpers
{
    public class AutoMapperProfile : Profile
    {
        public AutoMapperProfile()
        {
            CreateMap<FBUser, UserDto>();
            CreateMap<UserDto, FBUser>();
        }
    }
}