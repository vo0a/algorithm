## [programmers] 이분탐색, 입국심사

[문제](https://programmers.co.kr/learn/courses/30/lessons/43238#)



```c++
#include <string>
#include <vector>
using namespace std;

long long go(long long left, long long right, vector<int> times, int n) {
	if (left > right) return left;

	long long mid = (left + right) / 2;
	long long sum = 0;
	for (auto t : times) {
		sum += mid / t;
	}
	if (sum >= n) {
		return go(left, mid - 1, times, n);		
	}
	else return go(mid + 1, right, times, n);
}

long long solution(int n, vector<int> times) {
	long long answer = 0;

	answer = go(0, 1e9 * 1e9, times, n);
    
	return answer;
}
```





프로그래머스 고득점 키트 이분탐색 입국심사

