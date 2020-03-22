## [구름LEVEL] 제습제

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★    | -      |



프리미엄 알고리즘 위클리 비타알고 시즌3 3주차

```c++
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0, };
int n, ans;
int arr[1005][1005], tarr[1005][1005];
queue<p> cq, nq;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j]) {
				cq.push({ i, j });
			}
		}
	}
	if (cq.size() != n * n) {
		queue<p> q;
		while (1) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j])break;
					else cnt++;
				}
			}
			if (cnt == n * n) break;

			while (!cq.empty()) {
				p front = cq.front();
				cq.pop();
				int x = front.first, y = front.second;
				int flg = 0;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (!arr[nx][ny]) {
						flg = 1; break;
					}
				}
				if (!flg) {
					tarr[x][y] = 1;
					nq.push({ x, y });
				}
			}
			ans++;
			cq = nq;
			nq = q;
			memcpy(arr, tarr, sizeof(arr));
			memset(tarr, 0, sizeof(tarr));
		}
		printf("%d", ans);
	}
	else {
		printf("-1");
	}
	return 0;
}
```



#### 해설 본 후 바꾼 코드

> - queue에 좌표와 함께 **시간**을 저장해두면 queue하나로 문제를 해결할 수 있다.
> - 방문했음을 체크하는 chk배열을 사용하면 매번 배열을 복사하지 않아도 된다. 
>
> - 답이 **0**인 경우, BFS가 진행되지 않았으므로 제습제는 사라질 수 없다.

```c++
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0, };
int n, ans;
int arr[1005][1005], chk[1005][1005];
queue<pair<int, p>> q;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j]) q.push({ 1, { i, j } });
		}
	}
	if (q.size() != n * n) {
		while (!q.empty()) {
			pair<int, p> front = q.front();
			q.pop();
			int d = front.first, x = front.second.first, y = front.second.second;
			ans = max(ans, d);
			int flg = 0;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || chk[nx][ny] == d) continue;
				if (!arr[nx][ny]) {
					chk[x][y] = d;
					arr[x][y] = 0; flg = 1; break;
				}
			}
			if(!flg)q.push({ d + 1, { x, y } });
		}
	}
	printf("%d", ans ? ans : -1);
	return 0;
}
```



구름LEVEL 제습제 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

