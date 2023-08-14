#include <iostream>

using namespace std;

// 실버 2
int arr[101][101];
int N, M;
int cnt = 0;

bool check(){
    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 1){
                return false;
            }
        }
    }

    return true;
}


int main(){


    cin >> N >> M;

    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            scanf("%1d", &arr[i][j]);
    }

    for(int i=N-1; i>=0; i--){
        for(int j=M-1; j>=0; j--){
            if (arr[i][j] == 1){ // 1만나면 axb만큼 뒤집기
                cnt++;
                for(int k=0; k<=i; k++){
                    for(int l=0; l<=j; l++){
                        arr[k][l] = (arr[k][l] == 0)? 1:0;
                    }
                }
            }

            if(check()){
                cout << cnt << '\n';
                return 0;
            }
        }
    }
    return 0;
}