#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

ll solve(int N, int M, vector<int> lectures) {
    

    // 블루레이 크기 이분탐색으로 구하기
    // left = 강의 길이 중 최소? 
    ll left = *max_element(lectures.begin(), lectures.end());
    // right = 모든 강의길이 합
    ll right = 0;
    for(int i : lectures) {
        right += i;
    }

    ll answer = right;
    // cout << left << " ~ " << right << "\n";
    while(left <= right) {
        ll mid = (left + right) / 2;

        // check 
        // 강의 돌면서 더하기 
        ll blue_ray_count = 1;
        ll sum = 0;
        for(int i : lectures) {
            
            // 초과되면 개수 +1
            if (sum+i > mid) {
                sum = 0;
                blue_ray_count++;
            }

            sum += i;

            if (blue_ray_count > M) 
                break;
        }
        
            // cout << mid << " : " << blue_ray_count << "/" << M << "\n";

        if (blue_ray_count > M) {
            left = mid + 1;
        } else {
            answer = min(answer, mid);
            right = mid - 1;
        }
    }
    
    return answer;
}

int main() {

    int N, M;
    vector<int> lectures;

    // input
    cin >> N >> M;

    int lecture;
    for(int i=0; i<N; i++) {
        cin >> lecture;
        lectures.push_back(lecture);
    }

    // tc1
    // N = 100000;
    // M = 100000;

    // for(int i=1; i<=N; i++) {
    //     lectures.push_back(i);
    // }

    cout << solve(N, M, lectures);

    return 0;
}