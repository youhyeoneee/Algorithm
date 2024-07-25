#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0) {
        int share = n / 3; 
        int remainder = n % 3;         
        
        if (remainder == 0) {
            share--;
            remainder = 4;
        } 
        
        answer = to_string(remainder) + answer;
        
        n = share;
    }
    
    return answer;
}