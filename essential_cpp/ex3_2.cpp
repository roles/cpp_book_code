#include<iostream>
#include<string>
#include<map>
#include<set>
#include<iterator>
#include<fstream>
#include<algorithm>
#include<cctype>
#include<vector>

using namespace std;

class StrComp{
    public:
    bool operator()(const string &a, const string &b) const{
        return (a.size() < b.size() ? true : false);
    }
};

int main(){
    map<string, int> words;
    ifstream is("ex3_1.in");
    string word;
    map<string, int>::iterator iter;
    char excluded_words[][5] = {"is", "an", "a", "as", "the", "but", "in", "are", "with", "at"};
    const int excluded_words_size = 10;
    set<string> excluded_words_set;
    vector<string> word_vec;

    excluded_words_set.insert(excluded_words, excluded_words + excluded_words_size);
    while(is >> word){
        transform(word.begin(), word.end(), word.begin(), (int(*)(int))tolower);
        if(excluded_words_set.count(word))
            continue;
        word_vec.push_back(word);
    }
    sort(word_vec.begin(), word_vec.end(), StrComp());
    for(vector<string>::iterator iter = word_vec.begin(); iter != word_vec.end(); iter++)
        cout << *iter << endl;
    return 0;
}
