#include <iostream>

using namespace std;

int main(){
    char dot;
    int y, m, d;

    cin >> y >> dot >> m >> dot >> d;
    printf("%04d.%02d.%02d", y,m,d);

    return 0;
}