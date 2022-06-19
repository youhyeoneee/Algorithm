#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 실버 2
int T, max = 0, temp, idx, min_idx;
string N, result;
vector<int> v;

bool find(int num){
    for(int i=0; i<v.size(); i++){
        if (v[i] > num)
            return true;
    }

    return false;
}

int find_min(int num){
    int min = 9;
    for(int i=0; i<v.size(); i++){
        if (v[i] > num){
            if (v[i] < min){
                min_idx = i;
                min = v[i];
            }
        }
    }
    
    return min;
}


int main(){
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;

        result = "";
        v.clear();

        // 맨 마지막부터 
        for(idx=N.size()-1; idx>=0; idx--){
            temp = N[idx]-'0';
            v.push_back(temp); // 넣기
        
            if(idx!=N.size()-1) {
                if(find(temp))
                    break;
            }   
        }


        if(!find(temp)){
            result = "BIGGEST";
        }
        else{
             // 앞에 자리 붙이기
            for(int j=0; j<idx; j++)
                result += N[j];
            
            int min = find_min(temp);

            // 나보다 크면서 제일 작은 수 끼워넣기
            result += min + '0'; // int to char
            v.erase(v.begin() + min_idx);
            
            // 오름차순으로 정렬
            sort(v.begin(), v.end());
            for(int j=0; j<v.size(); j++)
                result += v[j] + '0'; //  int to char          
        }
        
        cout << result << '\n';
        
    }

    return 0;
}