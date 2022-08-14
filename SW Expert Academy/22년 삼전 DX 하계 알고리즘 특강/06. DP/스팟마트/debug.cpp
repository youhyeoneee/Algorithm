#include <iostream>

using namespace std;

int getAbit(unsigned short x, int n) { // getbit()
  return (x & (1 << n)) >> n;
}

int main(){

    int test = 0;
    test |= (1 << 2);
    test |= (1 << 4);



    // 0인거 찾기

    for(int i=4; i>=1; i--){
        cout << getAbit(test, i); 

        // MAX 비교 
        if (getAbit(test, i) == 0) cout << A[i] 
    }

    cout << "\n";
    // 삽입
    // test = test << 1 ;
    // test |= (1 << 1);

    cout << test;
}