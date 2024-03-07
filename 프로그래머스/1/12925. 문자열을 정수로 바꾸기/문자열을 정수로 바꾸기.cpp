#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int start = 0;
    string num = "";
    int sign = 1;
    
    if (s[0] == '-') {
        sign = -1;
        start = 1; 
    }
    
     for(int i=start; i<=s.length(); i++) {
          num += s[i];
      }  
    
    return stoi(num) * sign;
}