#include <iostream>
#include <vector>

using namespace std;

int N;
int x, y;

vector<pair<int, int>> v;

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
        cin >> x >> y;
        v.push_back({x, y});
    }
}

void Solve()
{
    for(int i=0; i<N; i++)
    {
        int rank = 1;
        for(int j=0; j<N; j++)
        {
            if(v[i].first < v[j].first && v[i].second < v[j].second)
                rank++;
        }
        cout << rank << " ";
    }
}

int main()
{
    FastIO();
    Input();
    Solve();
}