## [구름LEVEL] 미로찾기

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★★   | -      |



프리미엄 알고리즘 위클리 비타알고 시즌3 3월 2주차

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int n, arr[1005][1005], chk[1005][1005], warpChk[10];
vector<p> warp[10];
queue<p> q;
void warpPush(int x, int y, int warpNum) {
	warpChk[warpNum] = 1;
	for (auto child : warp[warpNum]) {
		int time = chk[x][y], cx = child.first, cy = child.second;
		if (cx == x && cy == y) continue;
		chk[cx][cy] = time + 1;
		q.push({ cx, cy });
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > 1) {
				warp[arr[i][j]].push_back({ i,j });
			}
		}
	}
	chk[0][0] = 1;
	q.push({ 0, 0 });
	while (!q.empty()) {
		p front = q.front();
		q.pop();
		int x = front.first, y = front.second;
		int time = chk[x][y];
		if (x == n - 1 && y == n - 1) {
			break;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == 1 || chk[nx][ny] || warpChk[arr[nx][ny]]) continue;			
			chk[nx][ny] = time + 1;
			if (arr[nx][ny] > 1) { warpPush(nx, ny, arr[nx][ny]); }
			else q.push({ nx, ny });
		}
	}
	printf("%d", chk[n - 1][n - 1] ? chk[n - 1][n - 1] : -1);
	return 0;
}

```





구름LEVEL 미로찾기 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3 

