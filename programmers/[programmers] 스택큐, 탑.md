## [programmers] 스택/큐, 탑

[문제](https://programmers.co.kr/learn/courses/30/lessons/42588?language=cpp)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	int flg;
	for (int i = heights.size() - 1; i >= 1; i--) {
		int pre = heights[i]; flg = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (heights[j] > pre) {
				answer.push_back(j+1);
				flg = 1;
				break;
			}
		}
		if (!flg) answer.push_back(0);
	}
	answer.push_back(0);
	reverse(answer.begin(), answer.end());
	return answer;
}
```





프로그래머스 고득점 키트 스택/큐 탑
