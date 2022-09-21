#include <iostream>
#include <string.h>
#include <vector>
#include <climits>

#define endl '\n'
#define DEBUG(X) cout << X << "\n";

using namespace std;

int N; // 숫자의 개수
int arr[4]; // '+', '-', '*', '/' 순서대로 연산자 카드의 개수
vector<int> number, susik; 
int minn, maxx;


void Init(){
    number.clear();
    susik.clear();
    minn = INT_MAX;
    maxx = - INT_MAX;
}

void Input(){
   cin >> N;
   for(int i=0; i<4; i++)
    cin >> arr[i];
    int data;
    for(int i=0; i<N; i++){
        cin >> data;
        number.push_back(data);
    }
}

int Calc(){
    int result = number[0];

    for(int i=0; i<susik.size(); i++){
         // '+', '-', '*', '/' 
        if (susik[i] == 0) result += number[i+1];
        else if (susik[i] == 1) result -= number[i+1];
        else if (susik[i] == 2) result *= number[i+1];
        else if (susik[i] == 3) result /= number[i+1];
    }

    return result;
}

void Dfs(int cnt){
    if (cnt == N){ // 연산자 다 썼으면 갱신
        int result = Calc();
        minn = min(minn, result);
        maxx = max(maxx, result);
    }
    else{ 
        for(int i=0; i<4; i++){
            if(arr[i] > 0){  // 사용할 수 있는 연산자가 남았다면
                susik.push_back(i);
                arr[i]--;
                Dfs(cnt+1);
                arr[i]++;
                susik.pop_back();
            }
        }
    }
}

void Solve(){
   Dfs(1);
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		Init();
        Input();
        Solve();
        cout << "#" << test_case << " " << maxx - minn << endl;
	}
	return 0;
}