#include "stdafx.h"
#include "functions.h"

class threeSum{
public:
	int count(vector<int>& a){
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

void listing141(){
try{
	ifstream in;
	//I:\\test\\1m-ints.txt
	//in.open("I:\\test\\1k-ints.txt", ios::ate); // 13
	//in.open("I:\\test\\2k-ints.txt", ios::ate); // 105
	in.open("I:\\test\\4k-ints.txt", ios::ate); // 833
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