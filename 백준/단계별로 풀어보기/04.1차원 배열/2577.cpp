#include <iostream>
#include <string>

using namespace std;

int main(){

    int A, B, C;

    int count[10] = {0,};

    cin >> A;
    cin >> B;
    cin >> C;

    string result = to_string(A*B*C);

    for (char ch : result) {		// 문자열의 문자들을 하나씩 꺼내온다. (foreach문 활용)
		// 문자를 숫자로 변환한 값의 인덱스를 1 증가시킨다.
		count[ch - '0']++;
	}

    for(int v:count)
        cout << v << '\n';
    return 0;
}