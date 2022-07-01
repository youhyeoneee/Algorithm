#include <iostream>
#include <string>
#define SIZE 26

using namespace std;

char alpabet[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int alpabet_num[SIZE] = {0,};



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;

    cin >> S;

    for (int i=0; i<SIZE; i++){
        
        if (S.find(alpabet[i]) != string::npos)
            alpabet_num[i] = S.find(alpabet[i]);
        else
            alpabet_num[i] = -1;
    }

    
    for(int i=0; i<SIZE; i++){
        cout << alpabet_num[i] << " ";
    }

    cout << '\n';

    return 0;
}