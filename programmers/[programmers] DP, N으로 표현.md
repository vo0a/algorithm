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
			chk[a[i]] = front.second;
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

		pushNum(q, front, N, 1);
		pushNum(q, front, NN, 2);
	}
	if (answer > 8) answer = -1;
	return answer;
}
```

예제 1번만 틀린다... 뭐가 문제지!





예제 4, 17 일 때 return 4가 아니라 6이 나오길래, 아래처럼 고쳐봤는데 그래도 예제 1번만 틀린다 ㅜ^ㅜ 내일 더 고쳐야지..

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

		if (number - front.first > 0) {
			int idx = number - front.first;
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





프로그래머스 고득점 키트 DP N으로 표현

