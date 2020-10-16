## [BOJ] #1005 ACM Craft

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 512 MB      | 20.931%   |





| 메모리 | 시간 |
| ------ | ---- |
| KB     | 0 ms |



## 시도 1

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int t, n, m, Find, d, time[1005], chk[1005], ans;
vector<vector<int>> adj;
vector<p> res;
void dfs(int here, int depth) {
	chk[here] = 1;
	for (auto next : adj[here]) {
		if (chk[next]) continue;
		dfs(next, depth + 1);
	}
	if (here == Find) {
		d = depth; ans += time[here];
	}
	res.push_back({ here, depth });
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &time[i]);
		}
		adj.resize(n + 1);
		for (int i = 0,a , b; i < m; i++) {
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}
		scanf("%d", &Find);

		for (int i = 1; i <= n; i++) {
			// 위상정렬
			if (!chk[i]) {
				dfs(i, 0);
			}
		}
		// 위상정렬 결과값으로 최소 시간 구하기		
		// 레벨에서 가장 큰 값을 더해가기
		int level = d, Max = 0;
		for (auto e : res) {
			if (e.second < level) {
				ans += Max;
				Max = time[e.first];
				level = e.second;
			}
			else if (e.second >= d) continue;
			else if (e.second == level) {
				Max = max(Max, time[e.first]);
			}
		}
		ans += Max;

		printf("%d\n", ans);
		ans = 0;
		adj.clear();
		res.clear();
		memset(chk, 0, sizeof(chk));
	}
	
	return 0;
}
```

> 2
> 3 2
> 1 2 3
> 3 2
> 2 1
> 1
> 5 10
> 100000 99999 99997 99994 99990
> 4 5
> 3 5
> 3 4
> 2 5
> 2 4
> 2 3
> 1 5
> 1 4
> 1 3
> 1 2
> 4

위 처럼 DFS를 활용하여 위상정렬 후 최소시간을 구하려고 했더니

1. `3 → 2 → 1` 처럼 되어있으면 답이 틀리게 되는 문제가 발생.
   - 1부터 시작이 아니라, **루트**를 별도로 찾아야 하니까
2. `1 → 5` 같은 경우가 `1 → 2 → 3 → 4 → 5` 보다 먼저 입력 될 때
   - 입력 순서에 따라서 위상정렬 결과값이 달라지는 문제가 발생
   - 이럴바엔 큐를 활용하는게 낫다고 판단
   - 따라서 DFS를 활용한 위상정렬이 아닌, 큐를 활용하여 DFS를 작성해야 겠다.



백준 1005 ACM Craft boj acmicpc

