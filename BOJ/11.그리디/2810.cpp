#include <iostream>
#include <string>

// 브론즈 1

using namespace std;


int main(){

    int N; // 사람의 수
    string str; // 좌석 정보 

    cin >> N;
    cin >> str;

    int result = N+1;
    // 컵홀더 만들기
    int cnt = 0; // 커플 수
    for (int i=0; i<str.size(); i++){
        if (str[i] == 'L'){
            cnt++;
            if (cnt%2==0){
                result--;
            }
        }       
    }

    if (cnt != 0)
        cout << result << '\n';
    else
        cout << N << '\n';
    return 0;
}