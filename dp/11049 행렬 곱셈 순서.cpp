#include <bits/stdc++.h>
using namespace std;

int N;
int input[501][2];
int dp[501][501];

void sol(){
    for(int len = 1; len < N; len++){ //구간 간격 len
        for(int i = 1; i <= N - len; i++){ //i 행렬부터
            int j = i + len; //j 행렬까지의 곱
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++){ //중간 지점 k
                dp[i][j] = min(dp[i][j], 
                    dp[i][k] + dp[k + 1][j] + input[i][0] * input[k][1] * input[j][1]);
            }
        }
    }

    cout << dp[1][N];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
 
    int r, c;
    for(int i = 1; i <= N; i++){
        cin >> r >> c;

        input[i][0] = r;
        input[i][1] = c;
    }

    sol();

    return 0;
}