#include <iostream>
#include <algorithm>

using namespace std;
long long arr[100001];


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 

    int N;

    cin >> N;


    for (int i=0; i<N; i++)
        cin >> arr[i];
    
    sort(arr, arr+N); // 정렬

    int cnt, max, idx; // cnt = 현재 카운트 max = 젤 많은 카운트 idx = 젤 많은 숫자 idx

    cnt = 1;
    max = 1;
    idx = 0;

    for(int i=1; i<N; i++){

        if (arr[i] == arr[i-1]){ // 전에 꺼랑 같으면
            cnt++;
        }

        else{ // 다르면
            if(cnt > max){
                max = cnt;
                idx = i-1;
            }
            cnt = 1;

        }
        
    }
    
    if(cnt > max){
        max = cnt;
        idx = N-1;
    }

    cout << arr[idx] << '\n';
    
    return 0;
}