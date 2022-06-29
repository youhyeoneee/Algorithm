#include <iostream>

using namespace std;

int main(){

    int N;

    cin >> N;

    int left, right, center;

    for(int i=0; i<N-1; i++){
        center = N-1;
        left = center-i; // 3
        right = center+i; // 3 

        for(int j=0; j<left; j++) // 0 1 2 
            cout << " ";
        cout <<"*"; // left // 3 
        for(int j=left; j<right-1; j++) // 3 2
            cout <<" "; 
        if (left != right)
            cout << "*"; //right
        cout << "\n";
        
    }

    // 마지막 꽉찬 줄
    for (int i=0; i<2*N-1; i++)
        cout << "*";
    cout << "\n";
    return 0;
}