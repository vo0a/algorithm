## [구름LEVEL] 온라인 강의

| 난이도 | 정답률 |
| ------ | ------ |
| ★      | -      |



프리미엄 알고리즘 위클리 비타알고 시즌3 3월 5주차

```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t1, t2, flg;
int main() {
	string a, b, x, x1, y, y1;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ':') { flg = 1; continue; }
		if (!flg) x += a[i];
		else {
			x1 += a[i];
		}
	}
	flg = 0;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == ':') { flg = 1; continue; }
		if (!flg) y += b[i];
		else {
			y1 += b[i];
		}
	}
	t1 = stoi(x) * 60 + stoi(x1);
	t2 = stoi(y) * 60 + stoi(y1);
	
	if (t2 - t1 >= 0 && t2 - t1 < 10) {
		printf("1");
	}
	else printf("0");
		
	return 0;
}
```





구름LEVEL 온라인 강의 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

