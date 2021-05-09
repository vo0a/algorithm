## [BOJ] #2533 사회망 서비스(SNS)

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 3 초      | 256 MB      | 34.797%   |

[문제](https://www.acmicpc.net/problem/2533)



| 메모리   | 시간    |
| -------- | ------- |
| 76364 KB | 1024 ms |

```c++
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int n, r, q, dp[1000005][2];
vector<vector<int>> adj;

 int go(int now, int parent, int flg) {
	 int& ret = dp[now][flg];
	 if (ret != -1) return ret;
	 ret = flg ? 1 : 0;
	 
	 for (auto next : adj[now]) {
		 if (parent == next) continue;
		 if (flg) { // now가 얼리어 답터면 자식들은 얼리어 답터이거나, 얼리어 답터가 아님
			 ret += min(go(next, now, 0), go(next, now, 1));
		 }
		 else ret += go(next, now, 1);
	}

	 return ret;
}

int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 0, u, v; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));
	int ans = min(go(1, 0, 0), go(1, 0, 1));
	printf("%d", ans);
	return 0;
}
```





백준 2533 사회망 서비스(SNS) boj acmicpc

