## [BOJ] #2291 Sequence

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 2 초      | 128 MB      | 43.230%   |

[문제](https://www.acmicpc.net/problem/2291)



| 메모리  | 시간  |
| ------- | ----- |
| 6212 KB | 32 ms |

```c++
#include <iostream>
using namespace std;
long long d[11][221][221]; // len, sum, last
int n, m;
void go(int len, int sum, int last, long long cnt) {
	if (len <= 0) {
		return;
	}
	// cerr << len << ' ' << sum << ' ' << last << '\n';
	long long acc = 0;
	for (int i = last; i <= m; i++) {
		if (cnt < acc + d[len][sum][i]) {
			printf("%d ", i);
			go(len - 1, sum - i, i, cnt - acc);
			break;
		}
		acc += d[len][sum][i];
	}
}
int main() {
	long long s;
	scanf("%d%d%lld", &n, &m, &s);
	for (int i = 1; i <= m; i++) {
		d[1][i][i] = 1LL;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= j; k++) {
				for (int l = k; l <= j; l++) {
					if (j - k >= 1) {
						d[i][j][k] += d[i - 1][j - k][l];
					}
				}
			}
		}
	}
	go(n, m, 1, s - 1);
	return 0;
}
```

- D\[n]\[m][l] = 길이가 n이고 합이 m이며 a1이 l인 수열의 개수
- D\[n]\[m][l]에서 2번째 수가 k라면 (m-k >=1, k>= l)
- D\[n]\[m][l] += D\[n-1]\[m-l][k]
- 사전 순으로 K번째를 찾아야 하기 때문에 수열의 앞부터 정답을 찾음



백준 2291 Sequence boj acmicpc

