#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[34]; 

bool isInVec(vector<int> v, int i)
{
    return find(v.begin(), v.end(), i) != v.end();
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int answer = 0;
    
    fill(&arr[0], &arr[0] + 34, 1);
    
    for(int i : lost)
    {
        arr[i] = 0;    
    }
    
    for(int i : reserve)
    {
        arr[i] = 2;
        
        // 여벌의 체육복을 가져온 학생이 체육복을 도난당한 경우 
        if (isInVec(lost, i))
        {
            arr[i] = 1;
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        if (arr[i] == 2)
        {
            if (arr[i-1] == 0)
            {
                arr[i-1] = 1;
                arr[i] = 1;
            }
            else if (arr[i+1] == 0)
            {
                arr[i+1] = 1;
                arr[i] = 1;
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        if (arr[i] > 0) 
            answer++;
    }
    
    return answer;
}