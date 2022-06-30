#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &a){
    
	long long ans = 0;
    for(int i : a)
        ans += i;
    return ans;
}