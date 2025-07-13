#include <bits/stdc++.h>
using namespace std;

int board[10][10];
vector<pair<int, int>> empty_loc; //채워야 할 자리를 저장

void print(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
}

//해당 위치에 k가 들어갈 수 있는지 검사
bool is_possible(int r, int c, int k){
    for(int i = 1; i <= 9; i++){
        //행 검사
        if(board[r][i] == k && i != c) return false;
        //열 검사
        if(board[i][c] == k && i != r) return false;

        //3 * 3 검사 
        int nr = ((r - 1) / 3) * 3 + 1 + (i - 1) / 3;
        int nc = ((c - 1) / 3) * 3 + 1 + (i - 1) % 3;

        if((board[nr][nc] == k) && (nr != r || nc != c)) return false;

    }
    
    return true;
}

//빈 위치를 재귀적으로 저장 
void backtracking(int start){
    if(start == empty_loc.size()){
        print();
        exit(0);
    }

    int r = empty_loc[start].first;
    int c = empty_loc[start].second;

    for(int i = 1; i <= 9; i++){
        if(is_possible(r, c, i)){
            board[r][c] = i;
            backtracking(start + 1);
            board[r][c] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int i = 1; i <= 9; i++){
        string line;
        cin >> line;

        for(int j = 1; j <= 9; j++){
            int num = line[j - 1] - '0';
            board[i][j] = num;

            if(num == 0) empty_loc.push_back({i, j});
        }
    }

    backtracking(0);

    return 0;
}