#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int arr[26] = {0, };
    string str; 

    cin >> str;

    for(char ch : str){
        // 소문자 97 ~ 122 : a ~ z
        if ((int)ch >= 97) arr[(int)ch-97]++;
        // 대문자 65 ~ 90 : A ~ Z
        else arr[(int)ch-65]++;
    }

    // 최댓값 문자 / 개수 / 최댓값
    int max_idx, max_cnt = 0, max = *max_element(arr, arr+26);

    for(int i=0; i<26; i++)
        if (arr[i] == max) {max_cnt++; max_idx = i;}
        
    if (max_cnt>1) cout << "?";
    else cout << (char)(max_idx+65);

    return 0;
}