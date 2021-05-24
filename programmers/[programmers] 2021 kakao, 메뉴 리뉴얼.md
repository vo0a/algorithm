## [programmers] 2021 kakao, 메뉴 리뉴얼

[문제](https://programmers.co.kr/learn/courses/30/lessons/72411)



```c++
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int chk[11];
map<string, int> course_menu;

void make_menu(string &order, string &menu, int idx, int cnt) {
	if (idx >= order.size()) {
		if(chk[cnt])
			course_menu[menu]++; 
		return;
	}

	make_menu(order, menu, idx + 1, cnt);
	menu += order[idx];
	make_menu(order, menu, idx + 1, cnt + 1);
	menu.pop_back();
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	
	// 코스요리를 구성하는 단품메뉴의 갯수
	for (auto e : course) {
		chk[e] = 1;
	}

	for (auto order : orders) {
		sort(order.begin(), order.end()); // 정렬
		string s = "";
		make_menu(order, s, 0, 0);
	}

	vector<pair<int, string>> rank;
	for (auto e : course_menu) {
		if (e.second < 2) continue;
		rank.push_back({ e.second, e.first });
	}
	sort(rank.rbegin(), rank.rend());

	for (auto e : rank) {
		if (chk[e.second.length()] <= e.first) {
			chk[e.second.length()] = e.first;
			answer.push_back(e.second);
		}
	}
	sort(answer.begin(), answer.end());

	return answer;
}
```



프로그래머스 2021 kakao, 메뉴 리뉴얼

