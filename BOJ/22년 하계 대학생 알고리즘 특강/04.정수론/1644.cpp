#include <iostream>
#include <vector>

// 소수의 연속합

using namespace std;

int N;

bool arr[4000001] = {false};
vector<int> prime;

 // 에라토스테네스의 체 
void Sieve(int N){
    for (int i=2; i<=N; i++){
        if (arr[i] == false){
            for(int j=i*2; j<=N; j+=i)
                arr[j] = true;
        }   
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N == 1) {cout << 0 << '\n'; return 0;}
    // 소수 구하기
    Sieve(N);

    for (int i=2; i<=N; i++){
        if(arr[i] == false) prime.push_back(i);
    }

    // 2-pointer
    int start = 0, end = 0, sum = 0, cnt = 0;
    // 최초 전부구간합
    sum = prime[0];

    while(start<prime.size() && end<prime.size()){
        
        if (sum > N) {
            if(start != prime.size()-1) sum -= prime[start++]; 
            else start++;
        }
        else if (sum < N) {
            if(end != prime.size()-1) sum +=prime[++end];
            else end++;
        }
        else { // 같을 경우
            cnt++; 
            if(start != prime.size()-1) sum -= prime[start++];
            else start++; // break
        }
    }

    cout << cnt << '\n';

    return 0;
}