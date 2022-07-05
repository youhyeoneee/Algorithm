#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long A[4000];
long long B[4000];
long long C[4000];
long long D[4000];
vector<long long> AB;
vector<long long> CD;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long start = 0, end = AB.size()-1; //2 pointer
    long long result = 0, sum;
    int before_end;
    while(start < AB.size() && end >= 0){
        sum = AB[start] + CD[end] ;
        if (sum>0) end--; 
        else if (sum == 0){
            // 같은거 세기
            long long ab = 1, cd = 1;
            while (start < AB.size() - 1 && AB[start] == AB[start + 1]) {
                start++;
                ab++;
            }
            while (end > 0 && CD[end] == CD[end-1]) {
                end--;
                cd++;
            }
            result += ab*cd;
            start++;
        }
        else start++;
        
    }

    cout << result << '\n';
    return 0;
}