#include <iostream>

using namespace std;

// 골드바흐의 추측

bool arr[1000001] = {false};

void Sieve(){
    for (int i=2; i<=1000000; i++){
        if (arr[i] == false){
            for(int j=i*2; j<=1000000; j+=i)
                arr[j] = true;
        }   
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, b, a;

    arr[0] = true;
    arr[1] = true;
    

    Sieve(); // 에라토스테네스의 체 

    while(true){
        cin >> N;

        // 입력의 마지막 줄에는 0이 하나 주어진다.
        if (N==0) break;
                
        for(int i=N; i>=2; i--){
            if (arr[i] == false){
                b = i;
                a = N-b;
                if (arr[a] == false) { cout << N << " = " << a << " + " << b << '\n'; break;}
            }
        }
    }

    return 0;
}