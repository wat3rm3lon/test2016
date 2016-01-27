#include "stdafx.h"
#include "functions.h"

bool read_file(std::vector<int>& vec, std::string file_path){
    ifstream in;
    in.open(file_path, ios::ate);
    if(!in.is_open()){
        cout << "open failed " << endl;
        return FALSE;
    }
    long long size = in.tellg();
    if(size < 10){
        cout << "empty or corrupted file. size = " << size << endl;
        in.close();
        return FALSE;
    }
    in.seekg(0, ios::beg);

    string tmp;
    char delim = ' ';
    int counter = 0;
    while(getline(in, tmp, delim)){
        vec.push_back(atoi(tmp.c_str()));
        counter++;
    }
    in.close();
    return TRUE;
}
int start(){
    using namespace std;
    try{
        stringstream ss22;
        ofstream out;
        //out.open("I:\\test\\1m-ints.txt");
        out.open("..\\..\\..\\100-bytes.txt");
        if(!out.is_open()){
            cout << "open failed" << endl;
            return 1;
        }
        srand (static_cast<UINT>(time(NULL)));
        //for(int i = 0; i < 1000000; i++){
        for(int i = 0; i < 101; i++){
            //int number = rand();
            int number = rand() % 256;
            ss22 << number << " ";
        }
        out << ss22.str().c_str() << endl;
        //out << "AAAAAAAAAAAAAAAAAAA" << endl;
        //cout << ss22.str() << endl;
        //out.write(ss22.str().c_str(), ss22.);
        out.close();
    }catch(std::exception& exc){
        cout << exc.what() << endl;
        return 1;
    }
    _exit(0);

    string s1 = "to be or not to - be - - that - - - is ";
    queue<string> que;
    stringstream ss(s1);
    string item;
    char delim = ' ';
    while(getline(ss, item, delim)){
        if(item != "-")
            que.enqueue(item);
    }
    //que.printf();
    stringstream ss1;
    ss1 << "pos = " << 9000 << " text is "<< "ololo" << "asdfdasfasd" << endl;
    ss1 << "sdfdsafdsfdasfdsafa11111111111111111111111111111 " << endl;
    cout << ss1.str();
    cin.get();
#if 0
    string s1 = "to be or not to - be - - that - - - is ";
    stackA<string> stck;
    stringstream ss(s1);
    string item;
    char delim = ' ';
    while(getline(ss, item, delim)){
        if(item != "-")
            stck.push(item);
    }
    cin.get();

#endif

#if 0
    string s1 = "to be or not to - be - - that - - - is ";
    fixedStack fs(100);
    string item;
    string sdelim = " ";
    char delim = ' ';
    stringstream ss(s1);
    vector<string> vstr;
    while(getline(ss, item, delim)){
        if(item != "-"){
            char* ptmp = new char[item.length() + 1];
            //strcat(ptmp, item.c_str());
            strcpy_s(ptmp, item.length() + 1, item.c_str());
            ptmp[item.length()] = '\0';
            //fs.push(const_cast<char*>(item.c_str()));
            fs.push(ptmp);
        }
        //vstr.push_back(stmp);
    }
    for(int i = 0; i < fs.size(); i++){
        cout << fs.a[i] << endl;
    }
    cin.get();
#endif
    ///////working
#if 0
    stack<char> ops;
    stack<int> vals;
    char buf[128];
    //string s1 = "(5 + 15)";
    //string s1 = "(45 + 11 - 44)"; //missing )
    //string s1 = "((45 + 11) - 44)";

    //string s1 = "(1+((2+3)*(4*5)))"; //101
    //string s1 = "(1+(5*(4*5)))";
    string s1 = "(((15 / 3) + (11 * 2)) - 33) + 100)";
    cout << s1 << endl;
    int len = s1.length();
    for(int i = 0; i < len; i++){
        char token = s1.at(i);

        if(token == ' ') continue;
        else if(token == '(') continue;
        else if(token == '+') ops.push(token);
        else if(token == '-') ops.push(token);
        else if(token == '*') ops.push(token);
        else if(token == '/') ops.push(token);
        else if(token == ')'){
            char op = ops.top();
            ops.pop();
            int v = vals.top();
            int left, right;
            left = v;
            vals.pop();
            right = vals.top();
            if(op == '+') v = vals.top() + v;
            else if(op == '-') v = vals.top() - v;
            else if(op == '*') v = vals.top() * v;
            else if(op == '/') v = vals.top() / v;
            vals.pop();
            vals.push(v);
            cout << right << " '" << op << "' " << left << " = " << v << endl;
        }else{
            char buf[200];
            int pos = 0;
            for(int j = i; ; j++){
                char token_number = s1.at(j);
                if(!isdigit(token_number)){
                    i = j;
                    //if(pos > 1) i--;
                    i--;
                    break;
                }
                buf[pos] = token_number;
                pos++;
            }
            buf[pos] = '\0';
            int number = atoi(buf);
            vals.push(number);
        }
    }
    cout << "total value = " << vals.top();
    cin.get();
#endif
    return 0;
}
void listing114(){
    ifstream in;
    in.open("..\\..\\..\\files\\1k-ints.txt", ios::ate);
    if(!in.is_open()){
        cout << "open failed " << endl;
        return;
    }
    long long size = in.tellg();
    if(size < 1000){
        cout << "empty or corrupted file. size = " << size << endl;
        in.close();
        return;
    }
    in.seekg(0, ios::beg);
    vector<int> vints;
    string tmp;
    char delim = ' ';
    int counter = 0;
    while(getline(in, tmp, delim)){
        vints.push_back(atoi(tmp.c_str()));
        counter++;
    }
    binarySearch bs;
    int rank = bs.rank(25618, vints);
    cout << "total size = " << vints.size() << endl;
    cout << "binarySearch rank unsorted = " << rank << endl;
    std::sort(vints.begin(), vints.end());
    rank = bs.rank(25618, vints);
    cout << "binarySearch rank sorted = " << rank << endl;

    cin.get();
    in.close();
}
void listing141(){
try{
	ifstream in;
	//I:\\test\\1m-ints.txt
	//in.open("I:\\test\\1k-ints.txt", ios::ate); // 13
	//in.open("I:\\test\\2k-ints.txt", ios::ate); // 105
	//in.open("I:\\test\\4k-ints.txt", ios::ate); // 833
	in.open("..\\..\\..\\files\\1k-ints.txt", ios::ate);
    if(!in.is_open()){
		cout << "open failed " << endl;
		return;
	}
	long long size = in.tellg();
	if(size < 1000){
		cout << "empty or corrupted file. size = " << size << endl;
		in.close();
		return;
	}
	in.seekg(0, ios::beg);
	vector<int> vints;
	string tmp;
	char delim = ' ';
	int counter = 0;
	while(getline(in, tmp, delim)){
		vints.push_back(atoi(tmp.c_str()));
		counter++;
	}
	//ctime time(
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	threeSum sum;
	sum.count(vints);
	end = std::chrono::system_clock::now();
	
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

	in.close();
	cin.get();
	}catch(exception& exc){
		cout << exc.what() << endl;
		return;
	}
	/*
	char delim = ' ';
    while(getline(ss, item, delim)){
        if(item != "-")
            que.enqueue(item);
    }
	*/
}
void listing143(){
    ifstream in;
    in.open("..\\..\\..\\files\\1k-ints.txt", ios::ate);
    if(!in.is_open()){
        cout << "open failed " << endl;
        return;
    }
    long long size = in.tellg();
    if(size < 1000){
        cout << "empty or corrupted file. size = " << size << endl;
        in.close();
        return;
    }
    in.seekg(0, ios::beg);
    vector<int> vints;
    string tmp;
    char delim = ' ';
    int counter = 0;
    while(getline(in, tmp, delim)){
        vints.push_back(atoi(tmp.c_str()));
        counter++;
    }
    twoSumFast sf;
    in.close();
    int count = sf.count(vints);
    cout << "pairs count with 0 sum = " << count << endl;
    cin.get();
}
void listing144(){
    ifstream in;
    in.open("..\\..\\..\\files\\1k-ints.txt", ios::ate);
    if(!in.is_open()){
        cout << "open failed " << endl;
        return;
    }
    long long size = in.tellg();
    if(size < 1000){
        cout << "empty or corrupted file. size = " << size << endl;
        in.close();
        return;
    }
    in.seekg(0, ios::beg);
    vector<int> vints;
    string tmp;
    char delim = ' ';
    int counter = 0;
    while(getline(in, tmp, delim)){
        vints.push_back(atoi(tmp.c_str()));
        counter++;
    }
    threeSumfast sf;
    in.close();
    int count = sf.count(vints);
    cout << "3 count with 0 sum = " << count << endl;
    cin.get();
}
void listing151(){
    //std::string path("..\\..\\..\\files\\mediumUF.txt");
    std::string path("..\\..\\..\\files\\tinyUF.txt");
    std::vector<int> vints;
    if(!read_file(vints, path)){
        return;
    }
    int n = vints.size();
    uf uf2(n);
    for(UINT i = 0; i < vints.size() - 1; i += 2){
        int p = vints[i];
        int q = vints[++i];
        if(uf2.connected(p, q)){
            continue;
        }
        uf2.union_(p, q);
        cout << p << " " << q << endl;
    }
    cout << uf2.count_() << " components count" << endl;
    cin.get();
}