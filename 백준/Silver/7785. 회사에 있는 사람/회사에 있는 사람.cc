#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int n;
map<string, bool, greater<string>> logs;


void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<string> split(string input, string delimiter) {
   vector<string> ret;
   
   long long pos = 0;
   string token = "";
   
   while ((pos = input.find(delimiter)) != string::npos) { 
      token = input.substr(0, pos);
      ret.push_back(token);
      input.erase(0, pos + delimiter.length());
  }
  
  ret.push_back(input);
  
  return ret;
}

void setLog(string name, string action)  
{
    if (action == "enter")
    {
        logs[name] = true;
    }
    else if (action == "leave")
    {
        logs[name] = false;
    }
}


void solve()
{
    for(auto i : logs) 
    {
        if (i.second) {
            cout << i.first << '\n';
        }
       
    }
}

void input()
{
    string log;

    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++) {
        getline(cin, log);
        vector<string> v = split(log, " ");
        setLog(v[0], v[1]);
    }
}


int main()
{
    fastIO();
    input();
    solve();

    return 0;
}