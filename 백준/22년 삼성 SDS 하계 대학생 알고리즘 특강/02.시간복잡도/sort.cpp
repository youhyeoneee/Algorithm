#include <queue>

using namespace std;
// sort 방법

// 1. sort 사용시 import algorithm
// 2. compare 함수에서 return true 시 = 없어야 함 !!
// 3. 첫번째 인자가 두번째 인자보다 "strict weak ordering" 관계에 있어서 앞에 있어야 한다면 return true 그게 아니라면 false
    // 1. For all a, comp(a,a)==false
    // 2. If comp(a,b)==true then comp(b,a)==false
    // 3. if comp(a,b)==true and comp(b,c)==true then comp(a,c)==true
// https://en.cppreference.com/w/cpp/named_req/Compare


// "strict weak ordering" 관계 한글 풀이로도 공유드립니다!

// 1. 비반사성(irreflexivity): 모든 x에 대해 R(x, x)는 거짓
// 2. 비대칭성(asymmetry): 모든 x, y에 대해 R(x, y)가 참이면 R(y, x)는 거짓
// 3. 추이성(transitivity): 모든 x, y, z에 대해 R(x, y)와 R(y, z)가 참이면 R(x, z)는 참
// 4. 비비교성의 추이성(transitivity of incomparability): 모든 x, y, z에 대해 R(x, y)와 R(y, x)가 거짓이고 R(y, z)와 R(z, y)가 거짓이면 R(x, z)와 R(z, x)는 거짓
// 출처: https://panty.run/strict-weak-ordering/
struct Point{
    int i, j;
};
bool cmp(const int &a, const int &b){
    if (a > b) return true;
    return false;
}

int main() {
    int a[5] = { 2,7,4,4,9 };
    sort(a, a + 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    sort(a, a + 5, cmp);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    sort(a, a + 5, greater<int>()); // less
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(9);
    pq.push(5);

    int first = pq.top();
    printf("%d", first);
    printf("\n");
    return 0;
}