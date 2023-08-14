#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[54][54];

vector<pair<int, int>> homeVec;
vector<pair<int, int>> chickenVec;
vector<int> newChickenVec;
int result = 1000000004;



void Input()
{
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
                homeVec.push_back({i, j});
            else if (arr[i][j] == 2)
                chickenVec.push_back({i, j});
        }
    }
}


int GetDistance(pair<int, int> a, pair<int, int>b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void GetChickenDistance(vector<int> b)
{
    int newResult = 0;

    for(auto home : homeVec)
    {
        int chickenDistance = 2504; 

        for (int idx : b)
        {
            pair<int, int> chicken = chickenVec[idx];
            chickenDistance = min(chickenDistance, GetDistance(home, chicken));
        }

        newResult += chickenDistance;
    }

    result = min(result, newResult);
}

void Combination(int start, vector<int> b)
{
    if (b.size() == M)
    {
        GetChickenDistance(b);
        return;
    }
    
    for(int i=start+1; i<chickenVec.size(); i++)
    {
        b.push_back(i);
        Combination(i, b);
        b.pop_back();
    }

    return;
}

void Solve()
{
    do
    {
        // 치킨집 개수중에 M개를 고르기 
        Combination(-1, newChickenVec);
    }while(M--);

    cout << result << '\n';
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}