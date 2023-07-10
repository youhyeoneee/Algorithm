#include <iostream>
#include <algorithm>
#define SIZE 9
using namespace std;

int arr[SIZE];

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<SIZE; i++)
        cin >> arr[i];
}

void Solve1()
{
    // 정렬
    sort(arr, arr + SIZE);

    // 순열 
    do {
        int sum = 0;
        for (int i=0; i<7; i++) sum += arr[i];
        if (sum == 100)
            break;
    } while(next_permutation(arr, arr + SIZE));

    for(int i=0; i<7; i++)
        cout << arr[i] << " ";
}

void Solve2()
{
    // 전체 합에서 2개를 뺐을 때 100이 되는 것 고르기

    //  1. 전체 합 
    int sum = 0;
    for(int i=0; i<SIZE; i++) sum += arr[i];

    int A, B;
    // 2. 2개 고르기
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<i; j++)
        {
            if (sum - arr[i] - arr[j] == 100)
            {
                A = arr[i];
                B = arr[j];
                break;
            }
        }
    }

    // 정렬
    sort(arr, arr+SIZE);

    // 2개 제외 출력
    for(int i=0; i<SIZE; i++)
    {
        if (arr[i] == A || arr[i] == B)
            continue;
        else 
            cout << arr[i] << " ";
    }
}


void makePermutation(int n, int r, int depth)
{
    if (depth == r)
    {
        int sum = 0;
        for(int i=0; i<7; i++) sum += arr[i];

        if (sum == 100)
        {
            sort(arr, arr+7);
            for(int i=0; i<7; i++)
                cout << arr[i] << " ";
        
            exit(0);
        }

        return;            
    }

    for(int i=depth; i<n; i++)
    {
        swap(arr[i], arr[depth]);
        makePermutation(n, r, depth+1);
        swap(arr[i], arr[depth]);
    }
}

void Solve3()
{
    // 9P7
    makePermutation(SIZE, 7, 0);



}
int main()
{

    Input();
    // Solve1();
    // Solve2();
    Solve3();

    return 0;
}