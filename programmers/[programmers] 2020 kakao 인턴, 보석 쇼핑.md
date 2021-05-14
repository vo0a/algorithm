## [programmers] 2020 kakao 인턴, 보석 쇼핑

[문제](https://programmers.co.kr/learn/courses/30/lessons/67258)



### map

```c++
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
	map<string, int> gem;
	int total_cnt = 0; // 보석의 종류 개수 - set으로 insert 후 size값을 저장해도 됨
	for (auto e : gems) {
		if (gem.find(e) == gem.end()) gem[e] = total_cnt++;
	}

	pair<int, int> ans;
	int left = 0, right = 0,  Min = 100005;
	map<string, int> chk;
	chk[gems[right]]++;
	while (left <= right && right < gems.size()) {
		// 선택한 보석의 종류 개수가 전체 보석의 종류 개수와 같을 때
		if (chk.size() == total_cnt) {
			if (Min > right - left + 1) {
				Min = right - left + 1;
				ans.first = left + 1;
				ans.second = right + 1;
			}
			// left 삭제
			chk[gems[left]]--;
			if (chk[gems[left]] == 0) chk.erase(gems[left]);
			left++;
			continue;
		}
		else if (chk.size() < total_cnt) {
			right++;
			if (right < gems.size()) {
				chk[gems[right]]++;
				// 속도향상을 위함 - 없어도 정답
				if (gems[right] == gems[left] || gems[left] == gems[left + 1]) {
					chk[gems[left]]--;
					left++;
				}
			}
		}
	}
	vector<int> answer = { ans.first, ans.second };
	return answer;
}
```



### String find 사용 → 시간초과

```c++
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
	map<string, int> gem;
	int total_cnt = 0; // 보석의 종류 개수
	for (auto e : gems) {
		if (gem.find(e) == gem.end()) gem[e] = total_cnt++;
	}

	pair<int, int> ans;
	int left = 0, right = 0, cnt = 1, Min = 100005;
	string gemstr = gems[right];
	while (left <= right && right < gems.size()) {
		// 선택한 보석의 종류 개수가 전체 보석의 종류 개수와 같을 때
		if (cnt == total_cnt) {
			if (Min > right - left + 1) {
				Min = right - left + 1;
				ans.first = left + 1;
				ans.second = right + 1;
			}
			// left 삭제
			gemstr.replace(gemstr.find(gems[left]), gems[left].length(), "");
			if (gemstr.find(gems[left]) == string::npos) cnt--;
			left++;
			continue;
		}
		else if (cnt < total_cnt) {
			right++;
			if (right < gems.size()) {
				if (gemstr.find(gems[right]) == string::npos) cnt++;
				gemstr += gems[right];

				if (gems[right] == gems[left] || gems[left] == gems[left + 1]) {
					gemstr.replace(gemstr.find(gems[left]), gems[left].length(), "");
					left++;
				}
			}
		}
	}
	vector<int> answer = { ans.first, ans.second };
	return answer;
}
```





프로그래머스 2020 kakao 인턴, 보석 쇼핑

