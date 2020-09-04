## [programmers] 그래프, 가장 먼 노드

[문제](https://programmers.co.kr/learn/courses/30/lessons/49189)



```c++
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
vector<vector<int>> adj;
int chk[20001], maxCnt;
queue<p> q;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	adj.resize(n + 1);

	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i][0], b = edge[i][1];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	q.push({ 1, 0 });
	chk[1] = 1;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (maxCnt == cnt) answer++;

		for (auto child : adj[cur]) {
			if (chk[child]) continue;
			if (cnt + 1 > maxCnt) {
				maxCnt = cnt + 1;
				answer = 0;
			}
			chk[child] = 1;
			q.push({ child, cnt + 1 });
		}
	}

	return answer;
}
```

> 최단 거리로 거리를 세기 때문에 BFS로 풀어야 했다.



프로그래머스 고득점 키트 그래프 가장 먼 노드

