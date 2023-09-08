#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<pair<int, int>> meetingVec; // 회의 리스트 ( 끝 ~ 시작)

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void Input()
{
    cin >> N;

    int startTime, endTime;

    for(int i=0; i<N; i++)
    {
        cin >> startTime >> endTime;

        meetingVec.push_back({endTime, startTime});
    }

}

void Solve()
{   
    // 끝 순서 오름차순으로 정렬
    sort(meetingVec.begin(), meetingVec.end());

    int endTime = meetingVec[0].first;
    int startTime = meetingVec[0].second;
    int result = 1;

    if (N > 1)
    {
        for(int i=1; i<N; i++)
        {
            int nextEndTime = meetingVec[i].first;
            int nextStartTime = meetingVec[i].second;

            // 다음 회의 시작 시간이 끝나는 시간보다 작은 경우 = 겹치는 경우 Pass 
            if (nextStartTime < endTime) continue;

            startTime = nextStartTime;
            endTime = nextEndTime;
            result++;
        }
    }


    cout << result;

}

int main()
{
    FastIO();
    Input();
    Solve();
}