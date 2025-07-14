#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1001][1001];

void sol(){
    for(int i = 1; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    //LCS 찾기
    int i = s1.length(), j = s2.length();
    string ans = "";
    int cnt = 0;

    while(i != 0 && j != 0){
        if(dp[i][j] == dp[i - 1][j])
            i -= 1;
        else if(dp[i][j] == dp[i][j - 1])
            j -= 1;
        else{
            cnt += 1;
            ans += s1[i - 1];
            i -= 1;
            j -= 1;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << cnt << "\n";
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> s1;
    cin >> s2;

    sol();

    return 0;
}