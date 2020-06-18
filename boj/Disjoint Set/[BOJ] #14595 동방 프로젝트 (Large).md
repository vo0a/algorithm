## [BOJ] #14595 동방 프로젝트 (Large)

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 512 MB      | 44.499%   |

[문제](https://www.acmicpc.net/problem/14595)





| 메모리  | 시간  |
| ------- | ----- |
| 5892 KB | 12 ms |

```c++
#include <iostream>
#define MAX_SIZE 1000005

int parent[MAX_SIZE], n, m, ans;
int Find(int x) {
	if (parent[x] < 0) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;

	parent[y] += parent[x];
	parent[x] = y;	
}


int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		parent[i] = -1;
	}
	
	ans = n;
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d %d", &a, &b);
		while (Find(a) != Find(b)) {
			ans--;
			int next = Find(a) + 1;
			Union(a, b);
			a = next;
		}
	}

	printf("%d\n", ans);
	return 0;
}
```



### 반대로

Union 합집합 작업을 x 를 루트로 하면

```c
#include <iostream>
#define MAX_SIZE 1000005

int parent[MAX_SIZE], n, m, ans;
int Find(int x) {
	if (parent[x] < 0) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;

	parent[x] += parent[y];
	parent[y] = x;
}


int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		parent[i] = -1;
	}

	ans = n;
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d %d", &a, &b);
		while (Find(a) != Find(b)) {
			ans--;
			int next = Find(b) - 1;
			Union(a, b);
			b = next;
		}
	}

	printf("%d\n", ans);
	return 0;
}
```





백준14595 동방 프로젝트 (Large) boj acmicpc

