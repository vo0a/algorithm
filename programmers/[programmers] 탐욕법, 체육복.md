## [programmers] 탐욕법, 체육복

[문제](https://programmers.co.kr/learn/courses/30/lessons/42862)



```c++
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
   sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	int chk[31] = {0};
	int lostLength = lost.size();
	int reserveLength = reserve.size();
	int answer = n - lostLength;

	for (int i = 0; i < lostLength; i++) {
		chk[lost[i]]++;
	}
	for (int i = 0; i < reserveLength; i++) {
		if (chk[reserve[i]]) answer++;
		chk[reserve[i]]++;
	}

	for (int i = 0; i < reserveLength; i++) {
		if (chk[reserve[i]] == 2)continue;
		for (int j = 0; j < lostLength; j++) {
			if (chk[lost[j]] == 2)continue;
			if (abs(reserve[i] - lost[j]) == 1) {
				answer++;
                break;
			}
		}
	}

	return answer;
}
```





프로그래머스 고득점 키트 탐욕법 체육복

