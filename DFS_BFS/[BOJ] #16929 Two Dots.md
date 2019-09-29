## [BOJ] #16929 Two Dots

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 2 초      | 512 MB      | 50.417%   |

https://www.acmicpc.net/problem/16929



testcase 1

```
3 4
AAAA
ABCA
AADA
```

출력 No



| 메모리  | 시간 |
| ------- | ---- |
| 1132 KB | 0 ms |

```c++
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
char arr[55][55];
int chk[55][55];
int n, m;
void dfs(int r, int c, int cnt, int dontgodir) {
	if (cnt >= 4 && chk[r][c]) {
		printf("Yes"); 
		exit(0);
	}
	chk[r][c] = 1;
	char C = arr[r][c];
	for (int i = 0; i < 4; i++) {
		if (dontgodir == i) continue;
		int nr = r + dx[i], nc = c + dy[i];
		if (arr[nr][nc] == C && nr >= 0 && nr < n && nc >= 0 && nc < m) {
			dfs(nr, nc, cnt + 1, (i + 2) % 4);
			chk[nr][nc] = 0;
		}
	}
	return;
}
int main(){	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, 0, -1);
			chk[i][j] = 0;
		}
	}
	printf("No");
	return 0;
}
```



실버 3 이라서 조금 겁을 먹었는데 술술풀려서 놀랐던 문제다. 
기존 그래프의 사이클 문제와는 다르게 변을 공유해야하는 조건이 추가되어 생각을 해보니, 이전에 왔던 방향으로 다시 탐색을 못하게끔 구현을 하면 되겠다 싶어 구현해보니 의외로 매개변수 하나만 추가하고 반복문에 조건 하나만 넣으면 되어 쉽게 풀 수 있었다.

그리고 항상 nr, nc 변수를 지역변수로 선언하다가 전역변수로 선언해보면 어떨까 싶어서 전역변수로 했다가 chk배열 체크를 푸는 과정이 생각대로 잘 되지 않는 문제가 생겨서 다시 지역변수로 바꿨더니 잘 해결되었다.

이 문제의 핵심이었던 DFS는 제대로 잘 구현이 되었지만 체크를 푸는 과정에서 시행착오가 있어 생각보다 쉬웠지만 오래걸렸던 문제이다.



백준 16929 Two Dots boj acmicpc

