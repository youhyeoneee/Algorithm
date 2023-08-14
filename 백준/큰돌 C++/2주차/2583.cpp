#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 101;

bool map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int N, M, K;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void Fill(int x1, int y1, int x2, int y2)
{
    for(int i=y1; i<y2; i++)
    {
        for(int j=x1; j<x2; j++)
            map[i][j] = true;
    }
}

void Print()
{
    cout << "===============\n";
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
            cout << map[i][j] << " ";
        cout << '\n';
    }
    cout << "===============\n";

}

void Input()
{
    cin >> M >> N >> K;

    for (int i=0; i<K; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Fill(x1, y1, x2, y2);
        // Print();
    }
}

int Dfs(int y, int x)
{
    visited[y][x] = true;
    int area = 1;
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[ny][nx] || visited[ny][nx])
            continue;
        
        area += Dfs(ny, nx);
    }

    return area;
}
void Solve()
{
    vector<int> areaVec;

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if (!map[i][j] && !visited[i][j])
            {
                areaVec.push_back(Dfs(i, j));
            }
        }
    }

    cout << areaVec.size() << '\n';
    sort(areaVec.begin(), areaVec.end());

    for(int area : areaVec)
    {
        cout << area << " ";
    }


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