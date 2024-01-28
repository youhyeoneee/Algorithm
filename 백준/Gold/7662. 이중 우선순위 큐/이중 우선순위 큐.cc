#include <iostream>
#include <set>
#include <vector>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<pair<char, int>>> input() {
    int T;
    cin >> T;

    vector<vector<pair<char, int>>> testCases;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        vector<pair<char, int>> commands;
        char order;
        int num;
        while (n--) {
            cin >> order >> num;
            commands.push_back({order, num});
        }

        testCases.push_back(commands);
    }

    return testCases;
}

vector<pair<int, int>> solve(const vector<pair<char, int>>& commands) {
    multiset<int> ms;

    for (const auto& cmd : commands) {
        char order = cmd.first;
        int num = cmd.second;

        if (order == 'I') {
            ms.insert(num);
        } else {
            if (!ms.empty() && num == -1) {
                ms.erase(ms.begin());
            } else if (!ms.empty() && num == 1) {
                auto iter = ms.end();
                iter--;
                ms.erase(iter);
            }
        }
    }

    if (ms.empty()) {
        return {{0, 0}};  // EMPTY
    } else {
        auto end_iter = ms.end();
        end_iter--;
        return {{*end_iter, *ms.begin()}};
    }
}

void output(const vector<pair<int, int>>& results) {
    for (const auto& result : results) {
        if (result.first == 0) {
            cout << "EMPTY" << '\n';
        } else {
            cout << result.first << ' ' << result.second << '\n';
        }
    }
}

int main() {
    fastIO();

    vector<vector<pair<char, int>>> testCases = input();

    for (const vector<pair<char, int>>& commands : testCases) {
        vector<pair<int, int>> results = solve(commands);
        output(results);
    }

    return 0;
}
