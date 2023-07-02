#include <iostream>
#include <map>
#include <string>

using namespace std;


map<string, float> scoreMap;
map<string, float>::iterator p;


void Init()
{
    scoreMap["A+"] = 4.3;
    scoreMap["A0"] = 4.0;
    scoreMap["A-"] = 3.7;
    scoreMap["B+"] = 3.3;
    scoreMap["B0"] = 3.0;
    scoreMap["B-"] = 2.7;
    scoreMap["C+"] = 2.3;
    scoreMap["C0"] = 2.0;
    scoreMap["C-"] = 1.7;
    scoreMap["D+"] = 1.3;
    scoreMap["D0"] = 1.0;
    scoreMap["D-"] = 0.7;
    scoreMap["F"] = 0.0;
}

void Solve()
{

    string score;
    cin >> score;
    p = scoreMap.find(score); 
    cout << fixed;
    cout.precision(1);
    cout << p->second;
}

int main()
{
    
    Init();
    Solve();
    
    return 0;
}