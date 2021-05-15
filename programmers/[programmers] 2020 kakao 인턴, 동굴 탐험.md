## [programmers] 2020 kakao 인턴, 동굴 탐험

[문제](https://programmers.co.kr/learn/courses/30/lessons/67260)



```c++
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool answer = true;
int cnt = 0;
void dfs(vector<vector<int>> &adj, vector<int> &discover, vector<bool> &finished, int here) {
	discover[here] = cnt++;

	for (int next : adj[here]) {
		if (discover[next] == -1) {
			dfs(adj, discover, finished, next);
		}
		else if (discover[here] < discover[next]) {
			continue;
		}
		else {
			if (!finished[next]) { // 사이클이 존재
				answer = false; return;
			}
			else continue;
		}
	}
	finished[here] = true;
	return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	vector<vector<int>> adj;
	adj.resize(n);
	for (int i = 0; i < path.size(); i++) {
		adj[path[i][0]].push_back(path[i][1]);
		adj[path[i][1]].push_back(path[i][0]);
	}
	vector<vector<int>> r_adj(n);
	vector<bool> chk(n, false);
	queue<int> q;

	chk[0] = true;
	q.push(0);
	while (!q.empty()) {
		int here = q.front(); q.pop();

		for (auto next : adj[here]) {
			if (chk[next]) continue;

			r_adj[next].push_back(here);

			chk[next] = true;
			q.push(next);
		}
	}

	for (int i = 0; i < order.size(); i++) {
		r_adj[order[i][1]].push_back(order[i][0]);
	}

	// 유일한 입구는 0. 입구를 방문하기 전 먼저 방문해야 하는 방이 있다면 모든 방을 탐험 못함
	if (r_adj[0].size() != 0) return false;

	vector<int> discover(n, -1);
	vector<bool> finished(n, false);
	for (int i = n - 1; i >= 0; i--) {
		if (!answer) break;
		if (finished[i]) continue;
		dfs(r_adj, discover, finished, i);
	}
	return answer;
}

int main() {
	bool v = solution(9, { {0, 1},{0, 3}, {0, 7},{8, 1},{3, 6},{1, 2},{4, 7},{7, 5}}, {{4, 1},{8, 7},{6, 5}} );
	cout << v;

	return 0;
}
```

1. 우리는 먼저 방문해야 하는 노드(방)를 가리키는 트리를 만들고, 순회 할 수 있으면 true, 사이클을 만나면 탐색 불가로 false를 리턴할 것이다. 이러한 목적을 위해 아래의 과정을 거친다.
2. BFS 탐색으로 부모를 확인해야함.
   - 양방향 그래프이고, 입력이 (1, 8) 또는 (8, 1) 로 주어지기 때문에 BFS 탐색으로 부모를 확인해야 함.
   - (노드 i →  i의 부모) 방향의 간선을 사이클 탐색에 사용할 트리(r_adj)에 추가한다. 
3. DFS 탐색으로 사이클이 있는지 확인하여 true or false를 리턴한다.
   - discover, finished 배열을 사용해서, i번 방을 방문했을 때 시각을 discover에 저장하고, i번 방 탐색이 완료되면 finished[i]를 true로 만든다.
   - discover[next]값이 없다면 dfs함수를 호출한다.
   - 만약 next를 방문한 시각(discover[next])이 i를 방문한  시각(discover[i]) 보다 작으면서, finished[next]가 false라면, 사이클이다!
     - 바로 false를 리턴한다.
   - 그 외의 경우에는 올바른 탐색이 가능하다.
     - n-1~0까지 dfs 탐색이 가능한 경우 최종적으로 true를 리턴한다.



프로그래머스 2020 kakao 인턴, 동굴 탐험

