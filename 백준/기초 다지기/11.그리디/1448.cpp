#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 실버3

bool compare(int a, int b) {
    return a > b;	
}

int main(){

    int N, result = -1;

    cin >> N;

    vector<int> v(N);
    for (int i=0; i<N; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end(), compare);

    int a, b, c; // a+b>c
    for(int i=0; i<v.size()-2; i++){
        c = v[i]; // 앞에서부터
        a = v[i+1];
        b = v[i+2];
        if ((a+b)>c){
            result = a + b + c;
            break;
        }
    }

    cout << result << '\n';
    return 0;
}