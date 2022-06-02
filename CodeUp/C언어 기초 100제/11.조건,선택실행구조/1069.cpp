#include <iostream>

using namespace std;

int main(){

    char a;
    cin >> a;
    
    switch (a)
    {
    case 'A':
        cout << "best!!!";
        break;
    case 'B':
        cout << "good!!";
        break;
    case 'C':
        cout << "run!";
        break;
    case 'D':
        cout << "slowly~";
        break;
       
    default:
        cout << "what?";
    }
  

    return 0;
}

  