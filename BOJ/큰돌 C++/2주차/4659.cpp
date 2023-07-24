#include <iostream>
#include <string>

using namespace std;


string str;

char moeumArr[5] = {'a', 'i', 'e', 'o', 'u'};


bool firstCondition; // 1. 모음이 있는가
bool secondCondition; // 2. 모음이나 자음이 3번 반복되지 않는가
bool thirdCondition; // 3. 같은 글자가 2번 반복되지 않는가 (ee, oo 제외)

bool isMoeum(char ch)
{
    return ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u';
}

bool isSameChar(char a, char b)
{
    if (a == b)
    {
        if (a == 'e' || a == 'o')
            return false;
        return true;
    }

    return false;
}

bool isAcceptable()
{
    if (!firstCondition) 
        return false;
    else if (!secondCondition)
        return false;
    else if (!thirdCondition)
        return false;
    
    return true;
}


void Solve()
{
    firstCondition = false;
    for(char ch : str)
    {   

        if (!firstCondition && isMoeum(ch))
            firstCondition = true;
    }

    // 2글자 이상인 경우
    thirdCondition = true;
    if (firstCondition)
    {
        for(int i=0; i<str.size()-1; i++)
        {
            if (isSameChar(str[i], str[i+1]))
            {
                thirdCondition = false;
                break;
            }
        }
    }

    secondCondition = true;
 
    if(thirdCondition)
    {
        // 3글자 이상인 경우 
        if (str.size() >= 3)
        {
            for(int i=0; i<str.size()-2; i++)
            {
                // 모음 개수 
                int cnt = 0;

                if (isMoeum(str[i])) cnt++;
                if (isMoeum(str[i+1])) cnt++;
                if (isMoeum(str[i+2])) cnt++;

                if (cnt == 0 || cnt == 3)
                {
                    secondCondition = false;
                    break;
                }

            }
        }
    }   

    cout << "<" << str << "> is ";

    if (!isAcceptable())    
        cout << "not ";
    
    cout << "acceptable.\n";
}

void Solve2()
{
    
    int mCnt = 0; // 모음개수 
    int jCnt = 0; // 자음개수
    bool isIncludeM = false;
    bool isAcceptable2 = true;

    for(int i=0; i<str.size(); i++)
    {
        char ch = str[i];
        // 모음인 경우
        if (isMoeum(ch)) 
        {
            mCnt++;
            jCnt = 0;
            isIncludeM = true;
        }
        else // 자음인 경우
        {
            mCnt = 0;
            jCnt++;
        }

        if (mCnt == 3 || jCnt == 3)
        {
            isAcceptable2 = false;
            break;
        }
        
        if (i >= 1)
        {   
            if (isSameChar(str[i-1], ch))
            {
                isAcceptable2 = false;
                break;
            }

        }

    }

    if (!isIncludeM) isAcceptable2 = false;

    cout << "<" << str << "> is ";

    if (!isAcceptable2)    
        cout << "not ";
    
    cout << "acceptable.\n";

}

void Input()
{
    while(true)
    {
        cin >> str;
        if (str == "end")   
            break;
        Solve2();
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    return 0;
}