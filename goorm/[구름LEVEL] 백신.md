## [구름LEVEL] 백신

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★    | -      |



프리미엄 알고리즘 위클리 비타알고 시즌3 1주차

```c++
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
int n, m, maxNum, maxCnt, cnt;
int chk[200005];
void dfs(int num) {
	for (auto child: v[num]) {
		if (!chk[child]) {
			cnt++;
			chk[child] = 1;
			dfs(child);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	v.resize(n+1);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			cnt = 1;
			chk[i] = 1;
			dfs(i);
			if (maxCnt < cnt) {
				maxCnt = cnt;
				maxNum = i;
			}
		}
	}
	printf("%d %d", maxNum, maxCnt);
	return 0;
}

```





구름LEVEL 백신 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

