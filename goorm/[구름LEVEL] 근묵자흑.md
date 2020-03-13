## [구름LEVEL] 근묵자흑

| 난이도 | 정답 비율 |
| ------ | --------- |
| ★★     | 61.9%     |





```c++
#include <iostream>
#include <algorithm>
using namespace std;
int input[100000];
int n, k, ans;
int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}
	int idx = 1;
	while (1) {
		if (idx > n)break;
		if (idx == 1) idx += k;
		else idx += k-1;
		ans += 1;		
	}
	printf("%d", ans);
	return 0;
}
```





구름LEVEL 근묵자흑 goorm goormlevel

