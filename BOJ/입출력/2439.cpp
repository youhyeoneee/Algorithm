#include <iostream>

using namespace std;

int main(){

    int N;

    cin >> N;

    for (int i=1; i<=N; i++){

        // 공백 출력
        for(int j=N-i; j>0; j--) // j=0; j<N-i; k++
            cout << ' ';
        // 별 출력 
        for(int k=1; k<=i; k++)  //k=0; k<i; k++
            cout << '*';
        
        cout << '\n';
        
    }
    return 0;
}