#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];
int dist[1001];
int INF = 1e9;
int before[1001];

int dijkstra(int expNode1, int expNode2){
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i < N + 1; i++) dist[i] = INF;

    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){
        int cur_node = pq.top().second;
        int cur_cost = -pq.top().first;
        pq.pop();

        if (dist[cur_node] < cur_cost) continue;

        for(int i = 0; i < graph[cur_node].size(); i++){
            int dest = graph[cur_node][i].second;
            int via_cost = cur_cost + graph[cur_node][i].first;

            //막아진 간선은 skip
            if((cur_node == expNode1 && dest == expNode2) || (cur_node == expNode2 && dest == expNode1)) continue;

            if (dist[dest] > via_cost) {
                dist[dest] = via_cost;
                pq.push({-via_cost, dest});

                //최단 경로 기록
                if(expNode1 == -1 && expNode2 == -1)
                    before[dest] = cur_node;
            }
        }
    }

    return dist[N];
}

void Solution(){
    int min = dijkstra(-1, -1);
    int ans = -1;

    for(int n = N; n != 1; n = before[n]){
        int result = dijkstra(n, before[n]);
            
        if (result == INF){
            cout << -1;
            return;
        }
        else{
            ans = max(ans, result - min);
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int a, b, t;

    for(int i = 0; i < M; i++){
        cin >> a >> b >> t;

        graph[a].push_back({t, b});
        graph[b].push_back({t, a});
    }

    Solution();

    return 0;
}