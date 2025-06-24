#include <bits/stdc++.h>
using namespace std;

int N, E, v1, v2;
vector<pair<int, int>> graph[801]; //인접 리스트
int dist[801];
int INF = 1e9;

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;

    for(int i = 1; i < N + 1; i++)
        dist[i] = INF;
    
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(dist[curr] < cost) continue;
        
        for(int i = 0; i < graph[curr].size(); i++){
            int n_node = graph[curr][i].second;
            int n_cost = cost + graph[curr][i].first;

            if(n_cost < dist[n_node]){
                dist[n_node] = n_cost;
                pq.push({ -n_cost, n_node });
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> E;

    int a, b, c;

    //그래프 입력
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    /*
    dist1 : start -> v1 -> v2 -> N
    dist2 : start -> v2 -> v1 -> N
    */

    long long int s_v1, s_v2, v1_v2, v2_v1, v1_N, v2_N;

    dijkstra(1);
    s_v1 = dist[v1];
    s_v2 = dist[v2];

    dijkstra(v1);
    v1_v2 = dist[v2];
    v1_N = dist[N];

    dijkstra(v2);
    v2_v1 = dist[v1];
    v2_N = dist[N];

    long long int dist1 = s_v1 + v1_v2 + v2_N;
    long long int dist2 = s_v2 + v2_v1 + v1_N;
    long long int ans = dist1 > dist2 ? dist2 : dist1;

    cout << (ans >= INF ? -1 : ans);

    return 0;
}