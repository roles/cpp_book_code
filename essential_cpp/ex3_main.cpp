#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

template <typename IteratorType, typename elemType>
IteratorType
my_find(IteratorType first, IteratorType last, const elemType &value){
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


/**
 * 这两个函数都是function pointer
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
#endif

/**
 * @brief 利用泛型算法find_if来实现根据条件pred选取元素的filter
 *
 * @tparam InputIterator
 * @tparam OutputIterator
 * @tparam ElemType
 * @tparam Comp
 * @param first
 * @param last
 * @param at
 * @param val 二元运算中需要比较的值
 * @param pred 传入一个二元运算的function object
 *
 * @return 
 */
template <typename InputIterator, typename OutputIterator,
          typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
       OutputIterator at, const ElemType &val, Comp pred){
    while((first = find_if(first, last, bind2nd(pred, val))) != last){
        cout << "found value: " << *first << endl;
        *at++ = *first++;
    }
    return at;
}

/**
 * @brief  用function template改写sub_vec
 *         TODO 最后没有将元素erase，只是通过改变其返回iterator的位置
 *
 * @tparam InputIterator
 * @tparam OutputIterator
 * @tparam ElemType
 * @tparam Comp
 * @param first
 * @param last
 * @param at
 * @param val
 * @param pred
 *
 * @return 
 */
template <typename InputIterator, typename OutputIterator,
          typename ElemType, typename Comp>
OutputIterator
sub_seq(InputIterator first, InputIterator last, 
        OutputIterator at, const ElemType &val, Comp pred){
    OutputIterator at_end = at;
    for(InputIterator iter = first; iter != last; iter++, at_end++)
        *at_end = *iter;
    sort(at, at_end, not2(pred));
    OutputIterator iter = find_if(at, at_end, bind2nd(pred, val));
    return iter;
}

int main(){
    const int asize = 8;
    int ia[asize] = {1, 2, 7, 6, 13, 4, 21, 17};
    int *pi;
    vector<int> ret(asize);

    /*
    pi = my_find(ia, ia + asize, 13);
    if(pi != ia + asize){
        cout << *pi << endl;
    }else{
        cout << "not found" << endl;
    }
    */

    //filter(ia, ia + asize, ret.begin(), 10, less<int>());
    vector<int>::iterator iter = sub_seq(ia, ia + asize, ret.begin(), 10, less<int>());
    
    for(; iter != ret.end(); iter++)
        cout << *iter << endl;

    return 0;
}
