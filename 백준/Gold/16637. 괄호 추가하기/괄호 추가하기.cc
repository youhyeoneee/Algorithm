#include <iostream>
#include <vector>

using namespace std;

int N; // 수식의 길이 1 ~ 19 

vector<int> numVec; // 숫자 벡터 
vector<char> operVec; // 연산자 벡터

int result = -987654321;

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Input()
{
    cin >> N;

    char temp; 
    for(int i=0; i<N; i++)
    {
        cin >> temp;

        // 숫자와 기호 구분하기
        if ('0' <= temp && temp <= '9') 
            numVec.push_back(temp - '0');
        else 
            operVec.push_back(temp);
    }
}

int Calculate(char oper, int a, int b)
{
    if (oper == '+') return a+b;
    else if (oper == '-') return a-b;
    else if (oper == '*') return a*b;
}

void Go(int idx, int num)
{
    if (idx == numVec.size() - 1)
    {
        result = max(result, num);
        return;
    }

    int temp = Calculate(operVec[idx], num, numVec[idx+1]); // 8*3 = 24
    Go(idx+1, temp);
    
    if (idx + 2 < numVec.size())
    {
        int temp = Calculate(operVec[idx+1], numVec[idx+1], numVec[idx+2]); 
        Go(idx+2, Calculate(operVec[idx], num, temp));
    }

}

void Solve()
{    
    Go(0, numVec[0]);

    cout << result;
}

int main()
{
    FastIO();
    Input();
    Solve();
}
