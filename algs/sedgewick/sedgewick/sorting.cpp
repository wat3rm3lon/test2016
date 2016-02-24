#include "stdafx.h"

void swap2(std::vector<int>& a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

class sorting{
public:
    //swap
    void exch(std::vector<int>& a, int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    bool less(int i, int j){
        return i > j;
    }
    void sort_selection(std::vector<int>& a){
        int n = a.size();
        for(int i = 0; i < n - 1; i++){
            int pos_min = i;
            for(int j = i + 1; j < n; j++){
                if(a[j] < a[pos_min]){
                    pos_min = j;
                }
            }
            int temp = a[i];
            a[i] = a[pos_min];
            a[pos_min] = temp;
        }
    }
    void sort_insertion(std::vector<int>& a){
        int n = a.size();
        for(int i = 1; i < n; i++){
            for(int j = i; j > 0 && a[j] > a[j - 1]; j--){
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
    void sort_shell(std::vector<int>& a){
        int n = a.size();
        int h = 1;
        while(h < n / 3){
            h = 3 * h + 1;
        }
        cout << "shell. h = " << h << endl;
        while(h >= 1){
            for(int i = h; i < n; i++){
                for(int j = i; j >= h && a[j] < a[j - h]; j -= h){
                    int temp = a[j];
                    a[j] = a[j - h];
                    a[j - h] = temp;
                }
            }
            h = h / 3;
        }
    }
    void show(std::vector<int>& a){
        for(UINT i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
//page 254
class merge_sorting{
    vector<int> aux;
    int sort_count;
    int merge_count;
public:
    merge_sorting() : aux(), sort_count(0), merge_count(0) {}
    void merge(std::vector<int>& a, int low, int mid, int high){
        merge_count++;
        int i = low;
        int j = mid + 1;
        for(int k = low; k <= high; k++){
            aux[k] = a[k];
        }
        for(int k = low; k <= high; k++){
            if(i > mid){
                a[k] = aux[j++];
            }else if(j > high){
                a[k] = aux[i++];
            }else if(aux[j] > aux[i]){
                a[k] = aux[j++];
            }else{
                a[k] = aux[i++];
            }
        }
    }
    void sort(std::vector<int>& a){
        aux = a;
        //reserve assert crash in debug only!!!
        //aux.reserve(a.size());
        sort(a, 0, a.size() - 1);
    }
    void sort(std::vector<int>& a, int low, int high){
        sort_count++;
        if(high <= low)
            return;
        int mid = low + (high - low) / 2;
        sort(a, low, mid);
        sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
    void show(std::vector<int>& a){
        cout << "sort invoke count " << this->sort_count << endl;
        cout << "merge invoke count " << this->merge_count << endl;
        cout << "vector size " << a.size() << endl;
        for(unsigned int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
    }
    //260
    void sort_bu(std::vector<int>& a){
        int n = a.size();
        aux = a;
        for(int size = 1; size < n; size = size + size){
            for(int low = 0; low < n - size; low += size + size){
                merge(a, low, low + size - 1, min(low + size + size - 1, n - 1));
            }

        }
    }
};
//271
class quick_sorting{
public:
    int partition(std::vector<int>& a, int low, int high){
        int i = low;
        int j = high + 1;
        int v = a[low];
        while(TRUE){
            while(a[++i] < v) if(i == high) break;

            while(v < a[--j]) if(j == low) break;

            if(i >= j) break;

            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            /*
            while(a[++i] < v){
                if(i == high)
                    break;
            }
            while(v < a[--j]){
                if(j == low)
                    break;
            }
            if(i >= j)
                break;
                
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            */
        }
        int tmp2 = a[low];
        a[low] = a[j];
        a[j] = tmp2;
        return j;
    }
    void sort(std::vector<int>& a, int low, int high){
        if(high <= low){
            return;
        }
        int j = partition(a, low, high);
        sort(a, low, j - 1);
        sort(a, j + 1, high);
    }
    void sort(std::vector<int>& a){
        sort(a, 0, a.size() - 1);
    }
    void show(std::vector<int>& a){
        for(unsigned int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
    }
};
class quick3way_sorting{
public:
    void sort(std::vector<int>& a, int low, int high){
        if(high <= low) 
            return;
        int lt = low;
        int i = low + 1;
        int gt = high;
        int v = a[low];
        while(i <= gt){
            if(a[i] < v) swap2(a, lt++, i++);
            else if(a[i] > v) swap2(a, i, gt--);
            else i++;
            //int cmp = a[i]  v
        }
        sort(a, low, lt - 1);
        sort(a, gt + 1, high);
    }
};
//295
class MaxPQ{
    vector<int> pq;
    int n;
public:
    MaxPQ(int maxN){ pq.reserve(maxN); n = 0; }
    bool isEmpty() { return pq.size() == 0; }
    int size(){ return n; }
    /*
    void insert(int v){
        pq.insert()
    }
    */
    //293
    void swim(int k){
        while((k > 1) && (k/2 < k)){
            swap2(this->pq, k / 2, k);
            k = k / 2;
        }
    }
    void sink(int k){
        while(2 * k <= n){
            int j = 2 * k;
            if((j < n) && (j < j + 1)) j++;
            if(k > j) break;
            swap2(this->pq, k, j);
            k = j;
        }
    }
    void insert(int v){
        pq[++n] = v;
        swim(n);
    }
    int delmax(){
        int max = pq[1];
        swap2(this->pq, 1, this->n--);
        this->pq[n + 1] = 0;
        sink(1);
        return max;
    }
    void show(){
        cout << "size = " << this->n << endl;
        for(UINT i = 0; i < this->pq.size(); i++){
            cout << this->pq[i] << " ";
        }
    }
};
void listing214(){
    std::vector<int> vints;
    std::string file_path("..\\..\\..\\files\\100-bytes.txt");
    read_file(vints, file_path);
    sorting sel;
    sel.show(vints);
    cout << " pe pew" << endl;
    //sel.sort_selection(vints);
    //sel.sort_insertion(vints);
    sel.sort_shell(vints);
    sel.show(vints);
    cin.get();
    _exit(0);
}
void listing254(){
    std::vector<int> vints;
    std::string file_path("..\\..\\..\\files\\100-bytes.txt");
    read_file(vints, file_path);
    merge_sorting merge;
    //merge.sort(vints);
    merge.sort_bu(vints);
    merge.show(vints);
    cin.get();
}
//270
void listing231(){
    std::vector<int> vints;
    std::string file_path("..\\..\\..\\files\\100-bytes.txt");
    read_file(vints, file_path);
    quick_sorting qs;
    qs.show(vints);
    cout << endl << "starting sorting" << endl;
    qs.sort(vints);
    qs.show(vints);
    cin.get();
}