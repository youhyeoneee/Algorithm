#include <string>
#include <vector>
#include <cmath>

using namespace std;



int getY(int x, int r, bool isMin)
{
    // y = root(r^2 - x^2)
    
    if (isMin) return ceil(sqrt((long long)r*r - (long long)x*x));
    else return floor(sqrt((long long)r*r - (long long)x*x));
}

long long solution(int r1, int r2) {
  
    long long answer = 0;
    int minY, maxY;
    
    for(int x=1; x<=r2; x++)
    {
        if (x < r1)
        {
            minY = getY(x, r1, true);
        } 
        else 
        {
            minY = 0;
        }
        
        maxY = getY(x, r2, false);
            
        answer += maxY - minY + 1;
    }
    
    return answer * 4;
}