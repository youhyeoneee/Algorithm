#include <iostream>

using namespace std;

int TC, N, M;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> TC;

    for (int i=1; i<=TC; i++){
        cin >> N >> M;
        //  (1 ≤ N ≤ 30 , 0 ≤ M ≤ 10^8)

        bool fail = false;
        // M 을 2진수로 변환 
         // N개의 비트가 모두 1로 켜져있는지 체크
        for (int j = N-1; j >= 0; j--) 
            if (!(M >> j & 1)) {     
                cout << "#" << i << " OFF" << '\n';
                fail = true;
                break; 
            }
        
        if (!fail) cout << "#" << i << " ON" << '\n';
        

    }
    return 0;
}