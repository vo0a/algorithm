## [BOJ] #1005 ACM Craft

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 1 초      | 512 MB      | 20.931%   |





| 메모리 | 시간 |
| ------ | ---- |
| KB     | 0 ms |



## 시도 1

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int t, n, m, Find, d, time[1005], chk[1005], ans;
vector<vector<int>> adj;
vector<p> res;
void dfs(int here, int depth) {
	chk[here] = 1;
	for (auto next : adj[here]) {
		if (chk[next]) continue;
		dfs(next, depth + 1);
	}
	if (here == Find) {
		d = depth; ans += time[here];
	}
	res.push_back({ here, depth });
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &time[i]);
		}
		adj.resize(n + 1);
		for (int i = 0,a , b; i < m; i++) {
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}
		scanf("%d", &Find);

		for (int i = 1; i <= n; i++) {
			// 위상정렬
			if (!chk[i]) {
				dfs(i, 0);
			}
		}
		// 위상정렬 결과값으로 최소 시간 구하기		
		// 레벨에서 가장 큰 값을 더해가기
		int level = d, Max = 0;
		for (auto e : res) {
			if (e.second < level) {
				ans += Max;
				Max = time[e.first];
				level = e.second;
			}
			else if (e.second >= d) continue;
			else if (e.second == level) {
				Max = max(Max, time[e.first]);
			}
		}
		ans += Max;

		printf("%d\n", ans);
		ans = 0;
		adj.clear();
		res.clear();
		memset(chk, 0, sizeof(chk));
	}
	
	return 0;
}
```

> 2
> 3 2
> 1 2 3
> 3 2
> 2 1
> 1
> 5 10
> 100000 99999 99997 99994 99990
> 4 5
> 3 5
> 3 4
> 2 5
> 2 4
> 2 3
> 1 5
> 1 4
> 1 3
> 1 2
> 4

위 처럼 DFS를 활용하여 위상정렬 후 최소시간을 구하려고 했더니

1. `3 → 2 → 1` 처럼 되어있으면 답이 틀리게 되는 문제가 발생.
   - 1부터 시작이 아니라, **루트**를 별도로 찾아야 하니까
2. `1 → 5` 같은 경우가 `1 → 2 → 3 → 4 → 5` 보다 먼저 입력 될 때
   - 입력 순서에 따라서 위상정렬 결과값이 달라지는 문제가 발생
   - 이럴바엔 큐를 활용하는게 낫다고 판단
   - 따라서 DFS를 활용한 위상정렬이 아닌, 큐를 활용하여 DFS를 작성해야 겠다.



## 시도 2

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int t, n, m, Find, d, time[1005], indegree[1005], ans;
vector<vector<int>> adj;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &time[i]);
		}
		adj.resize(n + 1);
		for (int i = 0,a , b; i < m; i++) {
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			indegree[b]++;
		}
		scanf("%d", &Find);

		queue<p> q;

		for (int i = 1; i <= n; i++) {
			if (!indegree[i]) q.push({ i, 0 });
		}
		// 위상정렬 결과값으로 최소 시간 구하기		
		// 레벨에서 가장 큰 값을 더해가기
		int level = -1, Max = 0;
		for (int i = 1; i <= n; i++) {
			p front = q.front();
			q.pop();
			int num = front.first, depth = front.second;

			// 답이되는 노드가 현재 그래프상에 없을 수도 있음
			if (num == Find) {
				if (!depth) ans = time[num];
				else ans += Max + time[num];
				break;
			}

			if (level < depth) {
				ans += Max;
				level = depth; Max = time[num];							
			}			
			else if (level == depth) {
				Max = max(Max, time[num]);
			}

			for (auto e : adj[num]) {
				if (--indegree[e] == 0) {
					q.push({ e, depth + 1 });
				}
			}
		}

		printf("%d\n", ans);
		ans = 0;
		adj.clear();
		memset(indegree, 0, sizeof(indegree));
	}
	
	return 0;
}
```

- 틀릴 걸 예상했지만 별 다른 생각이 나지 않아 일단 제출해봄

  - 당연히 틀림

  - 아래와 같은 테스트케이스인 경우, `1 → 2 → 3 `이 그리는 그래프와 `4`가 그리는 그래프가 다를 때, 위와 같이 위상정렬을 하면서 정답을 찾을 때 문제가 생긴다.

  - > ```
    > 1
    > 4 3
    > 5 5 5 5
    > 1 2
    > 1 3
    > 2 3
    > 4
    > ```

  - 
    ```c++
    // 답이되는 노드가 현재 그래프상에 없을 수도 있음
    			if (num == Find) {
    				if (!depth) ans = time[num]; // 일단은 이렇게 처리해봤지만..
    				else ans += Max + time[num];
    				break;
    			}
    ```

  - ``1 → 2 → 3  ` , `5 → 4` 이렇게 주어졌을 때 탐색을 1부터 시작한다면, 정답은 절대 나올 수 없음.

- 고민 끝에 [질문검색](https://www.acmicpc.net/board/view/30959)을 찾아봤고, 힌트를 얻을 수 있었다.

  - DP 로 메모이제이션하면서 다시 풀기!



백준 1005 ACM Craft boj acmicpc

