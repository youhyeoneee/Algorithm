#include <iostream>
#include <string>

using namespace std;

int main(){
    int dateArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string dayArr[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int x, y;
    int date = 0;

    cin >> x  >> y;

    for(int i=0; i<(x-1); i++)
        date += dateArr[i];
    
    date += (y-1);


    cout << dayArr[date%7];

    return 0;

}