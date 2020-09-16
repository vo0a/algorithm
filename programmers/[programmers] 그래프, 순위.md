## [programmers] 그래프, 순위

[문제](https://programmers.co.kr/learn/courses/30/lessons/49191)



```c++
#include <string>
#include <vector>

using namespace std;

// 플로이드 와샬
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    // 이길 수 있으면 i, j는 true
    for (auto r : results) graph[r[0]][r[1]] = true;
    // 거쳐가는 노드 k
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <=n; i++){
            for(int j = 1; j<=n; j++){
                if(graph[i][k] && graph[k][j]){
                    graph[i][j] = true;
                }
            }
        }        
    }
    for(int i = 1; i<=n; i++){
        int cnt = 0;
        for(int j = 1; j<=n; j++){
            // 이긴 횟수 + 진 횟수 = cnt
            if(graph[i][j] || graph[j][i]) cnt++;
        }
        // cnt가 n - 1이면 순위를 확정할 수 있는 선수
        if(cnt == n - 1) answer++;
    }
    
    return answer;
}
```

[플로이드 와샬 알고리즘 유튜브 설명](https://youtu.be/9574GHxCbKc?list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz) 참고했다.



## 시행착오

막연히 위상정렬이라고 생각했는데, 인디그리가 0인 노드가 여러개일 때 break하니까 30점짜리 코드가 됐다. 어떻게 해야할 지 더 고민해보기.

```c++
#include <string>
#include <vector>
#include <queue>
using namespace std;
int inDegree[105];
vector<int> adj[105];

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	for (int i = 0; i < results.size(); i++) {
		int a = results[i][0], b = results[i][1];
		adj[b].push_back(a);
		inDegree[a]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!inDegree[i]) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) return --answer;

		int front = q.front();
		q.pop();
		answer++;

		int flg = 0, b = 0;
		for (auto v : adj[front]) {
			if (--inDegree[v] == 0) {
				if (flg) {
					b = 1;  break;
				}
				q.push(v);
				flg = 1;
			}
		}
		if (b) break;
	}

	return answer;
}
```





프로그래머스 고득점 키트 그래프 순위

