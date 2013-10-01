#include<iostream>
#include<vector>

using namespace std;

int main(){
    const int max_len = 100;
    int arr_seq[max_len];
    vector<int> vec_seq(max_len);
    int i = 0;
    int data;
    int sum;
    int len;
    double avg;
    while(cin >> data){
        if(-1 == data)
            break;
        arr_seq[i] = data;
        vec_seq[i] = data;
        i++;
    }
    len = i; 
    for(i = 0, sum = 0, avg = 0.0; i < len; i++){
        sum += arr_seq[i]; 
    }
    avg = sum * 1.0 / len;

    printf("sum:%d\taverage:%lf\n", sum, avg);
    return 0;
}
