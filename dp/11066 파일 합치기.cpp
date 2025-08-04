#include <bits/stdc++.h>
using namespace std;

int T, K;
int input[501];
int dp[501][501];
int sum[501];

void sol(){
    for(int len = 1; len < K; len++){
        for(int j = 1; len + j <= K; j++){
            dp[j][len + j] = INT_MAX;

            for(int mid = j; mid < len + j; mid++){
                dp[j][len + j] = min(dp[j][len + j], 
                    dp[j][mid] + dp[mid + 1][len + j] + sum[j + len] - sum[j - 1]);
            }
        }
    }

    cout << dp[1][K] << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> K;

        for(int j = 1; j <= K; j++){
            cin >> input[j];
            sum[j] = sum[j - 1] + input[j];
        }

        sol();
    }

    return 0;
}  