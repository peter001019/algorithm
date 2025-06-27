#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
int n, d, c;
vector<pair<int, int>> graph[10001];
int dist[10001];
int INF = 1e9; //최대값이 아닐수도, 이따가 디버깅

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i < n + 1; i++) dist[i] = INF;

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_cost = -pq.top().first;
        pq.pop();

        if(dist[cur] < cur_cost) continue;
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int via_cost = cur_cost + graph[cur][i].second;
        
            if(via_cost < dist[next]){
                dist[next] = via_cost;
                pq.push({-via_cost, next});
            }
        }
    }
}

void solution(){
    dijkstra(c);
    int time = -1;
    int num = 0;

    for(int i = 1; i < n + 1; i++){
        if(dist[i] != INF){
            num += 1;
            time = max(time, dist[i]);
        }  
    }

    cout << num << " " << time << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> n >> d >> c;
        int a, b, s;

        for(int j = 0; j < d; j++){
            cin >> a >> b >> s;

            graph[b].push_back({a, s});
        }

        solution();

        for(int k = 1; k < n + 1; k++){
            graph[k].clear();
        }
    }

    return 0;
}