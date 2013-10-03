#include<iostream>
#include<string>
#include<map>
#include<set>
#include<iterator>
#include<fstream>
#include<algorithm>
#include<cctype>

using namespace std;

int main(){
    map<string, int> words;
    ifstream is("ex3_1.in");
    string word;
    map<string, int>::iterator iter;
    char excluded_words[][5] = {"is", "an", "a", "as", "the", "but", "in", "are", "with", "at"};
    const int excluded_words_size = 10;
    set<string> excluded_words_set;

    excluded_words_set.insert(excluded_words, excluded_words + excluded_words_size);
    while(is >> word){
        transform(word.begin(), word.end(), word.begin(), (int(*)(int))tolower);
        if(excluded_words_set.count(word))
            continue;
        if((iter = words.find(word)) != words.end()){
            words[word]++;
        }else{
            words[word] = 1;
        }
    }
    for(iter = words.begin(); iter != words.end(); iter++)
        cout << iter->first << ":\t" << iter->second << endl;
    return 0;
}
