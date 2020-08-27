## [programmers] 해시, 완주하지 못한 선수

[문제](https://programmers.co.kr/learn/courses/30/lessons/42576)



```c++
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> p;
map<string, p> m;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	for (int i = 0; i < participant.size(); i++) {
		m[participant[i]].first++;
	}

	for (int i = 0; i < completion.size(); i++) {
		m[completion[i]].second++;
	}

	for (auto e : m) {
		if (e.second.first != e.second.second) {
			answer += e.first;
		}
	}
	return answer;
}
```





프로그래머스 고득점 키트 해시 완주하지 못한 선수

