#include <bits/stdc++.h>
using namespace std;

int C, N;
pair<int, int> info[20]; //비용, 고객 수
int dp[100001]; //i 비용에서 만들기 위한 인원의 최댓값
int cost_max = 100001;

void sol(){
    for(int i = 1; i < cost_max; i++){
        for(pair<int, int> p: info){
            int cost = p.first;
            int client = p.second;

            if(cost > i) continue;
            
            dp[i] = max(dp[i], dp[i - cost] + client);
        }
    }

    for(int i = 1; i < cost_max; i++){
        if(C <= dp[i]){
            cout << i << "\n";
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> C >> N;

    for(int i = 0; i < N; i++){
        int cost, client;

        cin >> cost >> client;

        info[i] = {cost, client};
    }

    sol();

    return 0;
}