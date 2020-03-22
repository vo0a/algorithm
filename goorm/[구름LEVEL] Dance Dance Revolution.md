## [구름LEVEL] Dance Dance Revolution

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | -      |





```c++
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> m;
int n, flg;
int main() {
	scanf("%d", &n);
	for (int i = 0,a,b; i < n; i++) {
		scanf("%d %d", &a, &b);
		m[b]++;
	}
	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > 2) {
			flg = 1; break;
		}
	}
	flg ? printf("0") : printf("1");
	return 0;
}
```





구름LEVEL Dance Dance Revolution goorm goormlevel

