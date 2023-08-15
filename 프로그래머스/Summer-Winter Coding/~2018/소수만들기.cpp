#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int r = 3;
vector<int> ind;

bool isPrime(int n){
    for (int i=2; i<n; i++){
        if (n%i == 0)
            return false;
    }
    
    return true;
    
}

int solution(vector<int> nums) {
    int answer = 0;
    
   
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    // (1) 조합
    // r개의 1 추가
	for(int i=0; i<r; i++){
		ind.push_back(1);
	}
    
    // nums.size개-r개의 0 추가
	for(int i=0; i<nums.size()-r; i++){
		ind.push_back(0);
	}

    // 정렬
	sort(ind.begin(), ind.end());

    //순열
	do{

        int temp = 0;
		// 출력
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 1){
                temp += nums[i];
				//printf("%d ", nums[i]);
			}
		}
        if(isPrime(temp))
            answer++;

	}while(next_permutation(ind.begin(), ind.end()));


    return answer;
}


int main(){

    // vector<int> nums = {1,2,3,4}; // 1
    vector<int> nums = {1,2,7,6,4}; // 4
    cout << solution(nums) << endl;
}