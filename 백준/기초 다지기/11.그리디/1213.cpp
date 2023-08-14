#include <iostream>
#include <string>
#include <vector>

// 실버 3

using namespace std;

string make_string(char a, int cnt){
    string temp;
    for(int i=0; i<cnt; i++)
        temp += a;
    
    return temp;
}
int main(){

    string name, result;

    cin >> name;
    
    int arr[26] = {0, }; // 알파벳 개수 저장

    vector<pair<char, int>> v;
    // 각 문자 개수 세기 
    for(int i=0; i<name.size(); i++)
        arr[(int)name[i]-65]++;

    bool is_fail = false;
    if (name.size() % 2 == 0){ // 자리수 짝수면 -> 다 짝수개여야함
        for (int i=0; i<26; i++){
            if (arr[i]!= 0){
                if (arr[i] % 2 != 0)
                    is_fail = true;
                else{
                    v.push_back(make_pair(i+65, arr[i]));
                }
            }

        }

        if (!is_fail){
            // 문자열 만들기
            int idx = 0;
            for (int i=0; i<v.size(); i++){
                result.insert(idx, make_string(v[i].first, v[i].second));
                idx += v[i].second / 2;
            }   
        }
            
    }
    else{ // 자리수 홀수면 -> 하나 빼고 다 짝수여야 함
        int cnt = 0;
        for (int i=0; i<26; i++){
            if (arr[i]!= 0){
                if (arr[i] % 2 != 0){
                    cnt++;
                    if (cnt > 1)
                        is_fail = true;
                    else
                        v.push_back(make_pair(i+65, arr[i]));
                }
                else{
                    v.push_back(make_pair(i+65, arr[i]));
                }
            }

        }

         if (!is_fail){
            // 문자열 만들기
            int idx = 0;
            char odd; // 홀수인 문자 (가운데에 넣을 것)
            for (int i=0; i<v.size(); i++){
                if (v[i].second % 2 != 0){
                    result.insert(idx, make_string(v[i].first, v[i].second-1));
                    idx += v[i].second / 2;
                    odd = v[i].first;
                }
                else{
                    result.insert(idx, make_string(v[i].first, v[i].second));
                    idx += v[i].second / 2;
                }
                
            }   

            result.insert(idx, make_string(odd, 1));
        }
    }
    

    
    if (is_fail)
        cout << "I'm Sorry Hansoo" << '\n';
    else
        cout << result << '\n';

   

    return 0;
}