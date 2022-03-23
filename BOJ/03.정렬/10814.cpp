#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, string>> info; //이름, 들어온 순서

bool compare(pair<int,string> a, pair<int,string> b)
{
    return a.first < b.first;
}


int main(){

    int N;

    cin >> N;

    int age;
    string name;

    for (int i=0; i<N; i++){
        cin >> age >> name;
        info.push_back({age, name});
    }
       

    stable_sort(info.begin(), info.end(), compare);


    for (int i=0; i<N; i++){
        cout << info[i].first << " " << info[i].second << '\n';
    }


    return 0;
}