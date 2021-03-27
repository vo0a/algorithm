## [programmers] 2020 kakao 인턴, 경주로 건설

[문제](https://programmers.co.kr/learn/courses/30/lessons/67259)



```c++
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
struct Car {
	int r, c, dir, cost;
};

int solution(vector<vector<int>> board) {
	int n = board.size();
	queue<Car> q;
	q.push({ 0, 0, -1, 0 });
	board[0][0] = 1;

	while (!q.empty()) {
		Car car = q.front();
		q.pop();

		int cost = car.cost;

		for (int i = 0; i < 4; i++) {
			int nr = car.r + dx[i];
			int nc = car.c + dy[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n || board[nr][nc] == 1) continue;

			int ncost = cost;
			if (car.dir == -1 || car.dir == i) ncost += 100;
			else ncost += 600;

			if (board[nr][nc] == 0 || board[nr][nc] >= ncost) {
				q.push({ nr, nc, i, ncost });
				board[nr][nc] = ncost;
			}
			
		}
	}
	return board[n - 1][n - 1];
}
```

- DFS 돌리면 시간초과가 나고
- BFS를 돌릴때도 유의할 점이 있다.
  - 구조체가 아닌 pair<int, pair<int, int>> 타입으로 BFS돌리면 무조건 틀림... 
  - 계속 왜 틀리는지 이해를 못해서 끈질기게 붙잡았는데 결국은 나머지 코드는 동일하게 두고, 자료형을 구조체로 바꾸니 정답이 됐다.
  - 이해가 안된다....

### 틀렸던 DFS, BFS

```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int chk[30][30] = { 0 }, ans = 12501;
void dfs(int r, int c, vector<vector<int>>& board,  int straight, int corner, int dir ) {
	if (r == board.size() - 1 && c == board.size() - 1) {
		ans = min(ans, straight * 100 + corner * 500); 
		return;
	}
	chk[r][c] = 1;
	for (int k = 0; k < 4; k++) {
		int nr = r + dx[k], nc = c + dy[k];
		if (nr < 0 || nc < 0 || nr >= board.size() || nc >= board.size()) continue;
		if (chk[nr][nc] || board[nr][nc]) continue;
		int flg = 0;
		if (dir != -1 && dir != k) flg = 1;
		dfs(nr, nc, board, straight + 1, corner + flg, k);
		chk[nr][nc] = 0;
	}
}

int solution(vector<vector<int>> board) {
	dfs(0, 0, board, 0, 0, -1);
	return ans;
}
```

```c++
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int dist[30][30];
const int Max = 1000000;
int solution(vector<vector<int>> board) {
	queue<pair<int, pair<int, int>>> q;
	int n = board.size();
	q.push({ -1, {0, 0 } });	
	fill(&dist[0][0], &dist[29][30], Max);
	dist[0][0] = 0;
	while (!q.empty()) {
		int dir = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cost = dist[x][y];
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nr = x + dx[k], nc = y + dy[k];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
			if (board[nr][nc]) continue;
			int val = 100;
			if (dir != -1 && dir != k && dir != (k + 2) % 4) val += 500;
			if (dist[nr][nc] < cost + val) continue;
			dist[nr][nc] = cost + val;
			q.push({ k, {nr, nc}});
		}
	}	
	return dist[n-1][n-1];
}
```





프로그래머스 2020 kakao 인턴, 경주로 건설

