#include <iostream>
#include <queue>

// 가운데를 말해요 

using namespace std;

priority_queue<int> q;
priority_queue<int> q2;

int N, X;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i=1; i<=N; i++){
        cin >> X;
        q.push(X);

        q2 = priority_queue <int>(); // clear
        
        while(!q.empty()){ // copy
            q2.push(q.top());
            q.pop();
        }

        int cnt = 0;
        while(!q2.empty()){
            cnt++;
            int item =  q2.top();
            q.push(item);
            if (cnt == (i/2)+1)
                cout << item << '\n';  
            q2.pop();
        }
        
    }

    

    return 0;
}