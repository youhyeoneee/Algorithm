#include <iostream>

// 에라토스테네스의 체

using namespace std;

int N, K;
bool arr[1001] = {false};
int main(){

    cin >> N >> K;


    int cnt = 0;

    
    // 2부터 N까지 모든 정수를 적는다.
    // 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
    // P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
    // 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.
    for (int i=2; i<=N; i++){
        for(int j=i; j<=N; j+=i){
            if (arr[j] == false) {
                arr[j] = true;
                if(++cnt == K) {
                    cout << j << '\n'; 
                    return 0;
                }
            }

        }
    }


    return 0;
}