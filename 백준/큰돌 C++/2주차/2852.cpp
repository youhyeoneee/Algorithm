#include <iostream>
#include <string>

using namespace std;

int N;

void Input()
{
    cin >> N;
}

pair<int, int> StringToTime(string str)
{
    int H = stoi(str.substr(0, 2));
    int M = stoi(str.substr(3, 5));

    return {H, M};
}

string TimeToString(int H, int M)
{
    string str = "";
    if (H < 10) str+= "0" + to_string(H);
    else str += to_string(H);

    str += ":";

    if (M < 10) str+= "0" + to_string(M);
    else str += to_string(M);

    return str;
}


// time1 - time2
string SubTime(string timeStr1, string timeStr2)
{
    pair<int, int> time1 = StringToTime(timeStr1);
    pair<int, int> time2 = StringToTime(timeStr2);

    int H, M;

    if (time1.second < time2.second)
    {
        time1.second += 60;     
        time1.first -= 1;   
    }

    M = time1.second - time2.second;
    H = time1.first - time2.first;

    return TimeToString(H, M);
}

// time1 + time2
string AddTime(string timeStr1, string timeStr2)
{
    pair<int, int> time1 = StringToTime(timeStr1);
    pair<int, int> time2 = StringToTime(timeStr2);

    int H, M;
    M = time1.second + time2.second;
    H = time1.first + time2.first;

    if (M > 60)
    {
        M -= 60;     
        H += 1;   
    }

    return TimeToString(H, M);
}

void Solve()
{

    int teamNum;
    string timeStr; 

    int score1 = 0;
    int score2 = 0;
    string time1 = "00:00";
    string time2 = "00:00";

    int nowWinnerTeamNum = -1; // 현재 이기고 있던 팀
    string nowWinnerTimeStr = ""; // 현재 이기고 있던 팀이 처음 이기기 시작한 시간


    for(int i=0; i<N; i++)
    {
        cin >> teamNum >> timeStr;

        if (teamNum == 1) score1++;
        else if (teamNum ==2) score2++;

        if (score1 == score2)
        {
            if (nowWinnerTeamNum == 1) time1 = AddTime(time1, SubTime(timeStr, nowWinnerTimeStr));
            else if (nowWinnerTeamNum == 2) time2 = AddTime(time2, SubTime(timeStr, nowWinnerTimeStr));
            nowWinnerTeamNum = -1;
            nowWinnerTimeStr = "";
        }
        else 
        {
            if (nowWinnerTimeStr.size() == 0) nowWinnerTimeStr = timeStr;
            if (score1 > score2) nowWinnerTeamNum = 1;
            else nowWinnerTeamNum = 2;
        }
        
    }

    if (nowWinnerTeamNum == 1) time1 = AddTime(time1, SubTime("48:00", nowWinnerTimeStr));
    else if (nowWinnerTeamNum == 2) time2 = AddTime(time2, SubTime("48:00", nowWinnerTimeStr));

    cout << time1 << "\n" << time2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}