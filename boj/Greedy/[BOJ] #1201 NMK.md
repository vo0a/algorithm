## [BOJ] #1201 NMK

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 2 초      | 128 MB      | 30.090%   |

[문제](https://www.acmicpc.net/problem/1201)



| 메모리 | 시간 |
| ------ | ---- |
| 2016KB | 0 ms |

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	vector<int> a(n);
	if (m + k - 1 <= n && n <= m * k) {
		for (int i = 0; i < n; i++) {
			a[i] = i + 1;
		}
		vector<int> g; // 그룹의 경계
		g.push_back(0);
		g.push_back(k);
		n -= k;
		m -= 1;
		int gs = m == 0 ? 1 : n / m;
		int r = m == 0 ? 0 : n % m;
		for (int i = 0; i < m; i++) {
			g.push_back(g.back() + gs + (r > 0 ? 1 : 0));
			if (r > 0) {
				r -= 1;
			}
		}
		for (int i = 0; i < g.size() - 1; i++) {
			reverse(a.begin() + g[i], a.begin() + g[i + 1]);
		}
		for (int i = 0; i < a.size(); i++) {
			printf("%d ", a[i]);
		}
	}
	else {
		printf("-1\n");
	}
	return 0;
}
```

- 최대 부분 증가수열 M개
- 최대 부분 감소수열의 길이가 K인
- 1부터 N까지로 이루어진 수열을 구하는 문제
  - m + k - 1 <= n && n <= m * k



## 만드는 방법

1. 1부터 N까지 수를 오름차순으로 적는다.
2. 수를 M등분 한다. 이 때, 그룹에 들어있는 수는 K보다 작거나 같아야 하며, 적어도 한 그룹은 K개의 수가 들어있어야 한다.
   - N을 M등분한 몫을 gs, 나머지를 r이라고 하면, r이 1 이상이라면 gs에서 1씩 증가시키고 r을 감소하여서 gs에서 하나씩 차이날 수 있도록 한다.
3. 각 그룹에 들어있는 수의 순서를 뒤집는다.
   - 그룹의 경계를 담고있는 g배열을 반복문을 사용해서 각각의 범위만큼 reverse함수를 사용하여 순서를 뒤집는다.
4. 완성!



### 이유

1. 감소수열은 각 그룹에서 나오게 되고
2. 증가수열은 각 그룹에서 하나씩 뽑게 되면 증가 수열이 만들어진다.



백준 1201 NMK boj acmicpc

