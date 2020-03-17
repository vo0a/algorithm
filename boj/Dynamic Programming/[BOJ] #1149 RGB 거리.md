## [BOJ] #1149 RGB 거리

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 0.5 초    | 128 MB      | 46.756%   |

N개의 행에 대하여 해당 행(집)을 빨간색, 초록색, 파란색으로 칠할 때 드는 비용이 각각 주어진다. 또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다. 집 i의 이웃은 집 i-1과 집 i+1이고, 첫 집과 마지막 집은 이웃이 아니다.

모든 집을 칠하는 비용의 최솟값을 구해야 한다.

N은 최대 1000 이다.

### 

| 메모리  | 시간 |
| ------- | ---- |
| 1988 KB | 0 ms |

이전에 내가 푼 코드 봄 ㄱ=

통찰력있게... i에서 r을 선택할 때는 i-1번째에서 g또는 b를 선택해야하니까 g또는 b 중 값이 작은 걸 선택.

```c++
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, r, g, b, x, y, z, ans;
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		r = min(y, z) + r;
		g = min(x, z) + g;
		b = min(x, y) + b;
		x = r, y = g, z = b;
	}
	ans = min(x, min(y, z));
	printf("%d", ans);
	return 0;
}
```



아래와 같이 dp 1차원 배열을 통해서 접근할 때는 틀리게 되는데 그 이유는 이전에 갱신된 값이 반영되어 더해지기 때문에 n*n 2차원 배열에서 i-1 행값으로 접근해야 정답이다.

```c++
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, dp[5], r, g, b, MIN;
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		dp[0] = min(dp[1], dp[2]) + r;
		dp[1] = min(dp[0], dp[2]) + g;
		dp[2] = min(dp[0], dp[1]) + b;
	}
	MIN = min(dp[0], min(dp[1], dp[2]));
	printf("%d", MIN);
	return 0;
}
```



백준 1149 RGB 거리 boj acmicpc

