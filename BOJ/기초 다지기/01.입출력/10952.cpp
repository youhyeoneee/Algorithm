#include <iostream>

using namespace std;

int main(){
    int A = -1, B = -1;

    // while(!(cin>>A>>B).eof()){
    //     cout << A+B << endl;
    // }

    while(scanf("%d %d", &A, &B) == 2){

        if (A == 0 && B == 0)
            break;
        cout << A+B << endl;
    }
   
    return 0;
}