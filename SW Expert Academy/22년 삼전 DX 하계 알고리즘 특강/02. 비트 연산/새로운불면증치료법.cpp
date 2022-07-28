#include <iostream>

using namespace std;

int T, N, result; // (1 ≤ N ≤ 10^6)

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin >> T;

    for(int i=1; i<=T; i++){
        cin >> N;
        bool arr[10] = {0, };
        for(result=N; ; result+=N){
            int num = result;
            bool fail = false;
            do{
                arr[num%10] = 1;
                num/=10;
            }while(num > 0);
            
            for (int j=0; j<10; j++){
                if (!arr[j]) {fail = true; break;}
            }

            if (fail) continue;
            else goto label;
        }
label:
        cout << '#' << i << ' ' << result << '\n';
    }

    return 0;
}