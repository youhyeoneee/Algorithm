#include <iostream>
#include <string>

using namespace std;

string N, result;

int trans(int temp, int n){
    if (temp / n > 0){
        result += '1';
        temp -=n;
    }
    else{
        result += '0';
    }

    return temp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;

    if (N == "0"){
        cout << N;
    }
    else{
        for (int i=0; i<N.length(); i++){
                int temp = N[i] - '0';
                for(int j=4; j>0; j/=2){
                    temp = trans(temp, j);
                }
            }
        }
        
        bool flag = false;
        for (int i=0; i<result.length(); i++){
            if (!flag){ // 맨앞 0 제거
                if (result[i] == '1'){
                    flag = true;
                    cout << result[i];
                }
            }
            else{
                cout << result[i];
            }

        }
    cout << '\n';

    return 0;
}