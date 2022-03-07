#include <iostream>

using namespace std;


int main(){
    int N, cnt = 0;
    cin >>  N;

    int dp[]
    while(N > 1){
        cout << N << " -> ";  
        cnt += 1;
        if(is_2N_or_3N(N-1)){ // 1뺐을 때 2의 배수 혹은 3의 배수인 경우
            N -=1;
        }
        else{
            if(N%2 == 0) { // 2의 배수인 경우
                N /= 2;
            }
            else if(N%3 == 0) { // 
                N /= 3;
            }
            else{ // 2의 배수도 3의 배수도 아닌 경우 
                N -= 1;
            }
        }
    }

    cout << "\n" << cnt;

    return 0;
}

