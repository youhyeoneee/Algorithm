#include <iostream>
#include <vector>

// 브론즈 1

using namespace std;

int main(){

    int N, temp, result = 0;

    cin >> N;
    vector<int> hanzo;

    for (int i=0; i<N; i++){
        cin >> temp;
        hanzo.push_back(temp);
    }

    int now_hanzo, cnt; // 현재 활잡이, 처치한 적의 수
    for(int i=0; i<N; i++){
        now_hanzo = hanzo[i];
        cnt = 0;
        for (int j=i+1; j<N; j++){
            if (now_hanzo < hanzo[j])// 높은 봉우리를 만났을 경우
                break;
            else
                cnt++;
        }

        result = max(result, cnt);
    }
    cout << result << '\n';


    return 0;
}