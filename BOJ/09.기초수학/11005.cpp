#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, B;
    
    vector<int> v;
    
    cin >> N >> B;

    while((N/B)>0){
        v.push_back(N%B);
        N = N/B;
    }
    v.push_back(N%B);

    for(int i=v.size()-1; i>=0; i--){
        if (v[i] >= 10){
            cout << (char)(v[i]+55);
        }
        else
            cout << v[i];
    }
    cout << endl;
    return 0;
}