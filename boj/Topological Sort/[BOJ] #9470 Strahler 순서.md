## [BOJ] #9470 Strahler 순서

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 128 MB      | 39.706%   |

[문제](https://www.acmicpc.net/problem/9470)



| 메모리  | 시간 |
| ------- | ---- |
| 1988 KB | 0 ms |

```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int t, k, m, p, indegree[1005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &k, &m, &p);
		vector<vector<int>> adj(m + 1);
		for (int i = 0, a, b; i < p; i++) {
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			indegree[b]++;
		}
		queue<P> q;
		for (int i = 1; i <= m; i++) {
			if (!indegree[i]) {
				q.push({ i, 1 });
			}
		}
		int strahler[1005][2] = { 0 }, Max = 0;
		while (!q.empty()) {
			int num = q.front().first, seq = q.front().second;
			Max = max(Max, seq);
			q.pop();

			for (auto next : adj[num]) {
				if (strahler[next][0] < seq) {
					strahler[next][0] = seq;
					strahler[next][1] = 1;
				}
				else if (strahler[next][0] == seq)
					strahler[next][1]++;

				if (--indegree[next] == 0) {
					int nseq = strahler[next][1] > 1 ? strahler[next][0] + 1 : strahler[next][0];
					q.push({ next, nseq });
				}
			}
		}
		printf("%d %d\n", k, Max);
	}

	return 0;
}
```





백준 9470 Strahler 순서 boj acmicpc

