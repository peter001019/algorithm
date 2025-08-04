#include <bits/stdc++.h>
using namespace std;

int T, K;
vector<int> input;
int dp[501][501];
int sum[501][501];

void sol(){
    //sum 계산
    for(int i = 1; i <= K; i++){
        sum[i][i] = input[i];

        for(int j = i + 1; j <= K; j++){
            sum[i][j] = sum[i][j - 1] + input[j];
        }
    }

    cout << sum[0][K];

    // for(int len = 1; len < K; len++){
    //     for(int j = 1; len + j <= K; j++){
    //         dp[j][len + j] = INT_MAX;

    //         for(int mid = j; mid < len + j; mid++){
    //             dp[j][len + j] = min(dp[j][len + j], 
    //                 dp[j][mid] + dp[mid + 1][len + j] + sum[j][len + j]);
    //         }
    //     }
    // }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> K;

        int num;
        for(int i = 0; i < K; i++){
            cin >> num;
            input.push_back(num);
        }

        sol();
        input.clear();
    }

    sol();

    return 0;
}  