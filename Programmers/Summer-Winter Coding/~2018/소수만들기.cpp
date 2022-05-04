#include <vector>
#include <iostream>
using namespace std;

int n, r = 3;
int result = 0;

bool isPrime(int n){
    for (int i=2; i<n; i++){
        if (n%i == 0)
            return false;
    }
    
    return true;
    
}
// nC3
void combination(vector<int> nums, int k) { 
    
    int temp = 0;
    if (nums.size() == r) { 

        for (int i = 0; i < nums.size(); i++) 
            temp += nums[i]; // (2) 더하기
        
        cout << "(2) : " << temp << endl;
        if (isPrime(temp)) // (3) 소수 판별
            result++; 
        cout << "(3) : " <<result << endl;

    } 
    else if( k == n + 1 ){ 
        cout << "here" << endl;

    } 
    else { 
        nums.push_back(k); 
        combination(nums, k + 1); 
        nums.pop_back(); 
        combination(nums, k + 1); 
    }
}

int solution(vector<int> nums) {
    int answer = -1;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    // (1) 조합
    n = nums.size();

    cout << n << endl;
    combination(nums, 1);
    
    return result;
}


int main(){
    vector<int> nums = {1,2,3,4};
    cout << solution(nums) << endl;
}