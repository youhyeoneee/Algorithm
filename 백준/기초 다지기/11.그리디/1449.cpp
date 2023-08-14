#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 실버 3

int main(){

    int N, L;
    

    cin >> N >> L;

    vector<double> v(N);

    for(int i=0; i<N; i++)
        cin >> v[i];

    sort(v.begin(), v.end()); // 오름차순

    int cnt = 1;
    
    double start = v[0]-0.5;

    for (int i=1; i<v.size(); i++){
        if(start+L >= v[i]+0.5){ 
            continue;
        }
        else{
            start = v[i]-0.5;
            cnt++;
        }
            
    }

    cout << cnt << '\n';

    return 0;
}