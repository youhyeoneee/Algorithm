#include <iostream>

using namespace std;

int main()
{
    for(int i=1; i<=100; ++i)
    {
        bool divByThree = (i%3 == 0);
        bool divByFive = (i%5 == 0);

        if (divByThree &&divByFive)
            cout << "FizzBuzz\n";
        else if (divByThree)
            cout << "Fizz\n";
        else if (divByFive)
            cout << "Buzz\n";
        else
            cout << i << '\n';
    }
}