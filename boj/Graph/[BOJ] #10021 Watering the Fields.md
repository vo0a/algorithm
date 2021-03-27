## [BOJ] #10021 Watering the Fields

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 128 MB      | 33.643%   |

[문제](https://www.acmicpc.net/problem/10021)



### 프림

| 메모리   | 시간   |
| -------- | ------ |
| 50424 KB | 488 ms |

```c++
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
typedef long long int ll;
int n, c, cnt;
ll ans;
bool chk[2001];
int main() {
	scanf("%d %d", &n, &c);
	vector<p> arr;
	for (int i = 0, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		arr.push_back({ x, y });
	}
	priority_queue<pair<ll, int>> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		ll num = -q.top().first;
		int x = q.top().second;
		q.pop();
		if (chk[x]) continue;
		chk[x] = true;
		ans += num;
		cnt++;
		for (int i = 0; i < n; i++) {
			if (!chk[i]) {
				int dx = arr[x].first - arr[i].first;
				int dy = arr[x].second - arr[i].second;
				ll cost = dx * dx + dy * dy;
				if (cost < c) continue;
				q.push({ -cost, i });
			}
		}
	}
	printf("%lld", cnt == n ? ans : -1);

	return 0;
}
```

- MST



### 크루스칼

| 메모리   | 시간   |
| -------- | ------ |
| 51204 KB | 584 ms |

```c++
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int from, to;
	long long val;
};
struct cmp {
	bool operator()(info& a, info& b) {
		return a.val > b.val;
	}
};
info tmp;
int x[2001], y[2001], par[2001];

int find_par(int p) {
	if (par[p] == p) return p;
	return par[p] = find_par(par[p]);
}

void make_union(int a, int b) {
	a = find_par(a);
	b = find_par(b);
	if (a > b) par[a] = b;
	else if (a < b) par[b] = a;
}

int main() {
	int n, maxi, conn = 0;
	long long result = 0;
	scanf("%d%d", &n, &maxi);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		par[i] = i;
	}
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long dx = x[i] - x[j];
			long long dy = y[i] - y[j];
			long long v = dx * dx + dy * dy;
			tmp.from = i;
			tmp.to = j;
			tmp.val = v;
			pq.push(tmp);
		}
	}
	while (!pq.empty()) {
		int cf = pq.top().from;
		int ct = pq.top().to;
		long long cv = pq.top().val;
		pq.pop();
		if (cv < maxi) continue;
		int pf = find_par(cf);
		int pt = find_par(ct);
		if (pf == pt) continue;
		make_union(cf, ct);
		result += cv;
		conn++;
		if (conn == n - 1) break;
	}
	if (conn != n - 1) result = -1;
	printf("%lld", result);
	return 0;
}
```





백준 10021 Watering the Fields boj acmicpc

