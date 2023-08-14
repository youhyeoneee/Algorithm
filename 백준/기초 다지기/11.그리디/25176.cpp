#include <iostream>
#include <algorithm>
#include <vector>

// 브론즈1

using namespace std;

int main(){

    int N, result = 0;

    cin >> N;

    vector <int> v;
    for (int i=1; i<=N; i++){
        v.push_back(i);
    }

    sort(v.begin(), v.end());

    do {
        result++;
            // for (auto it = v.begin(); it != v.end(); ++it)
            //     cout << *it << ' ';
            // cout << endl;
    } while(next_permutation(v.begin(), v.end()));

    cout << result << '\n';
    return 0;   
} 