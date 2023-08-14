#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K, temp;
    
    cin >> N >> K;

    queue<int> q;

    for (int i=1; i<=N; i++){
        q.push(i);
    }

    cout << '<';

    while(q.size() > 1){
        for(int i=1; i<K; i++){
            temp = q.front();
            q.push(temp);
            q.pop();
        }

        temp = q.front();
        cout << temp << ", " ;
        q.pop();
    }
    
    temp = q.front();
    cout << temp << ">\n";
    return 0;
}