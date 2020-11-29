## [BOJ] #11399 ATM

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 256 MB      | 65.119%   |

[문제](https://www.acmicpc.net/problem/11399)



| 메모리  | 시간 |
| ------- | ---- |
| 2020 KB | 0 ms |

```c++
#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1005];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}	
	sort(arr, arr + n);
	int ans = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += arr[i];
		ans += cnt;
	}
	printf("%d", ans);
	return 0;
}
```





백준 11399 ATM boj acmicpc

