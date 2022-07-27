#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M, a, b;

vector<int> arr[320001]; // 인접 리스트
int indegree[320001]; // 진입차수
int result[32001], idx = 0; // 정답

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    // M은 키를 비교한 회수
    
    for(int i=0; i<M; i++){
        cin >> a >> b;
        arr[a].push_back(b); // 인접 리스트
        indegree[b]++;
    }
   
    
    deque<int> q;

    for(int i=1; i<=N; i++){
        if(!indegree[i]) q.push_back(i);
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop_front();

        result[idx++] = curr;
        for(int next : arr[curr]){
            if(!--indegree[next]) q.push_back(next);
        }
    }

    for(int i=0; i<idx; i++)
        cout << result[i] << " ";

    return 0;
}