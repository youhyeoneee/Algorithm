#include <iostream>

// 1학년

using namespace std;

int arr[100];
unsigned long long dt[100][21];
int N;
int answer;

unsigned long long func(int depth, int sum){
    if (sum > 20 || sum < 0) return 0;
    if (dt[depth][sum] != 0) return dt[depth][sum];

    if (depth == N-1){
        if(sum == answer)
            return dt[depth][sum] = 1;
        return dt[depth][sum] = 0;
    }
    else{
        return dt[depth][sum] = func(depth + 1, sum + arr[depth]) + func(depth+1, sum - arr[depth]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(i==N-1) answer = num;
        else arr[i] = num;

        
    }

    cout << func(1, arr[0]);

    return 0;
}   

