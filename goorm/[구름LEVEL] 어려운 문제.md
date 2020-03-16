## [구름LEVEL] 어려운 문제

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | 69.5%  |





```c++
#include <iostream>
#include <vector>
using namespace std;
int n, i, j, r, ans;
vector<int> v;
int main() {
	scanf("%d", &n);
	v.push_back(1);
	for (i = 2; i <= n; i++) {
		j = 0;
		while (!v[j]) j++;
		for (r = 0 ; j < v.size(); j++) {
			r += v[j] * i; // r = v[j] * i + r;
			v[j] = r % 10; // push_back()하면 무한루프.
			r /= 10;
		}
		while (r) {
			v.push_back(r % 10);
			r /= 10;
		}
	}

	for (i = 0, r = 0; i < v.size(); i++) {
		if (!v[i]) continue;
		r += ans + v[i];
		ans = r % 10;
		r /= 10;
	}
	while (r) {
		ans += r % 10;
		r /= 10;
	}
	printf("%d", ans);
	return 0;
}

```





구름LEVEL 어려운 문제 goorm goormlevel

