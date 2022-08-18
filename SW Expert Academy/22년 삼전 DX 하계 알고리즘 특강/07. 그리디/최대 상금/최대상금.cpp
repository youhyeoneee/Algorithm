#include<bits/stdc++.h>
using namespace std;
string a;
int ret, n, T;
void go(int here, int _n){
    if(_n == 0){
        cout << a << "\n";
        ret = max(ret, atoi(a.c_str()));
        return;
    }
    for(int i = here; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            if(a[i] < a[j]){
                swap(a[i], a[j]);
                go(i, _n - 1);
                swap(a[i], a[j]);
            }
        }
    }
    if(_n % 2 == 0) ret = max(ret, atoi(a.c_str()));
    else{
        for(int i = 0; i < a.size(); i++){
            for(int j = i + 1; j < a.size(); j++){
                swap(a[i], a[j]);
                ret = max(ret, atoi(a.c_str()));
                swap(a[i], a[j]);
            }
        }
    }

    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> a >> n;
        ret = 0;
        go(0, n);
        cout << "#" << t << " " << ret << "\n";
    }
    return 0;
}