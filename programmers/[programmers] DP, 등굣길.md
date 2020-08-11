## [programmers] DP, 등굣길

[문제](https://programmers.co.kr/learn/courses/30/lessons/42898)



```c++
#include <string>
#include <vector>
using namespace std;
#define mod 1000000007

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0, dp[105][105] = { 0 };
	
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][0]][puddles[i][1]] = -1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
            if(i == 1 && j == 1) dp[i][j] = 1;
			else if (dp[i][j] == -1) dp[i][j] = 0;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}

	answer = dp[m][n];
	return answer;
}
```



처음에 아래 처럼 풀었다가 많이 틀렸다. 답은 같은데 문제에서 제시한 것 처럼 (m, n) 좌표로 출력하는지 확인하는 것 같다..

```c++
#include <string>
#include <vector>
using namespace std;
#define mod 1000000007

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0, dp[105][105] = { 0 };
	
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][0]][puddles[i][1]] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
            if(i == 1 && j == 1) dp[i][j] = 1;
			else if (dp[i][j] == -1) dp[i][j] = 0;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}

	answer = dp[n][m];
	return answer;
}
```



문제를 잘 읽자!



프로그래머스 고득점 키트 DP 등굣길

