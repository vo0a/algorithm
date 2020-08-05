## [programmers] DFS_BFS, 여행경로

[문제](https://programmers.co.kr/learn/courses/30/lessons/43164)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& tmp, vector<string>& answer, int cnt) {

	tmp.push_back(from);

	if (cnt == tickets.size()) {
		answer = tmp;
		return true;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == from && !visit[i]) {
			visit[i] = true;

			bool success = dfs(tickets[i][1], tickets, visit, tmp, answer, cnt + 1);
			if (success) return true;

			visit[i] = false;
		}
	}

	tmp.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer, tmp;
	vector<bool> visit(tickets.size(), false);

	sort(tickets.begin(), tickets.end());
	dfs("ICN", tickets, visit, tmp, answer, 0);

	return answer;
}
```





프로그래머스 고득점 키트 DFS/BFS 여행경로

