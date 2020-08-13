## [programmers] DP, N으로 표현

[문제](https://programmers.co.kr/learn/courses/30/lessons/42895#)



```c++
#include <string>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;
typedef pair<int, int> p;
int chk[MAX];

void pushNum(queue<p>& q, p front, int N, int plus) {
	int a[4] = { 0 };
	a[0] = front.first + N;
	a[1] = front.first - N;
	a[2] = front.first / N;
	a[3] = front.first * N;
	for (int i = 0; i < 4; i++) {
		if (a[i] < MAX && a[i] > 0 && !chk[a[i]]) {
			chk[a[i]] = front.second + plus;
			q.push({ a[i], front.second + plus });
		}
	}
}

int solution(int N, int number) {
	int answer = 10;
	string doubleN = to_string(N) + to_string(N);
	int NN = stoi(doubleN);

	queue<p> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		p front = q.front();
		q.pop();
		if (front.first == number) {
			answer = answer > front.second ? front.second : answer;
			break;
		}

		if (abs(number - front.first) > 0) {
			int idx = abs(number - front.first);
			if (chk[idx]) {
				answer = answer > front.second + chk[idx] ? front.second + chk[idx] : answer;
				continue;
			}
		}

		pushNum(q, front, N, 1);
		pushNum(q, front, NN, 2);
	}
	if (answer > 8) answer = -1;
	return answer;
}
```

> 1. (4, 17) -> return 4 (O)    : 4 * 4 + (4 / 4)
> 2. (5, 24) -> return 4 (X)     : 5 * 5  - (5 / 5)
>
> 1번은 제대로 나왔지만, 2번은 7을 출력해서 문제되는 곳을 봤더니 '(number - front.first) > 0' 부분에서 -가 되어 4가 저장되지 못했고 7을 출력하는 문제가 있었다.
>
> 따라서 abs 함수를 이용해서 절댓값으로 바꾼 후 정답을 받을 수 있었다.



프로그래머스 고득점 키트 DP N으로 표현

