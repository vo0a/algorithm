## [BOJ] #5847 Milk Scheduling

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 128 MB      | 49.438%   |

[문제](https://www.acmicpc.net/problem/5847)



| 메모리  | 시간  |
| ------- | ----- |
| 2864 KB | 20 ms |

```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, time[10005][2], indegree[10005];
vector<vector<int>> adj;
int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i][0]);
		time[i][1] = time[i][0];
	}
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}
	int ans = 0;
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		ans = max(time[num][1], ans);
		for (auto next : adj[num]) {
			time[next][1] = max(time[next][1], time[num][1] + time[next][0]);
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
```

- 여느 다른 위상정렬 문제와 유사했다.
- dp배열을 따로 선언하지 않았고, time을 이차원배열로 선언해서 0번째 행에는 본래 시간, 1번 행에 dp배열에 저장하듯이 `i번째 젖소를 착유하기 위해 걸리는 최소 시간`을 저장해 두었다.



백준 5847 Milk Scheduling boj acmicpc

