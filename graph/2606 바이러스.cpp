#include <bits/stdc++.h>
using namespace std;

int N, connectN;
vector<int> graph[101];
bool visited[101];

void bfs(){
    queue<int> q;
    int ans = 0;

    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        ans++;

        for(int next: graph[v]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << ans - 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> connectN;

    int a, b;
    for(int i = 0; i < connectN; i++){
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    return 0;
}