#include<iostream>
#include<vector>

using namespace std;

inline bool check_size(int size){
    const int max_size = 1024;
    return !(size <= 0 || size > max_size);
}

const vector<int>* pent_seq(int size){
    
    static vector<int> local_seq;
    
    if(!check_size(size)){
        cerr << "invalid size" << endl;
        return 0;
    }
    
    for(int i = local_seq.size(); i < size; i++)
        local_seq.push_back(i * (3*i - 1) / 2);
    
    return &local_seq;
}

bool pent_elem(int pos, int &elem){

    if(!check_size(pos)){
        cout << pos << endl;
        cerr << "invalid pos" << endl;
        return false;
    }
    const vector<int> *pseq = pent_seq(pos);
    if(!pseq){
        cerr << "no seq" << endl;
        return false;
    }
    elem = (*pseq)[pos - 1]; 
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
    int elem;
    pent_elem(10, elem);
    cout << elem << endl;
    return 0;
}
