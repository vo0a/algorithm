## [구름LEVEL] 화학약품

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★    | -%     |



프리미엄 알고리즘 위클리 비타알고 시즌3 1주차

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
//배열에 num이 몇 개 있는지 확인하는 함수
ll count(vector<int>& seq, int num) {
	return upper_bound(seq.begin(), seq.end(), num)
		- lower_bound(seq.begin(), seq.end(), num);
}
int main() {
	int n, num; scanf("%d", &n);
	vector<int> seq[2], sub[2];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		seq[i % 2].push_back(num);
	}
	for (int i = 0; i < 2; ++i) {
		//비트마스크를 이용하여 모든 부분집합 확인
		for (int j = (1 << seq[i].size()); j > 0; --j) {
			int sum = 0;
			for (int k = 0; k < seq[i].size(); ++k)
				if (j & (1 << k)) sum += seq[i][k];
			sub[i].push_back(sum);
		}
		sort(sub[i].begin(), sub[i].end());
	}
	auto l = sub[0].begin(), r = sub[1].end() - 1;
	ll ans = 0;
	while (l != sub[0].end() && r >= sub[1].begin()) {
		if (*l + *r == 0) {
			ans += count(sub[0], *l) * count(sub[1], *r);
			l = upper_bound(sub[0].begin(), sub[0].end(), *l);
			r = lower_bound(sub[1].begin(), sub[1].end(), *r) - 1;
		}
		else if (*l + *r > 0) {
			if (r == sub[1].begin()) break;
			--r;
		}
		else
			++l;
	}
	printf("%lld", ans - 1);
}
```





구름LEVEL 화학약품 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

