#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct INFO { //상태 정보
    int rx, ry, bx, by, count;
};
INFO start; //시작 위치

int N, M;
char map[10][11];

int bfs(){
    queue<INFO> q;
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    int visited[10][10][10][10] = { 0, };
    int ans = -1;

    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = 1;

    while(!q.empty()){
        INFO cur = q.front(); q.pop();

        if (cur.count > 10) break;
        if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O'){
            ans = cur.count;
            break;
        }

        for(int i = 0; i < 4; i++){
            int next_rx = cur.rx;
            int next_ry = cur.ry;
            int next_bx = cur.bx;
            int next_by = cur.by;

            //R 이동
            while(1){
                if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O'){
                    next_rx += dx[i]; next_ry += dy[i];
                }
                else {
                    if(map[next_ry][next_rx] == '#'){
                        next_rx -= dx[i]; next_ry -= dy[i];
                    }
                    break;
                }
            }   

            //B 이동
            while(1){
                if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O'){
                    next_bx += dx[i]; next_by += dy[i];
                }
                else {
                    if(map[next_by][next_bx] == '#'){
                        next_bx -= dx[i]; next_by -= dy[i];
                    }
                    break;
                }
            }

            //R, B 겹치면 구슬 하나를 한 칸 뒤로 이동
            if(next_rx == next_bx && next_ry == next_by){
                //두 구슬이 구멍에 빠진 경우 제외
                if (map[next_ry][next_rx] != 'O'){
                    int r_dist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
                    int b_dist = abs(next_bx - cur.bx) + abs(next_by - cur.by);
                    
                    if (r_dist > b_dist){
                        next_rx -= dx[i]; next_ry -= dy[i];
                    } else {
                        next_bx -= dx[i]; next_by -= dy[i];
                    }
                }
            }

            //방문하지 않았다면 방문 처리 및 이동
            if(visited[next_rx][next_ry][next_bx][next_by] == 0) {
                visited[next_rx][next_ry][next_bx][next_by] = 1;
                
                INFO next;
                next.rx = next_rx;
                next.ry = next_ry;
                next.bx = next_bx;
                next.by = next_by;
                next.count = cur.count + 1;
                
                q.push(next);
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    //map 입력
    for(int i = 0; i < N; i++) cin >> map[i];
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 'R'){
                start.rx = j; start.ry = i;
            }

            if(map[i][j] == 'B'){
                start.bx = j; start.by = i;
            }
        }
    }
    start.count = 0;

    cout << bfs() << "\n";

    return 0;
}