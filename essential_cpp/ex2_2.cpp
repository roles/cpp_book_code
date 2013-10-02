#include<iostream>
#include<vector>

using namespace std;

bool pent_seq(int size, vector<int>& vec){
    
    static vector<int> local_seq;
    const int max_size = 1024;
    
    if(size <= 0 || size > max_size){
        cerr << "invalid size" << endl;
        return false;
    }
    
    for(int i = local_seq.size(); i < size; i++)
        local_seq.push_back(i * (3*i - 1) / 2);
    
    for(int i = 0; i < size; i++)
        vec[i] = local_seq[i];

    return true;
}

bool print_seq(const vector<int> &vec){
    if(vec.size() <= 0){
        cerr << "empty vector" << endl;
        return false;
    }
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
    return true;
}


int main(){
    vector<int> vec(10); 
    pent_seq(10, vec);
    print_seq(vec);
    return 0;
}
