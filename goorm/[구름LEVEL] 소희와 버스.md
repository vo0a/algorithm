## [구름LEVEL] 소희와 버스

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | 62.7%  |





```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
p arr[100005];
vector<p> v;
int n, t, ans;
int main() {
	scanf("%d %d", &n, &t);
	for (int i = 1, s, d; i <= n; i++) {
		scanf("%d %d", &s, &d);
		arr[i] = { s, d };
		v.push_back({ s, i });
	}
	for (int i = 1; i <= n; i++) {
		while (arr[i].first < t) {
			arr[i].first += arr[i].second;
		}
		v.push_back({ arr[i].first, i });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first >= t) {
			ans = v[i].second; break;
		}
	}
	printf("%d", ans);
	return 0;
}
```





구름LEVEL 소희와 버스 goorm goormlevel

