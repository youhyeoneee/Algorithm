#include <iostream>

using namespace std;

int getGcd(int a, int b) {
    if (a%b==0) return b;
    return getGcd(b, a%b);
}

long long solution(int w, int h) {
    
    // 최대공약수
    int gcd = (w > h)? getGcd(w, h) : getGcd(h, w);
        
    int minW = w / gcd;
    int minH = h / gcd;
    
    long long deleted = (long long) minW * (long long) minH;
    
    for(int x=1; x<minW; x++) {
        long long y = ((double) minH * x)/minW;
        deleted -= (long long) y * 2;
    }
        
    long long answer = (long long)w * h;
    answer -= deleted * gcd;
        
    return answer;
}