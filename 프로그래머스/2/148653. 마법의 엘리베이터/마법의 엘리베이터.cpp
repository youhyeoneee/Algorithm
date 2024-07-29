#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey) {
        // 현재 자릿값 
        int number = storey % 10;
    
        if (number < 5) {
            answer += number; // 4 -> 3 -> 2 - > 1 -> 0
        } else if (number > 5) {
            answer += 10 - number; // 6 -> 7 -> 8 -> 9 -> 10 
            storey += 10;
        } else { // 5일 경우 
            // 다음 자릿값
            int next = (storey / 10) % 10; 
            if (next >= 5) {
                storey += 10;
            } 
            answer += number;
        }
            
        storey /= 10;
    }
    

    return answer;
}