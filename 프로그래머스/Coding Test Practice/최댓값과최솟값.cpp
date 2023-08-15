#include <string>
#include <vector>
#include <iostream>

using namespace std;

int mmax = -987654321;
int mmin = 987654321;

string solution(string s) {
    string answer = "";
    
   string str = "";
    
    for(char ch : s)
    {
        if (ch == ' ')
        {
            mmin = min(stoi(str), mmin);
            mmax = max(stoi(str), mmax);
            str = "";
        }
        else 
            str += ch;
        
    }
    
    if (str.length() > 0)
    {            
        mmin = min(stoi(str), mmin);
        mmax = max(stoi(str), mmax);
    }
    
    answer = to_string(mmin) + " " + to_string(mmax);
    
    
    return answer;
}

int main()
{
    cout << solution("1 2 3 4");    
    return 0;
}