#include <iostream>

using namespace std;

int main(){

    int C, N, sum, cnt;
    cin >> C;

    for(int i=0; i<C; i++){
        // 초기화
        int arr[1001] = {0, };
        sum = 0;

        cin >> N;
        
        // 평균 계산
        for(int j=0; j<N; j++){
            cin >> arr[j];
            sum += arr[j];
        }
        
        double average = sum/N;

        cnt = 0;
        // 한 줄씩 평균을 넘는 학생들의 비율 계산
        for(int j=0; j<N; j++)
            if (arr[j] > average) cnt++;

        printf("%.3f%%\n", (double)cnt/(double)N*100);

    }

    return 0;
}