#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a, b, c;
vector<int> sides;

bool isSameArr[3];

int GetSameCnt()
{
    int cnt = 0;
    for(int i=0; i<isSameArr.Length(); i++)
    {
        if (isSameArr[i]) cnt++;
    }

    return cnt;
}

bool isSame(int _a, int _b)
{
    return _a == _b;
}

int main()
{

    do {
        cin >> a >> b >> c;

        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(c);

        sort(sides.begin(), sides.end());

        if (sides[0] < sides[1] + sides[2])
            cout << "Invalid\n";


        // isSameArr = {isSame(a,b), isSame(b,c), isSame(a,c)};

        // int cnt = GetSameCnt();

        // switch (cnt)
        // {
        // case 3:
        //     cout << "Equilateral\n";
        //     break;
        // case 1:
        //     cout << "Scalene\n";
        //     break;
        // case 0:
        //     cout << "Isosceles\n";
        // default:
        //     break;
        // }
    } while (a != 0 && b != 0 && c != 0);
    
 
    return 0;
}