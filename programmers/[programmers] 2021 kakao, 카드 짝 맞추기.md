## [programmers] 2021 kakao, 카드 짝 맞추기

[문제](https://programmers.co.kr/learn/courses/30/lessons/72415)



```c++
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1e9

struct Point {
	int x, y, cnt;
};
vector<vector<int>> Board;
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// 조작횟수 구하기
int bfs(Point src, Point dst) {
	bool chk[4][4] = { false };
	queue<Point> q;
	q.push(src);
	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.x == dst.x && curr.y == dst.y) 
			return curr.cnt;

		for (int i = 0; i < 4; i++) {
			int nx = curr.x + d[i][0], ny = curr.y + d[i][1];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
			if (!chk[nx][ny]) {
				chk[nx][ny] = true;
				q.push({ nx, ny, curr.cnt + 1 });
			}
			// 이미 한 칸 이동해서 최대 2칸 이동 가능
			for (int j = 0; j < 2; j++) {
				if (Board[nx][ny]) break;
				if (nx + d[i][0] < 0 || ny + d[i][1] < 0 || nx + d[i][0] >= 4 || ny + d[i][1] >= 4) break;
				nx += d[i][0];
				ny += d[i][1];
			}
			if (!chk[nx][ny]) {
				chk[nx][ny] = true;
				q.push({ nx, ny, curr.cnt + 1 });
			}
		}
	}
	return INF;
}

// 조작횟수 반환
int permutate(Point src) {
	int ret = INF;
	for (int num = 1; num <= 6; num++) {
		vector<Point> card;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (Board[i][j] == num) {
					card.push_back({ i, j, 0 });
				}
			}
		}
		// 이미 제거된 경우
		if (card.empty()) continue;
		// 이동 거리 + Enter(2회)
		int one = bfs(src, card[0]) + bfs(card[0], card[1]) + 2; 
		int two = bfs(src, card[1]) + bfs(card[1], card[0]) + 2;

		// 제거
		for (int i = 0; i < 2; i++) {
			Board[card[i].x][card[i].y] = 0;
		}
		// 제거된 상태로 재귀호출
		ret = min(ret, one + permutate(card[1])); 
		ret = min(ret, two + permutate(card[0]));
		// 복원
		for (int i = 0; i < 2; i++) {
			Board[card[i].x][card[i].y] = num;
		}		
	}
	if (ret == INF) return 0;
	return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
	Board = board;
	return permutate({ r, c, 0 });
}
```



프로그래머스 2021 kakao, 카드 짝 맞추기

