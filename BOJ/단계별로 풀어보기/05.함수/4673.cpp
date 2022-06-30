#include <iostream>
#include <string>
#define SIZE 10000
using namespace std;


int d(int n){

    int result = n;

    // 각 자리수 더하기
    for(char ch : to_string(n)){
        result += ch - '0';
    }

    return result;
}


int main(){
    int arr[SIZE+1] = {0, };

    for (int i=1; i<=SIZE; i++){
        int temp = i;
        while(temp<=SIZE){
            temp = d(temp);
            if (temp<=SIZE)
                arr[temp]++;
        }
    }

    for (int i=1; i<=SIZE; i++)
        if(arr[i] == 0) cout << i << '\n';

    return 0;
}