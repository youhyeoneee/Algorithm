#include <iostream>

using namespace std;

int main(){

    int a, i=1, sum=0;

    cin >> a;
    for(int i=1; i<=a; i++){
        if (i%3==0)
            continue;
        cout << i << ' ';
    }
    return 0;
}