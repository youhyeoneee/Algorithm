#include <iostream>
#include <string>
#define MAX 110
using namespace std;


int dp[MAX][MAX][MAX]; // a b c
int offset = 50; // -50 ~ 50 이므로 0 ~ 100 
int zero = 0 + offset;
int twenty = 20 + offset;
bool isInited = false;
int getDP(int a, int b, int c);
int w(int a, int b, int c);

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(int &a, int  &b, int &c) {
    cin >> a >> b >> c;
}

int getDP(int a, int b, int c) {
    if (dp[a][b][c] == 0) {
        dp[a][b][c] = w(a, b, c);
    }

    return dp[a][b][c];
}

int w(int a, int b, int c) {

    if (a <= zero || b <= zero || c <= zero)
        return getDP(a, b, c);

    if (a > twenty || b > twenty || c > twenty) {
        return getDP(twenty, twenty, twenty);
    } 

    if (a < b && b < c) {
        return getDP(a, b, c-1) + getDP(a, b-1, c-1) - getDP(a, b-1, c);
    }
    else {
        return getDP(a-1, b, c) + getDP(a-1, b-1, c) + getDP(a-1, b, c-1) - getDP(a-1, b-1, c-1);
    }
}

int solve(int a, int b, int c) {

    // init 
    if (!isInited) {
        for(int i=0; i<MAX; i++) {
            for(int j=0; j<MAX; j++) {
                for(int k=0; k<=zero; k++) {
                    dp[k][i][j] = 1;
                    dp[i][k][j] = 1;
                    dp[i][j][k] = 1;
                }
            }
        }
        isInited = true;
    }
    
    int A = a + offset, B = b + offset, C = c + offset;

    dp[A][B][C] = w(A, B, C);

    return dp[A][B][C];
}

void output(int a, int b, int c, int result) {
    cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
}   

int main() {
    fastIO();

    int a, b, c;
    while(true) {
        input(a, b, c);
        if (a == -1 && b== -1 && c == -1) {
            break;
        }

        output(a, b, c, solve(a, b, c));

    }

    return 0;
}