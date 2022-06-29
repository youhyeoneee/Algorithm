#include <iostream>

using namespace std;

int main(){
    int A, B;

    // while(!(cin>>A>>B).eof()){
    //     cout << A+B << endl;
    // }

    while(scanf("%d %d", &A, &B) == 2){
        cout << A+B << endl;
    }
   
    return 0;
}