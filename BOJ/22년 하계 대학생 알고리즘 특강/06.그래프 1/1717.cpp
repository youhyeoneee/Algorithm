#include <iostream>

// 집합의 표현
using namespace std;

int n, m, x, a, b;

int parent[1000001];

int Find(int a){
    if (parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    int root_a = Find(a);
    int root_b = Find(b);
    parent[root_a] = root_b;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;  
    // {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합
    // m은 입력으로 주어지는 연산의 개수

    // init

    for (int i=0; i<=n; i++)
        parent[i] = i;

    for (int i=0; i<m; i++){
        cin >> x >> a >> b;
        // a와 b는 n 이하의 자연수 또는 0

        if (x==0){
            // 합집합 : 0 a b
            // a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다     
            if (a != b) Union(a, b);
        }
        else if (x==1){
            // 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산 : 1 a b의 형태
            // a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산
            if (a==b) cout << "YES\n";
            else{
                if (Find(a) == Find(b)) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }



}