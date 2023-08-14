#include <iostream>
#include <string>

using namespace std;

string arr[6] =
{
    "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE",
    "N2 Bomber      Heavy Fighter  Limited    21        ",
    "J-Type 327     Light Combat   Unlimited  1         ",
    "NX Cruiser     Medium Fighter Limited    18        ",
    "N1 Starfighter Medium Fighter Unlimited  25        ",
    "Royal Cruiser  Light Combat   Limited    4         ",
};

int main()
{
    for(auto str : arr)
    {
        cout << str << '\n';
    }

    return 0;
}