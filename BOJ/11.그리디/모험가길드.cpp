#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int N, result = 0, cnt = 0; 
    // ���谡�� ��, �׷��� ��, ���� �׷�ȿ� �ִ� ���谡�� ��

    cin >> N;

    vector<int> v;

    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
        
     for(int i=0; i<N; i++){
         cnt ++;
         if (cnt >= i){
            result ++;
            cnt = 0;            
         }
     }

     cout << result << '\n';

    return 0;

}