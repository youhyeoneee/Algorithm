#include <iostream>
#include <vector>

using namespace std;

int map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int N;

vector<int> makeDragonCurve(int dir, int generation) {
    vector<int> v; 
    v.push_back(dir);

    for(int i=0; i<generation; i++) {

        vector<int> new_v; 
        for(int j=v.size()-1; j>=0; j--) {
            int num = (v[j] + 1) % 4;
            new_v.push_back(num);
        }

        for(int j=0; j<new_v.size(); j++) {
            v.push_back(new_v[j]);
        }
    }

    return v;
}

bool check(int x, int y) {
    
    int checkDx[3] = {1, 1, 0};
    int checkDy[3] = {0, 1, 1};

    if (map[y][x]) {
        int cnt = 0;

        for(int i=0; i<3; i++) {
            int ny = y + checkDy[i];
            int nx = x + checkDx[i];

            if (ny < 0 || ny > 100 || nx < 0 || nx > 100) 
                continue;
            
            if (map[ny][nx]) cnt++;
        }
        return cnt == 3;
    }

    return false;
}

int main() {

    cin >> N;

    for(int i=0; i<N; i++) {
        int x, y, d, g; 
        cin >> x >> y >> d >> g;

        vector<int> dirInfo = makeDragonCurve(d, g);

        map[y][x] = 1;

        for(int i : dirInfo) {
            y = y + dy[i];
            x = x + dx[i];
            map[y][x] = 1;
        }
        
    }

    int answer = 0;

    for(int y=0; y<100; y++) {
        for(int x=0; x<100; x++) {
            // 우, 우하, 하 
            if (check(x, y)) answer++;
        }
    }

    cout << answer << "\n";


    return 0;
}