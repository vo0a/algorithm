## [programmers] 2021 kakao, 합승 택시 요금

[문제](https://programmers.co.kr/learn/courses/30/lessons/72413#qna)



## 플루이드 와샬

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e8
int dist[205][205];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (auto v : fares) {
		dist[v[0]][v[1]] = v[2];
		dist[v[1]][v[0]] = v[2];
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
	}
	return answer;
}
```

## 다익스트라(실패)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1e8
vector<pair<int, int>> adj[201];

vector<int> dijkstra(int start, int n) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();
		int cur = front.second;
		int cost = -front.first;

		for (auto e : adj[cur]) {
			int next = e.first;
			int ncost = e.second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
	return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;

	for (int i = 0; i < fares.size(); i++) {
		adj[fares[i][0]].push_back({ fares[i][1], fares[i][2] });
		adj[fares[i][1]].push_back({ fares[i][0], fares[i][2] });
	}

	for (int i = 1; i <= n; i++) {
		vector<int> d = dijkstra(i, n);
		answer = min(answer, d[s] + d[a] + d[b]);
	}

	return answer;
}

int main() {
	printf("%d", solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5,6,2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} }) );
	return 0;
}
```

- 효율성 테스트 7,8 번 두 개만 시간초과
- [질문하기 탭](https://programmers.co.kr/questions/15987)에서 이 문제는 N이 최대 200이고, 다익스트라시 최악의 경우, N*ElogN  이걸리는데 대략 3 * 10^7이라서 언어별로 시간초과가 날 수 있다고 한다.
- 반면, 플루이드 와샬같은 경우에는 N^3이므로 8*10^6 이 걸린다. 따라서 다익스타로 시간초과가 난다면 플루이드 와샬로 문제를 풀어보는 것을 고려할 수 있다. 



프로그래머스 2021 kakao, 합승 택시 요금

