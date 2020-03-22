## [구름LEVEL] 경품 추첨

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | -      |



프리미엄 알고리즘 위클리 비타알고 시즌3 2주차

```c++
#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
int n, m;
map<int, int> arr;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0,a; i < n; i++) {
		scanf("%d", &a);
		arr[a]++;
	}
	for (int i = 0, b; i < m; i++) {
		scanf("%d", &b);
		printf("%d ", arr[b]);
	}
	return 0;
}
```





구름LEVEL 경품 추첨 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

