#include <ctime>
#include <iostream>

using namespace std;

int main(void)
{
    
    time_t timer = time(NULL);

    struct tm* localTime = localtime(&timer);

    cout << localTime->tm_year + 1900 <<  "-";

    cout.width(2);
    cout.fill('0');
    cout << localTime->tm_mon + 1;
    
    cout << '-';

    cout.width(2);
    cout.fill('0');
    cout << localTime->tm_mday;

    return 0;
}