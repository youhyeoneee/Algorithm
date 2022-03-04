#include <iostream>
#include <string>

using namespace std;

int main(){

    string text;

    while (!(getline(cin, text)).eof())
    {   
        cout << text <<endl;
    }

    return 0;
}