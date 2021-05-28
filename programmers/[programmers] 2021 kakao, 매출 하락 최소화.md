## [programmers] 2021 kakao, 매출 하락 최소화

[문제](https://programmers.co.kr/learn/courses/30/lessons/72416?language=cpp)



```c++
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1e9

vector<int> Sales;
vector<vector<int>> adj(300000);
int cost[300000][2];

void traversal(int node) {
	cost[node][0] = 0;
	cost[node][1] = Sales[node];

	if (adj[node].empty()) return;

	int extraCost = INF;
	for (auto child : adj[node]) {
		traversal(child);
		if (cost[child][0] < cost[child][1]) {
			cost[node][0] += cost[child][0];
			cost[node][1] += cost[child][0];
			extraCost = min(extraCost, cost[child][1] - cost[child][0]);
		}
		else {
			cost[node][0] += cost[child][1];
			cost[node][1] += cost[child][1];
			extraCost = 0;
		}
	}
	cost[node][0] += extraCost;
}


int solution(vector<int> sales, vector<vector<int>> links) {
	Sales = sales;
	for (auto link : links) {
		adj[link[0] - 1].push_back(link[1] - 1);
	}
	traversal(0);
	return min(cost[0][0], cost[0][1]);
}
```



프로그래머스 2021 kakao, 매출 하락 최소화

