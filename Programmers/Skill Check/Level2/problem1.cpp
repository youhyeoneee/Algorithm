#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int a, b, c; // 번호, 차례, 탈락한 순서저장
    bool result = true;
    for(int i=1; i<words.size(); i++){
        string before = words[i-1];
        string now = words[i];
        
        // 이어서 잘 말했는지 
        if (now[0] == before[before.size()-1]){
            // 이미 나온 단어인지
            for (int j=0; j<i; j++){
                if (now == words[j])
                    result = false;
            }
        }
        else{
             result = false;
        }

        if (!result){
            c = i;
            break;
        }
            
    }
    
    if (result)
        answer = {0, 0};
    else{         // 탈락했을 경우         
        
        // 번호
        a = (c+1)%n;
        if(a==0) 
            a = n;
        
        // 차례
        b = ((c+1)/n); 
        if((c+1)%n>0)
            b+=1;
        answer = {a, b};
        
    }
    
    cout << answer[0] << ", " << answer[1] << endl;           

    return answer;
}

int main(){
    int n = 2;
	vector<string> words = {"hello", "one", "even", "never", "now", "world", "draw"};
    solution(n, words);
    return 0;
}