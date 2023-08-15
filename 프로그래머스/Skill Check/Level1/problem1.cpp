#include <string>
#include <vector>
#include <iostream>

using namespace std;

string tenTotwo(int n, int size){ //10진수 -> 2진수
    vector<int> v;
    string str = "";
    while((n/2)>0){
        v.push_back(n%2);
        n = n/2;
    }
     v.push_back(n%2);

    if(v.size() < size){
        for(int i=size; i>v.size(); i--)
            str += '0';
    }
    for(int i=v.size()-1; i>=0; i--){
        str += to_string(v[i]);
    }
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string str1, str2; 


    for (int i=0; i<n; i++){
        string str3;
        str1 = tenTotwo(arr1[i], n);
        str2 = tenTotwo(arr2[i], n);    
        for (int j=0; j<n; j++){
            if (str1[j] == '0' && str2[j] == '0' ){
                str3 += ' ';
            }
            else{
                str3 += '#';
            }
        }
        answer.push_back(str3);
    }
    return answer;
}

int main(){
    int n = 5;
    vector<int> arr1 = {46, 33, 33 ,22, 31, 50};
    vector<int> arr2 = {27 ,56, 19, 14, 14, 10};


    solution(n, arr1, arr2);
    return 0;
}
