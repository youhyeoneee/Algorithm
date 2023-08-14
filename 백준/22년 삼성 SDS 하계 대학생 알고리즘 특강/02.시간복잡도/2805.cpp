#include <iostream>
#include <vector>
#include <algorithm>

// 나무 자르기
using namespace std;

vector<int> tree;
long long N, M, H; // 나무의 수 N, 상근이가 집으로 가져가려고 하는 나무의 길이 M, 나무 높이 H


long long cut(int k){
    long long sum = 0;
    for(int i=0; i<N; i++){
        if(tree[i] > k) sum += tree[i] - k;
    }
    return sum;
}


int main(){

    cin >> N >> M;

    for (int i=0; i<N; i++){
        cin >> H;
        tree.push_back(H);
    }
    
    // 나무 자르기
    int low = 0, high =*max_element(tree.begin(),tree.end()), mid = (low+high)/2; H;
    long long wood = 0;

    // 이분탐색으로 잘라야 할 최대 나무 길이 찾기
    while(low<=high){
        mid = (low+high)/2,
        wood = cut(mid);
        
        if (wood < M) high = mid-1; // 나무 길이 높이기
        else { // 나무 길이 낮추기
            H = mid;
            low = mid+1;
        }; 
    }
    
    cout << H << '\n';
   
    return 0;
}