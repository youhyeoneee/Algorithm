#include <iostream>
#include <string>
#include <sstream>

using namespace std;


string ReverseString(string in)
{
    string out = "";

    for(int i = in.length()-1; i >= 0; --i)
    {
        out += in[i];
    }
    
    return out;
}


string ReverseString2(string in)
{
    int len = in.length();
    string out;
    out.reserve(len);

    for(int i = len-1; i >= 0; --i)
    {
       out.push_back(in[i]);
    }
    
    return out;
}


int main()
{
    string str = "abcdefsgfgfg";

    cout << ReverseString(str) << '\n'; 
    cout << ReverseString2(str) << '\n'; 

    return 0;
}