// sedgewick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sedgewick.h"

#include "functions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



template <class T>
struct node{
    T item;
    node* pnext;
    node& operator=(const node& nd){
        if(this != &nd){
            this->item = nd.item;
            this->pnext = nd.pnext;
        }
        return *this;
    }
    
};


template<class T>
class queue{
    node<T>* first;
    node<T>* last;
    int n;
public:
    queue(){ this->first = NULL; this->last = NULL; n = 0;}
    bool isEmpty(){ 
        //return first == NULL; 
        return n == 0;
    }
    int size(){ return n; }
    void enqueue(T item){
        //t is string
        node<T>* oldlast = last;
        last = new node<T>();
        last->item = item;
        last->pnext = NULL;
        if(isEmpty()){
            first = last;
        }else{
            oldlast->pnext = last;
        }
        n++;
    }
    T dequeue(){
        T item = first->item;
        first = first->pnext;
        if(isEmpty()){
            last = NULL;
        }
        n--;
        return item;
    }
    void printf(){
        //node<T>* pcurrent = this->last;
        node<T>* pcurrent = this->first;
        while(pcurrent != NULL){
            stringstream ss;
            ss << "pos = " << this->n << " text is "<< pcurrent->item << endl;
            cout << ss.str();
            pcurrent = pcurrent->pnext;
        }
    }
};


template<class T>
class stackA{
    node<T>* first; //head
    int n;
public:
    stackA(){ this->first = NULL; n =0; }
    bool isEmpty(){ return first == NULL; }
    int size(){ return n; }
    void push(T item){
        //item is string
        node<T>* oldfirst = first;
        first = new node<T>();
        first->item = item;
        first->pnext = oldfirst;
        n++;
        cout << "pushed '" << first->item << "' pos = " << n << endl;
    }
    T pop(){
        T item = first.item;
        first = first.pnext;
        n--;
        return item;
    }
};

class fixedStack{
public:
    char** a;
    int n;
public:
    fixedStack(int size){
        a = new char*[size]; 
        n = 0;
    }
    void push(char* item){ 
        a[n] = item; 
        n++;
        cout << "pushed '" << item << "' at pos = " << n << endl;
    }
    char* pop(){ 
        return a[n--];

    }
    bool isempty(){ return n == 0; }
    int size(){ return this->n; }
    
    
};
CWinApp theApp;

using namespace std;
int start();
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			listing141();
			//start();
			_exit(0);

		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
int start(){
	using namespace std;
try{
	stringstream ss22;
	ofstream out;
	out.open("I:\\test\\1m-ints.txt");
	if(!out.is_open()){
		cout << "open failed" << endl;
		return 1;
	}
	srand (time(NULL));
	for(int i = 0; i < 1000000; i++){
		int number = rand();
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