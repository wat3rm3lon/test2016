#pragma once


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

class binarySearch{
public: 
    int rank(int key, std::vector<int>& a){
        int low = 0;
        int high = a.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(key < a[mid]) high = mid - 1;
            else if(key > a[mid]) low = mid + 1;
            else return mid;
        }
        return -1;
    }
};
class threeSum{
public:
    int count(vector<int> a){
        int n = a.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + i; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(a[i] + a[j] + a[k] == 0)
                        count++;
                }
            }
        }
        return count;	
    }
};
class twoSumFast{
public:
    int count(std::vector<int> a){
        binarySearch bs;
        std::sort(a.begin(), a.end());
        int n = a.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(bs.rank(-a[i], a) > 1)
                count++;
        }
        return count;
    }
};
class threeSumfast{
public:
    int count(std::vector<int> a){
        std::sort(a.begin(), a.end());
        binarySearch bs;
        int n = a.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(bs.rank(-a[i] - a[j], a) > j){
                    count++;
                }
            }
        }
        return count;
    }
};

class uf{
    std::vector<int> id;
    //int* pID;
    int count;
public:
    uf(int n){
        count = n;
        id.reserve(n);
        //pID = new int[n];
        for(int i = 0; i < n; i++){
            id.push_back(i);
        }
    }
    int count_(){
        return count;
    }
    int find(int p){
        return id[p];
    }
    void union_(int p, int q){
        int pid = find(p);
        int qid = find(q);
        if(pid == qid) return;

        for(UINT i = 0; i < id.size(); i++){
            if(id[i] == pid){
                id[i] = qid;
            }
            count--;
        }
    }
    bool connected(int p, int q){
        return find(p) == find(q); 
    }
};
bool read_file(std::vector<int>& vec, std::string file_path);
int start();
void listing114(); //page 60
void listing141();
void listing143(); //page 182
void listing144();
void listing151();
void listing231();