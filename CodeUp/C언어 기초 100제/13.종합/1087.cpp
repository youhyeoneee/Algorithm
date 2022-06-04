#include <iostream>

using namespace std;

int main(){

    int a, i=1, sum=0;

    cin >> a;
    while(sum<a){
        sum+=i;
        i++;
    }
    cout << sum << '\n';
    return 0;
}