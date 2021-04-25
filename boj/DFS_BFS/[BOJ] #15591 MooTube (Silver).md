## [BOJ] #15591 MooTube (Silver)

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 2 초      | 512 MB      | 46.552%   |

[문제](https://www.acmicpc.net/problem/15591)



| 메모리    | 시간   |
| --------- | ------ |
| 100396 KB | 524 ms |

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 1000000000
int N, Q, dist[5005][5005];
vector<vector<int>> adj;
bool chk[5005];

int dfs(int v, int cur, int k) {
	chk[v] = true;
	int ret = 0;
	for (auto next : adj[v]) {
		if (!chk[next] && min(cur, dist[v][next]) >= k) {
			ret += dfs(next, min(cur, dist[v][next]), k) + 1;
		}
	}
	chk[v] = false;
	return ret;
}

int main() {
	scanf("%d%d", &N, &Q);
	adj.resize(N + 1);
	for (int i = 1, a, b, c; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(b);
		adj[b].push_back(a);
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (int i = 0, k, v; i < Q; i++) {
		scanf("%d%d", &k, &v);
		memset(chk, false, sizeof(chk));
		printf("%d\n", dfs(v, MAX, k));
	}
	return 0;
}
```





백준 15591 MooTube (Silver) boj acmicpc

