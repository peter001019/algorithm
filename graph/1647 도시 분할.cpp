#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> edge[100001];
bool visited[100001];
int ans;
int maxDist = -1;

int prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    while(!pq.empty()){
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(visited[node]) continue;
        visited[node] = true;

        ans += dist;
        maxDist = max(maxDist, dist);

        for(int i = 0; i < edge[node].size(); i++){
            int nextNode = edge[node][i].second;
            int nextDist = edge[node][i].first;

            if(visited[nextNode]) continue;
            pq.push({nextDist, nextNode});
        }
    }

    return ans - maxDist;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int A, B, C;
        cin >> A >> B >> C;

        edge[A].push_back({C, B});
        edge[B].push_back({C, A});
    }

    cout << prim();

    return 0;
}

/*
MST를 구하고, 제일 큰 간선을 하나 없앤다.

MST 알고리즘(vlogv)
*/