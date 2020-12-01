## [BOJ] #2875 대회 or 인턴

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 128 MB      | 41.581%   |

[문제](https://www.acmicpc.net/problem/2875)



| 메모리  | 시간 |
| ------- | ---- |
| 2016 KB | 0 ms |

```c++
#include <iostream>
using namespace std;

int n, m, k;
int main() {
	scanf("%d%d%d", &n,&m,&k);

	// 인턴을 하면, 대회에 못나감
	// n + m >= k + 3(대회에 참여하는 인원)
	int ans = 0;
	while (n - 2 >= 0 && m -1 >= 0 && n + m -3 >= k) {
		n -= 2;
		m--;
		ans++;
	}
	printf("%d", ans);
	return 0;
}
```





백준 2875 대회 or 인턴 boj acmicpc

