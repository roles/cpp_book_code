#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void string_implement(){
    string user_name; 
    cin >> user_name;
    while(user_name.size() < 2){
        cout << "invalid user name" << endl;
        cin >> user_name;
    }
    cout << "Your name is " << user_name << endl;
}

void cstyle_implement(){
    const int max_char_len = 100;
    char user_name[max_char_len];
    cin >> user_name;
    while(strlen(user_name) < 2){
        cout << "invalid user name" << endl;
        cin >> user_name;
    }
    cout << "Your name is " << user_name << endl;
}

int main(){
    cstyle_implement();
    return 0;
}
