#include <iostream>

// 실버 5

using namespace std;

int main(){
    int N, M, J, x;

    cin >> N >> M;
    
    cin >> J;

    int now_idx = 1,  result = 0; // 현재 위치, 바구니 이동거리 최솟값

    for (int i=0; i<J; i++){
        cin >> x; // 사과 떨어지는 위치

        if (now_idx <= x && x <= (now_idx+M-1)) // 현재 담을 수 있는 위치인가
            continue;
        else{
            // 왼쪽으로 가야하는가 
            if (x < now_idx){
                while(now_idx != x){
                    now_idx--;
                    result++;
                }
            }   
            else{ // 오른쪽으로 가야하는가
                while(now_idx+M-1 != x){
                    now_idx++;
                    result++;
                }
            } 
            
        }
        
    }

    cout << result << '\n';
    return 0;
}