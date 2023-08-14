#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sum = 0, num;

    cin >> N;

    num = N;
    do{
        sum ++;
        if (num<10) num += (num*10);
        else num = (num%10)*10 + ((num/10 + num%10) % 10);
    }while(num != N);

    cout << sum;

    return 0;
}