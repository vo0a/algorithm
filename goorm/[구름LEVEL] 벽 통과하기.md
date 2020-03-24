## [구름LEVEL] 벽 통과하기

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★★   | -      |



프리미엄 알고리즘 위클리 비타알고 시즌3 4주차

```c++
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int n, ans = 1e9;
int dx[] = { 0,1,0, -1 }, dy[] = { 1,0,-1, 0 };
int arr[1005][1005], chk[1005][1005];
priority_queue<pair<int, p>, vector<pair<int, p>>, greater<pair<int, p>>> pq;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	chk[0][0] = 1;
	pq.push({ 1, {0,0} });
	while (!pq.empty()) {
		pair<int, p> front = pq.top();
		pq.pop();
		int time = front.first, x = front.second.first, y = front.second.second;
		if (x == n - 1 && y == n - 1) {
			printf("%d", time - 1);
			break;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || chk[nx][ny]) continue;
			if (arr[nx][ny]) {
				chk[nx][ny] = time;
				pq.push({ time, { nx, ny } });
			}
			else {
				chk[nx][ny] = time + 1;
				pq.push({ time + 1, { nx, ny } });
			}
		}
	}
	return 0;
}
```





구름LEVEL 벽 통과하기 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

