## [구름LEVEL] 화학약품

| 난이도 | 정답률 |
| ------ | ------ |
| ★★★    | -%     |



>3
>6 -6 6 
>**2**

>5
>-5 -4 6 -10 9
>**2**



프리미엄 알고리즘 위클리 비타알고 시즌3 1주차

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, arr[45];
vector<int> v[2];
void func(int idx, int end, int sum, int i) {
	if (idx >= end) {
		v[i].push_back(sum);
		return;
	}
	func(idx + 1, end, sum, i);
	func(idx + 1, end, sum + arr[idx], i);
}

ll count(vector<int>& t, int num) {
	return upper_bound(t.begin(), t.end(), num) - lower_bound(t.begin(), t.end(), num);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	// 완전탐색
	func(0, n / 2, 0, 0);
	func(n / 2, n, 0, 1);
	// 정렬 - 필수
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	// 투포인터
	vector<int>::iterator l, r;
	l = v[0].begin(), r = v[1].end() - 1;
	ll ans = 0;
	while (l != v[0].end() && r >= v[1].begin()) {
		if (*l + *r == 0) {
			ans += count(v[0], *l) * count(v[1], *r);
			l = upper_bound(v[0].begin(), v[0].end(), *l);
			r = lower_bound(v[1].begin(), v[1].end(), *r - 1);
		}
		else if (*l + *r > 0) {
			if (r == v[1].begin()) break;
			r--;
		}
		else l++;
	}
    // 공집합 제외
	printf("%lld", ans - 1);
	return 0;
}
```

일단 공집합까지 모두 포함해서 배열에 저장해둬야 부분집합을 헤아릴 때 0되는 것들도 답으로 체크가 된다. 그래서 공집합 포함 모든 부분집합을 구한 뒤 투포인터로 정답 수를 세고, 마지막 출력할 때 공집합을 제외하여 출력해야 한다.



```c++
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
    ...
```

- 입력을 받을 때, 짝수와 홀수 인덱스로 나눠서 입력을 받고
- 부분집합을 헤아릴 때 비트연산자를 사용해서 나눠진 배열에서의 부분집합을 구했다.



구름LEVEL 화학약품 goorm goormlevel 프리미엄 알고리즘 위클리 비타알고 시즌3

