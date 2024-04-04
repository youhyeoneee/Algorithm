#include <string>
#include <vector>

using namespace std;

bool arr[10];

int solution(vector<int> numbers) {
    int answer = 0;
    
    for(int i : numbers) {
        arr[i] = true;
    }
    
    
    for(int i=0; i<10; i++) {
        if (!arr[i]) {
            answer += i;
        }
    }
    
    return answer;
}