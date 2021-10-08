## [programmers] 위클리 챌린지, 9주차_전력망을 둘로 나누기

[문제](https://programmers.co.kr/learn/courses/30/lessons/86971)



```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

// 2차원 adj 만들고, 간선하나씩 끊어보면서 dfs 로 갯수 세고, min값 저장하기
// 양방향 간선으로 만들거니까, 애초에 adj를 만들 때 부터
int chk[101];
int dfs(vector<vector<int>>& adj, int x) {
	int ret = 1;
	chk[x] = 1;
	for (auto e : adj[x]) {
		if (chk[e]) continue;
		ret += dfs(adj, e);
	}
	return ret;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = 101;

	for (int k = 0; k < wires.size(); k++) {
		int V = wires[k][0], U = wires[k][1];
		// 그래프 만들기
		vector<vector<int>> adj(n + 1);
		for (int i = 0; i < wires.size(); i++) {
			if (i == k) continue;
			int x = wires[i][0], y = wires[i][1];
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		// 갯수 세기
		memset(chk, 0, sizeof(chk));
		int cntV = dfs(adj, V);
		int cntU = dfs(adj, U);
		answer = min(answer, abs(cntV - cntU));
	}

	return answer;
}
```

- n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있다. 이때, 전선들 중 하나를 끊어서 네트워크를 2개로 분할하는데 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞추고자 한다.
- n이 최대 100이기 때문에 n^3도 가능하다는 판단이 들어서 바로 풀 수 있었다.
- 1~n개 까지의 전선을 제거한다고 가정하고 for문을 하나 세우고, 그 내부에서 2중 for문을 돌면서 인접리스트를 만들고, 만들어진 인접리스트를 활용해서 분리된 네트워크의 송전탑 개수를 센다. 이때 분할된 네트워크의 송전탑 개수의 차의 최소가 정답이 된다.



프로그래머스 위클리 챌린지, 9주차_전력망을 둘로 나누기

