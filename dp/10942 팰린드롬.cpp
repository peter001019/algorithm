#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[2001];
bool dp[2001][2001];
vector<pair<int, int>> question;

void sol(){
    //i == j 초기화
    for(int i = 1; i <= N; i++)
        dp[i][i] = true;
    //i == j - 1 초기화
    for(int i = 1; i < N; i++)
        if(num[i] == num[i + 1]) dp[i][i + 1] = true;
    //팰린드롬 찾기
    for(int i = N - 2; i >= 1; i--)
        for(int j = i + 2; j <= N; j++)
            if(dp[i + 1][j - 1] && num[i] == num[j])
                dp[i][j] = true;

    for(pair<int, int> p : question){
        int s = p.first;
        int e = p.second;

        cout << dp[s][e] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> num[i];
    
    cin >> M;
    
    int s, e;
    for(int i = 0; i < M; i++){
        cin >> s >> e;

        question.push_back({s, e});
    }

    sol();

    return 0;
}


/*
dp -> 

  1 2 3 4 5 6 7 
1 o x o x x x o
2   o x x x o x
3     o x o x x
4       o x x x
5         o x o
6           o x
7             o

1 2 2 1

1. 초기값 : i == j -> palindrom, i != j -> 아님, 같으면 마찬가지로
2. 사잇값이 팰린드롬이면 그 바깥 글자가 같은 경우에 팰린드롬
dp[i][j]가 palindrome이려면, arr[i] == arr[j] && dp[i - 1][j + 1] == true



팰린드롬 검사?
-> N(양 끝을 비교)

수열의 크기 2000

팰린드롬 검사 * M(100만) = O(2000 * 100만)
*/