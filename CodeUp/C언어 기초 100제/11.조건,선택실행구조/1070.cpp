#include <iostream>

using namespace std;

int main(){

    int a;
    cin >> a;
    
    switch (a)
    {
        case 3:
        case 4:
        case 5:
            cout << "spring";
            break;
        case 6:
        case 7:
        case 8:
            cout << "summer";
            break;
        case 9:
        case 10:
        case 11:
            cout << "fall";
            break;
        default:
            cout << "winter";
    }
  

    return 0;
}

  