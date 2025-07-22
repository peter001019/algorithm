#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[32001];
int indegree[32001];

void bfs(){
    queue<int> q;

    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        cout << v << " ";

        for(int n : graph[v]){
            indegree[n]--;

            if(indegree[n] == 0) q.push(n);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int A, B;
    for(int i = 0; i < M; i++){
        cin >> A >> B;

        graph[A].push_back(B);
        indegree[B]++;
    }

    bfs();

    return 0;
}