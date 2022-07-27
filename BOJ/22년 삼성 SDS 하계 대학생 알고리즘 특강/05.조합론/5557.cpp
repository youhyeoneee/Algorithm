#include <iostream>

// 1학년

using namespace std;

int arr[101]; 
long result[101][21];
int N;

int main(){

    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    for (int i=0; i<101; i++){
        for( int j=0; j<21; j++){
            result[i][j] = 0; 
        }
    }
    
    for(int i=1; i<N; i++){
        int num = arr[i];

        if (i==1) result[i][num] = 1;
        else{
            for (int j=0; j<21; j++){
                if(result[i-1][j] > 0){
                    int add = j+num;
                    int minus = j-num;
                    if (0 <= add && add <= 20) result[i][add]++;
                    if (0 <= minus && minus <= 20) result[i][minus]++;
                }
            }
        }

        cout << i << " : ";
        for (int j=0; j<21; j++){
            if (result[i][j] > 0) cout << j << "=" << result[i][j] << " ";
        }
        cout << '\n';
    }

    cout << result[N][arr[N]] << '\n';

    int cnt = 0;
    
}