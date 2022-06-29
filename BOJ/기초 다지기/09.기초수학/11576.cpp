#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


void transTenToB(int N, int B){
    vector<int> v;

    while((N/B)>0){
        v.push_back(N%B);
        N = N/B;
    }
    v.push_back(N%B);

    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << ' ';
    }
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, m;

    cin >> A >> B;

    cin >> m;

    int arr[25] = {0,};

    for (int i=m-1; i>=0; i--){
        cin >> arr[i]; 
    }

    // A -> 10진법 
    int ten = 0;

    for (int i=0; i<m; i++){
        ten += pow(A, i) * arr[i];
    }

    // 10진법 -> B
    string result;
    if(B == 10){ 
        result = to_string(ten);
        for(int i=0; i<result.length(); i++){
            cout << result[i] << " ";
        }
    }
    else{
        transTenToB(ten, B);
    }
    cout << '\n';

    return 0;
}