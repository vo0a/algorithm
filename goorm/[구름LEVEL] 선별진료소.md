## [구름LEVEL] 선별진료소

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★    | - %    |

[문제](https://edu.goorm.io/learn/lecture/18444/시즌3-연재-중-위클리-비타알고-중급편/lesson/941782/4월-1주차-선별진료소-3)



프리미엄 알고리즘 위클리 비타알고 시즌3 4월 1주차

```c++
#include <cstdio>
using namespace std;
typedef long long ll;
int n, k, ans, arr[100005];
ll chk(int mid) {
	ll res = 0;
	for (int i = 0; i < k; i++) {
		res += (mid / arr[i]);
	}
	return res;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
	}
	int l = 0, r = 1e9;
	while (l <= r) {
		int mid = (l + r) / 2;
		ll res = chk(mid);
		if (res >= n) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	printf("%d", ans);
	return 0;
}
```





구름LEVEL 선별진료소 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

