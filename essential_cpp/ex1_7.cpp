#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int main(){

    ifstream infile("ex1_7.in");
    ofstream outfile("ex1_7.out");
    vector<string> word_list;
    string word;

    if(!infile)
        cout << "cannot open in file" << endl;
    if(!outfile)
        cout << "cannot open out file" << endl;
    while(infile >> word)
        word_list.push_back(word); 
    sort(word_list.begin(), word_list.end()); 
    for(vector<string>::iterator iter = word_list.begin(); iter != word_list.end(); iter++)
        outfile << *iter << endl;
    
    return 0;
}
