#include <bits/stdc++.h>
using namespace std;

#define inf 1000001;

int N;
int cost[1000][3];

void sol(){
    int ans = INT_MAX;
    int dp[1000][3];

    for(int i = 0; i < 3; i++){
        //초기화
        for(int j = 0; j < N; j++)
            for(int k = 0; k < 3; k++)
                dp[j][k] = inf;

        dp[0][i] = cost[0][i];

        for(int j = 1; j < N; j++){
            for(int k = 0; k < 3; k++){
                dp[j][k] = min(
                    dp[j - 1][(k + 1) % 3] + cost[j][k],
                    dp[j - 1][(k + 2) % 3] + cost[j][k]
                );
            }
        }

        for(int j = 0; j < 3; j++){
            if(j != i)
                ans = min(ans, dp[N - 1][j]);
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            cin >> cost[i][j];

    sol();

    return 0;
}