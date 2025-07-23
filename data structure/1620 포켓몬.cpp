//10:40

#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<int, string> itostr;
unordered_map<string, int> strtoi;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    string input;
    for(int i = 1; i <= N; i++){
        cin >> input;

        itostr.insert({i, input});
        strtoi.insert({input, i});
    }

    for(int i = 0; i < M; i++){
        cin >> input;

        if(isdigit(input[0])){
            cout << itostr[stoi(input)] << "\n";
        }
        else{
            cout << strtoi[input] << "\n";
        }
    }

    return 0;
}

/*
N < 10만
M < 10만

20 바이트 * 10만 = 200만 바이트, 

int -> string arr
str -> int arr

400만 바이트 < 256 MB = 256 * 10 ^ 6 byte
*/