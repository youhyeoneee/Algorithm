#include <iostream>
#include <string>

using namespace std;

int main(){

    int T, score, cnt;
    string str;

    cin >> T;
    
    for(int i=0;i<T; i++){
        cin >> str;

        score = 0;
        cnt = 0;
        for (char ch : str){
            if (ch == 'O'){
                if (cnt >= 0) cnt++;
                score += cnt;
            }
            else cnt = 0;
        }

        cout << score << '\n';
    }
    return 0;
}