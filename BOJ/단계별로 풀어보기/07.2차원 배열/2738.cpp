
#include <iostream>

using namespace std;

int N, M;
int a[101][101], b[101][101];

int main()
{
    cin >> N >> M;
    
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++){
            cin >> a[r][c];
        }
    }
    
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++){
            cin >> b[r][c];
        }
    }
    
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++){
            cout << a[r][c] + b[r][c] << ' ';
        }
        cout << '\n';
    }
    return 0;
}