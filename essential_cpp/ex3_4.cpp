#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

class OddPred{
    public:
        bool operator()(const int &a) const{
            return (a % 2 == 0 ? false : true);
        }   
};

class EvenPred{
    public:
        bool operator()(const int &a) const{
            return (a % 2 != 0 ? false : true);
        }   
};

template <typename InputIterator, typename OutputIterator, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
       OutputIterator at, Comp pred){
    while((first = find_if(first, last, pred)) != last){
        *at++ = *first++;
    }
    return at;
}

int main(){
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    ofstream odd_outfile("ex3_4.odd");
    ofstream even_outfile("ex3_4.even");
    ostream_iterator<int> odd_os(odd_outfile, " ");
    ostream_iterator<int> even_os(even_outfile, "\n");
    vector<int> ivec, odd_vec, even_vec;
    copy(is, eof, back_inserter(ivec));
    filter(ivec.begin(), ivec.end(), back_inserter(odd_vec), OddPred());
    //TODO 这样为什么不行
    //filter(is, eof, back_inserter(even_vec), not1(OddPred()));
    
    filter(ivec.begin(), ivec.end(), back_inserter(even_vec), EvenPred());
    copy(odd_vec.begin(), odd_vec.end(), odd_os);
    copy(even_vec.begin(), even_vec.end(), even_os);
    
    return 0;
}
