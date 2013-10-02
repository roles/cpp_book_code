#include<iostream>
#include<string>
#include<vector>

using namespace std;

#if 0
TODO
当写成如下方式的时候会各种报警告
elemType max(const elemType &a, const elemType &b){
#endif
template <typename elemType>
elemType max(const elemType a, const elemType b){
    if(a > b)
        return a;
    else
        return b;
}

template <typename elemType>
elemType max(const vector<elemType> &vec){
    if(vec.size == 0){
        cerr << "empty vector" << endl;
        return (elemType)0;
    }
    elemType tmax = vec[0];
    for(int i = 0; i < vec.size(); i++){
        tmax = max(tmax, vec[i]);
    }
    return tmax;
}

template <typename elemType>
elemType max(const elemType *arr, int size){
    if(size == 0){
        cerr << "empty vector" << endl;
        return (elemType)0;
    }
    elemType tmax = arr[0];
    for(int i = 0; i < size; i++){
        tmax = max(tmax, arr[i]);
    }
    return tmax;
}

int main(){
    cout << max(1, 5) << endl;
    cout << max(1.231, 1.32) << endl;
    cout << max(string("Tom"), string("Tim")) << endl;

    int iarr[] = {1, 3, 2, 5};
    double darr[] = {1.4, 1.3, 2.2, 1.5};
    string sarr[] = {string("Tom"), string("Tim"), string("Lucy")};

    vector<int> ivec(iarr, iarr + 4);
    vector<double> dvec(darr, darr + 4);
    vector<string> svec(sarr, sarr + 3);

    cout << max(ivec) << endl;
    cout << max(dvec) << endl;
    cout << max(svec) << endl;

    cout << max(iarr, 4) << endl;
    cout << max(darr, 4) << endl;
    cout << max(sarr, 3) << endl;

    return 0;
}  
