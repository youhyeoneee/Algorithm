#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

int N, C;

int arr[1001];

// 숫자, 빈도, 들어온 횟수
vector<tuple<int, int, int>> vec;


vector<pair<int, int>> vec2;
map<int, int> m, mOrder;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b)
{
    if (get<1>(a) < get<1>(b))
        return false;
    else if (get<1>(a) == get<1>(b))
        return get<2>(a) < get<2>(b);
    return true;
}

bool compare2(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return mOrder[a.first] < mOrder[b.first];

    return a.second > b.second;
}


void Input()
{
    cin >> N >> C;
    
    int temp;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
}

void Solve()
{
    // 1. 개수 세기
    
    for(int i=0; i<N; i++)
    {
        bool find = false;

        for(int j=0; j<vec.size(); j++)
        {
            if (get<0>(vec[j]) == arr[i])
            {
                get<1>(vec[j])++;
                find = true;
                break;  
            }              
        }

        if (!find)
        {
            vec.push_back({arr[i], 1, i});
        }
    }


    // 2. 정렬 하기
    sort(vec.begin(), vec.end(), compare);

    for (auto i : vec)
    {
        int num = get<0>(i);
        for(int j=0; j<get<1>(i); j++)
            cout << num << ' ';
    }

}

void Solve2()
{
    // 1. 개수 세기
    
    for(int i=0; i<N; i++)
    {
        m[arr[i]]++;
        if (mOrder[arr[i]] == 0) mOrder[arr[i]] = i + 1;
    }

    for(auto i : m)
    {
        vec2.push_back({i.first, i.second});
    }

    sort(vec2.begin(), vec2.end(), compare2);

    for (auto i : vec2)
    {
        int num = i.first;
        for(int j=0; j<i.second; j++)
            cout << num << ' ';
    }


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    // Solve();
    Solve2();

    return 0;
}