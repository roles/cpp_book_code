#include<iostream>
#include<vector>

using namespace std;

template <typename IteratorType, typename elemType>
IteratorType
find(IteratorType first, IteratorType last, const elemType &value){
    for(; first != last; first++){
        if(value == *first)
            return first;
    }
    return last;
}

#if 0

找到一个vector中小于10的元素放到另一个vector返回

vector<int> less_than_10(const vector<int> &vec){
    vector<int> nvec;
    for(int i = 0; i < vec.size(); i++)
        if(vec[i] < 10)
            nvec.push_back(vec[i]);
    return nvec;
}

vector<int> less_than(const vector<int> &vec, int less_than_val){
    vector<int> nvec;
    for(int i = 0; i < vec.size(); i++)
        if(vec[i] < less_than_val)
            nvec.push_back(vec[i]);
    return nvec;
}

#endif


/**
 * 这两个函数都是function object
 */
bool less_than(int a, int b){
    return (a < b ? true : false);
}

bool greater_than(int a, int b){
    return (a > b ? true : false);
}

/*
** 将比较操作参数话，支持除小于之外的其他比较
*/
vector<int> filter(const vector<int> &vec, int filter_val, bool (*pred)(int, int)){
    vector<int> nvec;
    for(int i = 0; i < vec.size(); i++)
        if(pred(vec[i], filter_val))
            nvec.push_back(vec[i]);
    return nvec;
}

int main(){
    const int asize = 8;
    int ia[asize] = {1, 2, 7, 6, 13, 4, 21, 17};
    int *pi;

    pi = find(ia, ia + asize, 13);
    if(pi != ia + asize){
        cout << *pi << endl;
    }else{
        cout << "not found" << endl;
    }

    return 0;
}
