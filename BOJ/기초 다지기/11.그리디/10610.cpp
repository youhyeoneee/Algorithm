#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 실버 5

int main(){

    string N, result;
    cin >> N;

    vector<int> v;

    for(int i=0; i<N.size(); i++){
        v.push_back(N[i] - '0');
    }

    // 1. 0이 있는가
    auto zero = find(v.begin(), v.end(), 0);
    if (zero == v.end()) // 없으면
        result = "-1";
    else { // 있으면
        // 2. 3으로 나눠지는가
        int sum = 0;
        for(int i=0; i<N.size(); i++)
            sum+=v[i];

        if (sum%3 != 0) // 안나눠짐
            result = "-1";
        else{ // 나눠짐
            v.erase(zero); // 0제거
            result = "0";
            sort(v.begin(), v.end());
            for(int i=0; i<v.size(); i++)
                result += v[i] + '0';
        }

    }


    if (result != "-1")
        reverse(result.begin(),result.end());
    cout << result << '\n';
    return 0;
}