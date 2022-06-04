#include <iostream>

using namespace std;

int main(){

    int w, h, b;

    cin >> w >> h >> b;
    
    printf("%.2lf MB", ((double)(w*h*b)/(double)(8*1024*1024)));
    return 0;
}