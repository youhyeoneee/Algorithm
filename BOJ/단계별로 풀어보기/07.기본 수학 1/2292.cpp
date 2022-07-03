#include <iostream>

using namespace std;

int main(){

    int N, num = 1;

    cin >> N;

    for(int i=0; ; i++){
        num += 6*i;
        if (num >= N) { cout << i+1; break;}
    }

    return 0;
}