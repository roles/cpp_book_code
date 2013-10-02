#include "NumSeq.h"

using namespace std;

bool fibon_elem(int pos, int &elem){
    return seq_elem(pos, elem, fibon_seq);
}

int main(){
    int pos;
    while(true){
        cout << "Please enter a pos:";
        if(!(cin >> pos))
            break;
        int elem;
        if(fibon_elem(pos, elem))
            cout << "element # " << pos
                 << " is " << elem << endl;
        else
            cout << "Sorry, error input";
    }
    return 0;
}


