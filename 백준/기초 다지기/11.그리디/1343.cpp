#include <iostream>
#include <string>

using namespace std;


int main(){

    string S, result;
    cin >> S;

    int cnt = 0, start;
    for (int i=0; i<=S.size(); i++){

        if (cnt == 0){ // X묶음 시작점 저장
            start = i;
        }
        if (S[i] == 'X'){
            cnt++;
        }
        else { // .이나 마지막의 경우 
            if(cnt%4 == 0){
                result.append(cnt, 'A');
            }
            else if (cnt%2 == 0){
                result.append((cnt/4)*4, 'A');
                cnt -= (cnt/4)*4;
                result.append((cnt/2)*2, 'B');
            }
            else{ // 안나누어 지는 경우 
                cout << -1 << '\n';
                return 0;
            }
            if(S[i] == '.')
                result.append(1, '.');
            cnt = 0;
        }
    }

    cout << result << '\n';

}