#include <iostream>

using namespace std;

int N, K;
int arr[100001];

// 이 문제의 최솟값 : -100 * 10만 = -1000만 (넉넉히 버퍼 더해주기)
int temp;
int ret = -10000004; 
int psum[100001];

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
}   

void Solve()
{
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;

    for(int i=0; i<K; i++)
    {
        sum += arr[i];
    }

    int max = sum;


    for(int i=1; i<=N-K; i++)
    {
        sum -= arr[i-1];
        sum += arr[i+K-1];    
        
        if (sum > max) max = sum;
    }
    cout << max;
}


void Solve2()
{
    // 누적합
    for(int i=1; i<=N; i++)
    {
        cin >> temp; 
        psum[i] = psum[i-1] + temp;
    }

    for(int i=K; i<=N; i++)
    {
        ret = max(ret, psum[i] - psum[i-K]);
    }

    cout << ret;
}

int main()
{   

    Input();
    Solve2();

    return 0;
}