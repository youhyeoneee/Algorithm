#include <iostream>

using namespace std;

int main() {

    int origin_chess[6] = {1, 1, 2, 2, 2, 8};
    int chess[6];

    for(int i=0; i<6; i++) {
        cin >> chess[i];
    }

    for(int i=0; i<6; i++) {
        cout << origin_chess[i] - chess[i] << ' ';

    }

     
    return 0;
}