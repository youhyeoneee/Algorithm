#include <iostream>

// 캔디 분배 

using namespace std;
long long x1 = 1, y1 = 0, x2 = 0, y2 = 1;

long long gcd(long long a, long long b){
    if (b==0) return a;

    if (b != 1){ // 확장 유클리드 호제법
        long long x, y;
        x = x1 - ((a/b)*x2);
        y = y1 - ((a/b)*y2);     
        x1 = x2; y1 = y2;
        x2 = x; y2 = y;
    }

    return gcd(b, a%b);
}


int main(){

    long long t, K, C;

    cin >> t;
    
    for(long long i=0; i<t; i++){
        cin >> K >> C;


        if (C == 1){
            if (K >= 1000000000)  cout << "IMPOSSIBLE\n";
            else cout << K+1 << '\n';
        }
        else if(K == 1) cout << "1\n";
        else if (gcd(K, C) != 1) cout << "IMPOSSIBLE\n";
        else{
            x1 = 1; y1 = 0; x2 = 0; y2 = 1; // 초기화

            gcd(K, C);
            
            while(y2 < 0) {y2 = y2 + K;} // 음수일 경우 K를 계속 더해준다.

            
            if (y2 > 1000000000 || y2 == 0) cout << "IMPOSSIBLE\n";
            else cout << y2 << '\n';
        }
    }


    return 0;
}