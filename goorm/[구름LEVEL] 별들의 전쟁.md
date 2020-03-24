## [구름LEVEL] 별들의 전쟁

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★    | -      |



프리미엄 알고리즘 위클리 비타알고 시즌3 4주차

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, dp[10005];
vector<int> units;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0, a; i < n; i++) {
		scanf("%d", &a);
		units.push_back(a);
	}
	sort(units.begin(), units.end());
	units.erase(unique(units.begin(), units.end()), units.end());
	for (auto unit : units) {
		for (int i = unit; i <= k; i++) {
			if (i == unit)dp[i] = 1;
			else if (dp[i - unit] > 0) dp[i] = dp[i] ? min(dp[i], dp[i - unit] + 1) : dp[i - unit] + 1;
		}
	}
	printf("%d", dp[k] ? dp[k] : -1);
	return 0;
}

```





구름LEVEL 별들의 전쟁 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3
