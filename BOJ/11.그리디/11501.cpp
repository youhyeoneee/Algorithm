#include <algorithm>
#include <vector>
#include <iostream>

// 실버 2

using namespace std;

// - 잘못된 접근: 주가가 떨어지는 시점에 기존 구입했던 주식 판매 (Greedy)

// - 올바른 접근: 주가가 떨어지는 시점이 아니라, 현재 주가를 현재일 이후에 가장 비싸게 팔 수 있는 날에 판매

int main(){

    int T, N, input;

    vector<int> v;

    cin >> T;

    for (int i=0; i<T; i++){
        cin >> N;

        v.push_back(1000000);

        for (int j=0; j<N; j++){
            cin >> input;
            v.push_back(input);
        }

        int max = N;
        long long result = 0;
        for (int j=N-1; j>=0; j--){
            if (v[max] < v[j]){ // 팔아야 할 시점 
                for (int k=j+1; k<max; k++)
                    result += v[max] - v[k]; 
                
                max = j;
            }
        }


        cout << result << '\n';
        v.clear();
    }


    return 0;
}