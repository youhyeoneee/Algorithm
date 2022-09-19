#include <iostream>
#include <string.h>

using namespace std;

int result, N;
int arr[20][20];
int visited[101];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        // INIT 
        result = -1;

        // INPUT 
        cin >> N; // 지역의 한 변의 길이 N

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
            }
        }

        // PROCESS

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){

                // a : 사각형 한 변의 길이
                for(int a=1; a<N; a++){
                    // b : 사각형 또 다른 한 변의 길이
                    for(int b=1; b<N; b++){
                        
                        // 사각형 각 꼭짓점
                        // (i, j) (i+a, j+a) (i+a+b, j+a-b) (i+b, j-b);
                        
                        // 사각형의 오른쪽, 아래, 왼쪽 점이 지도 범위 내에 있는지 체크
                        if (j+a < N && i+a+b < N && j-b >=0){

                            // 더 큰 사각형 발견
                            if (result < 2*(a+b)){  

                                // INIT 
                                bool flag = false;
                                memset(visited, 0, sizeof visited);
                                int x = i;
                                int y = j;

                                // (i, j) -> (i+a, j+a)
                                for(int k=0; k<a; k++){
                                    x++; y++;
                                    
                                    // 방문 처리 
                                    if (!visited[arr[x][y]]) visited[arr[x][y]] = true;
                                    else {flag = true; break;}
                                }
                                if (flag) continue;
     
                                // (i+a, j+a) -> (i+a+b, j+a-b)
                                 for(int k=0; k<b; k++){
                                    x++; y--;
                                    
                                    // 방문 처리 
                                    if (!visited[arr[x][y]]) visited[arr[x][y]] = true;
                                    else {flag = true; break;}

                                }           
                                if (flag) continue;

                                // (i+a+b, j+a-b) -> (i+b, j-b)
                                 for(int k=0; k<a; k++){
                                    x--; y--;
                                    
                                    // 방문 처리 
                                    if (!visited[arr[x][y]]) visited[arr[x][y]] = true;
                                    else {flag = true; break;}

                                }           
                                if (flag) continue;

                                // (i+b, j-b) -> (i, j)
                                 for(int k=0; k<b; k++){
                                    x--; y++;
                                    
                                    // 방문 처리 
                                    if (!visited[arr[x][y]]) visited[arr[x][y]] = true;
                                    else {flag = true; break;}
                                }           
                                if (flag) continue; 

                                // 저장
                                result = 2*(a+b);

                            }
                        }

                    }
                }
            }
        }

        // OUTPUT
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}