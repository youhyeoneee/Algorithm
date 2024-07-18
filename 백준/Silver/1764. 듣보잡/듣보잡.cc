#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<string> listens, sees;
int N, M;

int main() {
    cin >> N >> M;

    // 듣도 못한 사람 
    string name;
    for(int i=0; i<N; i++) {
        cin >> name;
        listens.push_back(name);
    }

    // 보도 못한 사람 
    for(int i=0; i<M; i++) {
        cin >> name; 
        sees.push_back(name);
    }

    // 정렬
    sort(listens.begin(), listens.end());
    sort(sees.begin(), sees.end());

    int listensIdx = 0, seesIdx = 0;

    vector<string> listenSees;

    while(listensIdx < N && seesIdx < M) {

        string listenName = listens[listensIdx];
        string seeName = sees[seesIdx];

        if (listenName == seeName) {
            listenSees.push_back(listenName);
            listensIdx++;
            seesIdx++;
        } else if (listenName < seeName) {
            listensIdx++;
        } else {
            seesIdx++;
        }
    }

    cout << listenSees.size() << "\n";
    for(string name : listenSees) {
        cout << name << "\n";
    }
    
    return 0;
}