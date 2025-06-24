#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int N;
int towers[1001];

int check(){
    int result = 0;

    for(int i = 3; i <= N - 2; i++){
        int curr = towers[i];
        int maxHeight = max(towers[i - 2], max(towers[i - 1], max(towers[i + 1], towers[i + 2])));

        if (maxHeight < curr) result += curr - maxHeight;
    }

    return result;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test_case;
	int T = 1;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        int h;
        
        //입력
        for(int i = 1; i <= N; i++) {
            cin >> h;
            towers[i] = h;
        }

        //정답 확인
        cout << "#" << test_case << " " << check() << "\n";

        //초기화
        for(int i = 1; i <= N; i++){
            towers[i] = 0;
        }
	}

	return 0;
}