#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
double score;

priority_queue<double, vector<double>, greater<double>> pq;

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Input()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> score;
        pq.push(score);
    }
}

void Solve()
{
    int idx = 7;
    while(idx-- > 0)
    {
        cout << fixed;
        cout.precision(3);
        cout << pq.top() << "\n";
        pq.pop();
    }
}

int main()
{
    FastIO();
    Input();
    Solve();

    return 0;
}