## [programmers] 2021 kakao, 순위 검색

[문제](https://programmers.co.kr/learn/courses/30/lessons/72412)



```c++
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

map<string, vector<int>> scores;
// ----, java---, -backend--, javabackend--, --junior- ... javabackendjuniorpizza
void addCases(string *s, int score) {
	for (int i = 0; i < 16; i++) {
		string str = "";
		int a = i;
		for (int j = 0; j < 4; j++) {
			if (a % 2 == 0) str += "-";
			else str += s[j];
			a /= 2;
		}
		scores[str].push_back(score);
	}
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	string s[4], num;
	for (auto e : info) {		
		stringstream ss(e);
		ss >> s[0] >> s[1] >> s[2] >> s[3] >> num;
		addCases(s, stoi(num));
	}

	for (auto &e : scores)
		sort(e.second.begin(), e.second.end());
	
	for (auto e : query) {
		stringstream ss(e);
		ss >> s[0] >> num>>  s[1] >> num >>  s[2] >> num >> s[3] >> num; // num이 and를 받다가 마지막에 score를 입력받음.
		int score = stoi(num);
		
		vector<int> v = scores[s[0] + s[1] + s[2] + s[3]];
		if (v.size()) {
			int l = lower_bound(v.begin(), v.end(), score) - v.begin();
			answer.push_back(v.size() - l);
		}
		else answer.push_back(0);
	}
	return answer;
}
```

- 카테고리는 언어, 직군, 경력, 소울푸드 로 4가지 이다.
- 4가지에 대해 모든 경우의 수를 고려하기 위해 지원자당 2^4 = 16개의 문자열을 구성한다.
- query에 대해 이분탐색(lower_bound)를 활용하여 socre보다 큰 수의 갯수를 찾는다.
  - 이분탐색을 위해 map에 저장된 값를 정렬시켜야 한다.
  - `for ( auto &e : scores)` & 연산자를 붙여야 정렬이 됨!! 붙이지 않으면 e.second는 `scores`의 value가 아닌 value값을 복사한 단순 변수이기 때문에



프로그래머스 2021 kakao, 순위 검색

