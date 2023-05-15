#include <iostream>

using namespace std;

int main () {

    int arr[10][10];

    int max = -1;
    int r, c;

    for(int i=1; i<10; i++) 
    {
        for(int j=1; j<10; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] > max)
            {
                r = i;
                c = j;
                max = arr[i][j];
            }

        }
    }

    cout << arr[r][c] << '\n' << r << ' ' << c;
}