#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

// 실버 4
bool compare(double a, double b) {
    return a > b;	
}

int main(){

    int N, M, K;

    cin >> N >> M >> K; // 참가자 수, 장르 수, 본선 진출 수

    double arr[N][M]; // 사람 / 장르 별 점수 저장
    int people;
    double score;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            cin >> people >> score;
            arr[people-1][i] = score;
        }
    }

    for (int i=0; i<N; i++){ // 장르별로 높은 점수 정렬
        sort(arr[i], arr[i]+M, compare);
    }

    vector<double> final;
    for (int i=0; i<N; i++){ // 가장 높은 점수만 골라오기
        final.push_back(arr[i][0]);
    }

    sort(final.begin(), final.end(), compare); // 점수 높은 순 정렬

    double result;
    for (int i=0; i<K; i++){
        result += final[i];
    }

    cout << fixed;
    cout.precision(1);
    cout << result << '\n';

    return 0;
}