#include<iostream>
#include<algorithm>

using namespace std;

const int SIZE = 100;
const int MAX = 100;
const int MIN = 1;

int arr[SIZE];
int dumpCnt; 

void input() {
    cin >> dumpCnt;
    for (int i=0; i<SIZE; i++) {
        cin >> arr[i];
    }
}

void dump(int minIdx, int maxIdx) {
    arr[maxIdx]--;
    arr[minIdx]++;
}

int solve() {


    pair<int, int> p;
    int minIdx = 0, maxIdx = SIZE-1;
    for(int i = 0; i < dumpCnt; i++) {

        sort(arr, arr+SIZE);
        dump(minIdx, maxIdx);

        if (arr[maxIdx] - arr[minIdx] <= 1) {
            break;
        }
    }

    sort(arr, arr+SIZE);
    return arr[maxIdx] - arr[minIdx];
}

void output(int test_case) {
    cout << "#" << test_case << " " << solve() << "\n";
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        input();
        output(test_case);
	}

	return 0;
}