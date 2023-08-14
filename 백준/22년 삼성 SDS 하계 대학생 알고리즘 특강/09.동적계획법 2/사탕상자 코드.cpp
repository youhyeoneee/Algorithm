// 사탕상자 문제의 주요 코드입니다.
// Indexed Tree 의 기본 개념이 들어간 코드이므로 자세한 설명은 생략하겠습니다.

const int BASE = 1048576; // 2의 20제곱 : 사탕의 맛의 레벨 1~100만
const int TSIZE = 2097152; // 2의 21제곱

int N, A, B, C;
int iTree[TSIZE];  // 사탕의 총 개수 20억 이하 (따라서 int로 커버 가능)

// in main function

if (A == 1) { // 사탕상자 안에서 B번째로 맛있는 사탕을 한개 꺼내어 그 맛의 레벨을 출력.
    int index = 1;
    while (index < TSIZE) {
        if (B > iTree[index]) B -= iTree[index++];
        index *= 2;
    }
    B = index / 2 - BASE;
    // 이 상태에서 B를 출력한다.
    C = -1; // 출력 후에도 그 사탕을 상자에서 하나 빼야 하므로 다음 작업 준비.
}
// 사탕 넣거나 빼기 작업
B += BASE;
while (B) {
    iTree[B] += C;
    B /= 2;
}
