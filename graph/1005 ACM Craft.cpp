#include <bits/stdc++.h>
using namespace std;

int T, N, K, W;
int D[1001];
vector<int> graph[1001];
int indegree[1001];
int dp[1001]; //i번째 빌딩을 짓는데 걸리는 최소 시간 = 선행되는 모든 건물이 지어지는 시간

void bfs(){
    queue<int> q;
    
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0) {
            dp[i] = D[i];
            q.push(i);
        }
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i: graph[v]){
            dp[i] = max(dp[i], dp[v] + D[i]);

            indegree[i]--;

            if(indegree[i] == 0) q.push(i);
        }
    }

    cout << dp[W] << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    cin >> T;
    
    for(int i = 0; i < T; i++){
        //reset
        for(int i = 1; i <= N; i++){
            D[i] = 0;
            graph[i].clear();
            indegree[i] = 0;
            dp[i] = 0;
        }

        cin >> N >> K;

        for(int j = 1; j <= N; j++) cin >> D[j];
        for(int k = 0; k < K; k++){
            int x, y;
            cin >> x >> y;

            graph[x].push_back(y);
            indegree[y]++;
        }

        cin >> W;

        bfs();
    }

    return 0;
}