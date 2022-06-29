#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string S;

    cin >> S;

    string S_list[S.length()];

    for(int i=0; i<S.length(); i++){
        S_list[i] = S.substr(i, S.length()-i);
    } 

    sort(S_list, S_list+S.length());

    for(int i=0; i<S.length(); i++){
        cout << S_list[i] << '\n';
    }


    return 0;
}