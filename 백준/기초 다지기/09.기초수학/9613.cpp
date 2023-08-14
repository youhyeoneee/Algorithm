#include <iostream>
#include <algorithm>

using namespace std;

int num_list[100] = {0,};

int gcd(int a, int b){
    while(b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    long long sum;

    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        sum = 0;
        for(int j=0; j<n; j++){
            cin >> num_list[j];
        }

        for (int j=0; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                sum += gcd(num_list[j], num_list[k]);
            }
        }
        cout << sum << '\n';
    }


    return 0;
}