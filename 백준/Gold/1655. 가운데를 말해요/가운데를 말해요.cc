#include <iostream>
#include <queue>
#include <deque>

using namespace std;

// 9:40 ~ 10:10

int N; // 1 ~ 100000

priority_queue<int, deque<int>, greater<int>> minHeap;
priority_queue<int, deque<int>, less<int>> maxHeap;

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Solve(int num)
{
    // 1. 최대힙의 크기는 최소 힙의 크기보다 같거나 하나 커야한다.
    if (maxHeap.empty()) maxHeap.push(num); 
    else if (minHeap.size() == maxHeap.size()) maxHeap.push(num); 
    else minHeap.push(num);

    // 2. 최대힙의 최대 원소 <= 최소힙의 최소 원소
    if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())
    {
        int a = maxHeap.top();
        maxHeap.pop();
        int b = minHeap.top();
        minHeap.pop();

        minHeap.push(a);
        maxHeap.push(b);
    }

    cout << maxHeap.top() << "\n";

}

void Input()
{
    cin >> N;

    int num;
    for(int i=0; i<N; i++) 
    {   
        cin >> num;
        Solve(num);
    }
}



int main()
{
    FastIO();
    Input();
    return 0;
}