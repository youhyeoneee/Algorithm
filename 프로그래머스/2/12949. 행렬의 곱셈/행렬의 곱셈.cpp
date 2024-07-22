#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int arr1H = arr1.size();
    int arr1W = arr1[0].size(); // = arrr2H
    int arr2W = arr2[0].size(); 
    
    for(int m=0; m<arr1H; m++) {
        
        vector<int> v;
        for(int n=0; n<arr2W; n++) {
            
            int item=0;  
            for(int k=0; k<arr1W; k++) {
                item += arr1[m][k] * arr2[k][n];
            }
            
            v.push_back(item);
        }
        
        answer.push_back(v);
    }
    
    return answer;
}