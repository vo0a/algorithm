## [programmers] DP, 정수 삼각형

[문제](https://programmers.co.kr/learn/courses/30/lessons/43105)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0, dp[505][505] = { 0 }, MAX = 0;

	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]);
			if (answer < dp[i][j]) answer = dp[i][j];
		}
	}

	return answer;
}
```





프로그래머스 고득점 키트 DP 정수 삼각형

