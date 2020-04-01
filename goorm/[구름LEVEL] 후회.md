## [구름LEVEL] 후회

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★★   | -      |

>  아직 93점. 15번 테스트케이스 틀림.



프리미엄 알고리즘 위클리 비타알고 시즌3 3월 5주차

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
int n, m, base;
ll idt[1 << 27];
void update(int pos, int num) {
	idt[pos] -= num;
	pos >>= 1; // pos /= 2;
	while (pos) {
		idt[pos] = idt[pos * 2] + idt[pos * 2 + 1];
		pos /= 2;
	}
}
ll sum(int st, int end) {
	ll ret = 0;
	while (st < end) {
		if (st % 2 == 1) ret += idt[st], st++;
		if (!(end % 2)) ret += idt[end], end--;
		st >>= 1, end >>= 1;
	}
	if (st == end) ret += idt[st];
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	for (base = 1; base < n; base *= 2);
	for (int i = base; i < base + n; i++) {
		scanf("%d", &idt[i]);
	}
	for (int i = base - 1; i > 0; i--) {
		idt[i] = idt[i * 2] + idt[i * 2 + 1];
	}
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			printf("%lld\n", sum(base + b - 1, base + c - 1));
		}
		else {
			update(base + b - 1, c);
		}
	}

	return 0;
}
```





구름LEVEL 후회 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

