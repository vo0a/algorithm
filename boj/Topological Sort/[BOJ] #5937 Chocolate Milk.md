## [BOJ] #5937 Chocolate Milk

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 128 MB      | 31.944%   |

[문제](https://www.acmicpc.net/problem/5937)



| 메모리 | 시간 |
| ------ | ---- |
| KB     | 0 ms |



## 시도 1

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, indegree[100005], dp[100005][2]; // indegree 수 / 최대유량
vector<vector<int>> adj;
int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 0, a, b; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		indegree[b]++;
		dp[b][0]++;
		adj[a].push_back(b);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i])
			q.push(i);
	}
	int Max = 0;
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		Max = max(Max, dp[num][1]);
		for (auto next : adj[num]) {
			dp[next][1] += dp[num][0];
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	vector<int> ret;
	for (int i = 1; i <= n; i++) {
		if (dp[i][1] == Max) {
			ret.push_back(i);
		}
	}
	sort(ret.begin(), ret.end());
	for (auto e : ret) {
		printf("%d\n", e);
	}
	return 0;
}
```

- 바로 이전 노드의 indegree를 활용하여 구해보려고했는데, 조인트가 되는 부분을 어떻게 판별해야할지 고민이다.. 간선을 지웠을 때 두개의 연결성분으로 나누는 그런 간선을 찾아야하나? 어떻게 찾지 고민



백준 5937 Chocolate Milk boj acmicpc

