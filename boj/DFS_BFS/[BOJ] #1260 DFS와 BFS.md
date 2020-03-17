## [BOJ] #1260 DFS와 BFS

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 2 초      | 128 MB      | 30.405%   |

https://www.acmicpc.net/problem/1260



간선은 양방향이다.

| 메모리   | 시간  |
| -------- | ----- |
| 25568 KB | 20 ms |

```c++
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
#define F(x,y,u,p) for(int x = 0; x<u; x++)for(int y = 0; y<p; y++)
int n, m, start, chk[1005];
vector<vector<int>> v;
void dfs(int start) {
	chk[start] = 1;
	printf("%d ", start);
	for (auto& e : v[start]) {
		if (chk[e]) continue;
		chk[e] = 1;		
		dfs(e);
	}
}
void bfs(int start) {
	queue<int> q;
	q.push(start);
	chk[start] = 1;
	while (!q.empty()) {
		int present = q.front();
		q.pop();
		printf("%d ", present);
		for (auto& e : v[present]) {
			if (chk[e]) continue;
			chk[e] = 1;
			q.push(e);
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &start);
	v.resize(n * n);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	F(i, j, v.size(), v[i].size()) {
		sort(v[i].begin(), v[i].end());
	}	
	dfs(start);
	printf("\n");
	memset(chk, 0, sizeof(chk));
	bfs(start);
	return 0;
}
```





백준 1260 DFS와 BFS boj acmicpc

