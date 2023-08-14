#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, temp, result = 0;

    vector<int> v;

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    } 
    sort(v.begin(), v.end());


    temp = 0;
    for(int i=0; i<N; i++){
        temp += v[i];
        result += temp;
    }

    cout << result << '\n';

    return 0;
}