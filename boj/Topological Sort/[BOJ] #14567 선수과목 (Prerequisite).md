## [BOJ] #14567 선수과목 (Prerequisite)

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 5 초      | 256 MB      | 71.087%   |

[문제](https://www.acmicpc.net/problem/14567)



| 메모리  | 시간   |
| ------- | ------ |
| 4008 KB | 128 ms |

```c++
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int n, m, indegree[1005], d[1005];
vector<vector<int>> adj;

int main() {	
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	queue<p> q;
	for (int i = 1; i <= n; i++)
		if (!indegree[i]) {
			q.push({ i , 1 });
			d[i] = 1;
		}

	while (!q.empty()) {
		int x = q.front().first;
		int num = q.front().second;
		q.pop();
		for (auto y : adj[x]) {
			d[y] = max(d[y], num + 1);
			if (--indegree[y] == 0) {
				q.push({ y, d[y] });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", d[i]);
	}
	return 0;
}
```





백준 14567 선수과목 (Prerequisite) boj acmicpc

