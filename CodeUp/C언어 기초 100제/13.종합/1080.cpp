#include <iostream>

using namespace std;

int main(){

    int n, sum = 0, i=0;
    cin >> n;

    while(sum<n){
        i++;
        sum+=i;
        
    }
    cout << i << '\n';
    return 0;
}