#include <iostream>
#include <string>

using namespace std;

int main(){

    string A, B;
    int temp;
    bool one = false;
    cin >> A >> B;

    int arr[10001];

    int min_size = (A.length() > B.length())? B.length() : A.length(); // 더 작은 사이즈
    int max_size = (A.length() > B.length())? A.length() : B.length(); // 더 큰 사이즈
    int size = max_size;

    for(int a=A.length()-1, b=B.length()-1; min_size>0; min_size--){
        temp = (A[a]-'0') + (B[b]-'0'); // 합
        if (one) {temp++; one = false;} // 10넘으면 1올려줌
        if (temp >= 10) {arr[size] = temp%10; one = true;}
        else arr[size] = temp;
        a--; b--; size--;
    }

    if (size > 0) {
        string Big = (A.length() > B.length())? A : B; 

        for(; size>0; size--){
            temp = Big[size-1] - '0';
            if (one) {temp++; one = false;} // 10넘으면 1올려줌
            if (temp >= 10) {arr[size] = temp%10; one = true;}
            else arr[size] = temp;
        }
        
    }

    int start = 1;

    if(one) { arr[0] = 1; start = 0;}   // 마지막에 10 넘으면 자릿수++

    for(; start<=max_size; start++)
        cout << arr[start];


    return 0;
}