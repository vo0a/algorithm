## [programmers] 스택큐, 다리를 지나는 트럭

[문제](https://programmers.co.kr/learn/courses/30/lessons/42583)



```c++
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
queue<p> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int sec = 0, sum = 0;
	
	for (int i = 0; i < truck_weights.size(); i++) {
		int tw = truck_weights[i];
		while (1) {
			if (q.size() && sec - q.front().first >= bridge_length) {
				sum -= q.front().second;
				q.pop();
			}
			if (sum + tw <= weight) {
				sum += tw;
				q.push({ sec++, tw});
				break;
			}
			else sec++;
		}
	}

	return sec + bridge_length;
}
```



## 우선순위 큐

```c++
#include <string>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	int idx = 0, wgt = 0;
	while (idx < truck_weights.size() || !pq.empty()) {
		while (!pq.empty() && answer - pq.top().first >= bridge_length) {
			wgt -= pq.top().second;
			pq.pop();
		}
		if (weight >= wgt + truck_weights[idx]) {
			while (weight >= wgt + truck_weights[idx]) {
				pq.push({ answer, truck_weights[idx] });
				wgt += truck_weights[idx++];
				answer++;
			}
		}
		else answer++;
	}
	return answer;
}
```

결론부터 말하자면 틀린코드.

두 번째 테스트케이스에서 틀리는데 디버깅하면 정답대로나와서 도대체 어디서 문제인지 못찾겠는 코드..





프로그래머스 고득점 키트 스택/큐 다리를 지나는 트럭

