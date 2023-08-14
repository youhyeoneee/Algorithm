#include <iostream>
#include <algorithm>

using namespace std;

bool isSame(int a, int b)
{
    return a == b;
}

int main()
{
    int A, B, C;

    cin >> A;
    cin >> B;
    cin >> C;


    if (A+B+C != 180)
        cout << "Error\n";
    else // 삼각형 
    {
        bool AB = isSame(A, B);
        bool BC = isSame(B, C);
        bool CA = isSame(A, C);
        bool isSameArr[3] = {AB, BC, CA};


        int cnt = count(isSameArr, isSameArr + 3, true);

        // true true true => Equilateral
        // true false false => Isosceles
        // false false false => Scalene
        switch (cnt)
        {
            case 0:
                cout << "Scalene\n";
                break;
            case 1:
                cout << "Isosceles\n";
                break;
            case 3:
                cout << "Equilateral\n";
                break;
            default:
                break;
        }

    }
}