#include <iostream>

using namespace std;

int arr[101][101];

void init()
{
    for(int i=1; i<101; i++)
    {
        for(int j=1; j<101; j++)
        {
            arr[i][j] = 0;
        }
    }
}


int main ()
{
    int cnt;
    int width = 0;
    int w, h;

    init();

    cin >> cnt; 

    for(int i=0; i<cnt; i++)
    {
        cin >> w >> h;
        for(int j=h; j<h+10; j++)
        {   
            for(int k=w; k<w+10; k++)
            {
                if (arr[j][k] == 0)
                {
                    width++;
                    arr[j][k] = 1;
                }
            }
        }
    }
    
    cout << width << '\n';

    return 0;
}

