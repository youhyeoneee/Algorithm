#include <iostream>
#include <string>
#define SIZE 26

using namespace std;

char alpabet[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int alpabet_num[SIZE] = {0,};

void findAlpabet(char item){
    for(int i=0; i<SIZE; i++){
        if (item == alpabet[i])
            alpabet_num[i] += 1;
    }
}


int main () {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string S;

    cin >> S;

    for (int i=0; i<S.length(); i++){
        findAlpabet(S[i]);
    }

    for(int i=0; i<SIZE; i++){
        cout << alpabet_num[i] << " ";
    }

    cout << '\n';
    

    return 0;
}