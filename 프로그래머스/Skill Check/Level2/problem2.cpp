#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0; i<numbers.size();i++){
        if(numbers[i]%2==0){
            answer.push_back(numbers[i]+1);
        }
        else{
           long long lastbit = (numbers[i]+1) & -(numbers[i]+1);
            answer.push_back((numbers[i]|lastbit) & (~(lastbit>>1)));
        }
    }
    return answer;
}

int main() {

    vector<long long> numbers = {2, 7};
    vector<long long> answer = solution(numbers);

    for (int i=0; i<answer.size(); i++)
        cout << answer[i] << ',';
    return 0;
}