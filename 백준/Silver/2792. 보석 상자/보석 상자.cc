#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

vector<ll> v;
ll N;


bool check(ll jealousy) {
    // 모든 색상을 질투심으로 나눴을 때의 개수
    ll cnt = 0;
    for(ll color : v) {
        if (color % jealousy == 0)
            cnt += color / jealousy;
        else 
            cnt += (color / jealousy) + 1;
    }

    return N >= cnt;
}

int main() {

    // input
    int M;

    cin >> N >> M;


    ll cnt;
    for(int i=0; i<M; i++) {
        cin >> cnt;
        v.push_back(cnt);
    }

    // solve 
    ll left = 1, right = *max_element(v.begin(), v.end());
    ll mid;
    ll answer = 1e18;

    while(left <= right) {
        mid = (left + right) / 2;
        if (check(mid)) {
            answer = min(answer, mid); 
            right = mid - 1;
        } else
            left = mid + 1;
    } 
     

    cout << answer;

    return 0;
}