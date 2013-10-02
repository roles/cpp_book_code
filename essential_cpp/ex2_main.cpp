#include<iostream>
#include<vector>

using namespace std;

const vector<int>* fibon_seq(int size){

    //使用局部静态对象保存计算过的值
    const int max_size = 1024;
    static vector<int> elems;

    if(size < 0 || size > max_size){
        cerr << "invalid size " << size << endl;
        return 0;
    }
    for(int ix = elems.size(); ix < size; ix++)
        if(ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
    return &elems;
}

#if 0

最开始的定义
下面的实现利用函数指针做了进一步的抽象

bool fibon_elem(int pos, int &elem){
    const vector<int> *pseq = fibon_seq(pos);
    if(!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos - 1];
    return true;
}

#endif

bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int)){
    const vector<int> *pseq = seq_ptr(pos);
    if(!seq_ptr){
        cerr << "seq_ptr should not be null" << endl;
        return false;
    }
    if(!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos - 1];
    return true;
}
