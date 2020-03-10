## [programmers] 완전탐색, 모의고사

https://programmers.co.kr/learn/courses/30/lessons/42840



```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int q1[] = { 1, 2, 3, 4, 5}, q2[] = { 2, 1, 2, 3, 2, 4, 2, 5}, q3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
int ans[5];
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int idx = 0, Max = 0;
	for (int i = 0; i < answers.size(); i++){
		if (q1[idx % 5] == answers[i]) ans[1]++;
		if (q2[idx % 8] == answers[i]) ans[2]++;
		if (q3[idx % 10] == answers[i]) ans[3]++;
		idx++;
	}
	Max = max(ans[1], ans[2]);
	Max = max(Max, ans[3]);
	for (int i = 1; i <= 3; i++) {
		if (Max == ans[i]) answer.push_back(i);
	}
	return answer;
}
```





프로그래머스 고득점 키트 완전탐색 모의고사

