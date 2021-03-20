## [BOJ] #2150 Strongly Connected Component

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 2 초      | 128 MB      | 47.821%   |

[문제](https://www.acmicpc.net/problem/2150)



## Kosaju's Algorithm

| 메모리  | 시간  |
| ------- | ----- |
| 3484 KB | 40 ms |

```c++
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> a[10001];
vector<int> ar[10001];
int component[10001];
bool c[10001];
vector<int> order;
void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		dfs(a[x][i]);
	}
	order.push_back(x); // 끝나는 순서대로 스택에 추가(1~n 번호 부여)
}
void dfs_rev(int x, int cn) {
	if (c[x]) return;
	c[x] = true;
	component[x] = cn; // x가 속한 연결 요소 번호
	for (int i = 0; i < ar[x].size(); i++) {
		dfs_rev(ar[x][i], cn);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v); // 순방향
		ar[v].push_back(u); // 역방향 간선
	}
	for (int i = 1; i <= n; i++) {
		if (!c[i]) {
			dfs(i); // 번호 매기기
		}
	}
	reverse(order.begin(), order.end()); // 간선의 방향을 모두 뒤집음
	memset(c, false, sizeof(c));
	int cnt = 0; // 연결 요소 개수
	for (int i = 0; i < n; i++) { // 가장 늦게 끝난 순서대로 DFS = 번호가 큰 순서대로 DFS
		if (!component[order[i]]) {
			cnt += 1; // component 자체가 c(chk)배열 역할을 하고 있기 때문에 0부터 채우면 안됨
			dfs_rev(order[i], cnt);
		}
	}
	printf("%d\n", cnt);
	vector<vector<int>> ans(cnt);
	for (int i = 1; i <= n; i++) {
		ans[component[i] - 1].push_back(i); // 인덱스에 요소를 추가
	}
	// 각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 출력한다.
	for (int i = 0; i < cnt; i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < cnt; i++) {
		for (int x : ans[i]) {
			printf("%d ", x);
		}
		printf("-1\n");
	}
	return 0;
}
```

- Strongly Connected : 모든 정점에서 모든 정점으로 이동할 수 있다.
- **SCC** : Strongly Connected Component
  - 그래프를 Strongly Connected되게 서브 그래프로 나눔 & maximal한 성질을 가짐(SCC가 가능한 커야 한다)
  - **단방향** 그래프에서 의미가 있음. 
    - 양방향 그래프라면 컴포넌트 자체가 SCC라고 볼 수 있기 때문에 의미가 없게 됨.
  - 장점 : 방향 그래프의 사이클을 제거해 DAG로 만들어 문제를 해결 할 수 있다.
  - O(N) 안에 모든 SCC를 분리하는 것이 가능, 시간복잡도는 O(V + E)
- `Kosaju`방법 : SCC 만 구할 때 활용
  - 순방향 DFS로 정점의 번호를 매기고
  - 모든 간선의 방향을 뒤집은 역방향 DFS로 SCC를 구한다.



### Tarjan's Algorithm

| 메모리  | 시간  |
| ------- | ----- |
| 2672 KB | 36 ms |

```c++
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10000;
 
// SN: SCC 개수, sn[i]: i가 속한 SCC의 번호
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; // SCC 분리가 끝난 정점만 true
stack<int> S;
vector<vector<int>> SCC;
 
// 자신의 결과값을 리턴하는 DFS 함수
int DFS(int curr){
    dfsn[curr] = ++cnt; // dfsn 결정
    S.push(curr); // 스택에 자신을 push
 
    // 자신의 dfsn, 자식들의 결과나 dfsn 중 가장 작은 번호를 result에 저장
    int result = dfsn[curr];
    for(int next: adj[curr]){
        // 아직 방문하지 않은 이웃
        if(dfsn[next] == 0) result = min(result, DFS(next));
        // 방문은 했으나 아직 SCC로 추출되지는 않은 이웃
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
 
    // 자신, 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
    if(result == dfsn[curr]){
        vector<int> currSCC;
        // 스택에서 자신이 나올 때까지 pop
        while(1){
            int t = S.top();
            S.pop();
            currSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if(t == curr) break;
        }
        // 출력을 위해 원소 정렬
        sort(currSCC.begin(), currSCC.end());
        // SCC 추출
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
}
 
int main(){
    // 그래프 정보 입력
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        adj[A-1].push_back(B-1);
    }
 
    // DFS를 하며 SCC 추출
    for(int i=0; i<V; i++)
        if(dfsn[i] == 0) DFS(i);
    // 출력을 위해 SCC들을 정렬
    sort(SCC.begin(), SCC.end());
 
    // SCC 개수
    printf("%d\n", SN);
    // 각 SCC 출력
    for(auto& currSCC: SCC){
        for(int curr: currSCC)
            printf("%d ", curr+1);
        puts("-1");
    }
}
```

- 아래 코드와 finished - chk 배열의 의미가 다르고, sn을 채우는 방식이 미세하게 차이가 있음

| 메모리  | 시간  |
| ------- | ----- |
| 2676 KB | 32 ms |

```c++
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
// sn[i] : i가 속한 SCC의 번호
vector<int> a[10001];
int sn[10001], num[10001], cnt = 0;
bool chk[10001]; // 분리가 끝난 정점만 false
stack<int> s;
vector<vector<int>> ans;
void dfs(int x) {
	chk[x] = true;
	s.push(x);
	num[x] = ++cnt; // dfs 번호를 결정
	sn[x] = cnt;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (num[y] == 0) { // 방문하지 않음 -> Tree edge
			dfs(y);
			sn[x] = min(sn[x], sn[y]);
		}
		else if (chk[y] == true) { // Back edge
			sn[x] = min(sn[x], num[y]);
		}
	}
	if (sn[x] == num[x]) { // SCC
		vector<int> scc;
		while (!s.empty()) { // 현재 정점 x까지 pop
			int y = s.top();
			scc.push_back(y);
			chk[y] = false;
			s.pop();
			if (x == y) {
				break;
			}
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!num[i]) dfs(i);
	}
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for (auto& scc : ans) {
		for (int x : scc) {
			printf("%d ", x);
		}
		printf("-1\n");
	}
	return 0;
}
```

- `Tarjan` 방법 : 다용도(SCC, 단절점, 단절선 등)
  - DFS 순회와 동시에 스택을 활용해서 SCC 단절점을 찾아낸다.
  - 방문하는 순서대로 스택에 저장한다.
  - DFS 순회 번호를 저장하는 **dfsn\[i]**(num[i])과, DFS Tree에서 i를 루트로하는 서브트리에서 갈 수 있는 가장 작은 번호를 저장하는 **sn[i]**가 필요하다.
    - DFS 순회가 끝난 sn[i]는 바로 i가 속한 SCC 번호가 된다.
    - sn[i]를 채울 때, 두 가지 경우로 나뉘게 된다.
      - Tree Edge
        - edge(u, v)에 대해서 v를 아직 방문하지 않은 경우이므로
        - DFS 순회를 끝낸 후
        -  `sn[u] = min(sn[u], sn[v]);`
      - Back Edge
        - edge(u, v)에 대해서 v를 이미 방문한 경우이므로
        - `sn[u] = min(sn[u], dfsn[v]);`
  - `num[i] == sn[i]`가 되는 경우가 SCC 라고 판단하는 기준이 된다.
    - 이 때, 스택에 존재하는 원소를 제거하면서 현재 정점 i와 같아질 때까지 제거한다.
    - 제거하면서 scc에 원소를 추가 하며
    - 출력을 위해 정렬을 하고 정답배열에 추가한다.





백준 2150 Strongly Connected Component boj acmicpc

