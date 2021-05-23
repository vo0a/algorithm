## [programmers] 2021 kakao, 신규 아이디 추천

[문제](https://programmers.co.kr/learn/courses/30/lessons/72410)



```c++
#include <string>
#include <vector>
using namespace std;

void rule1(string& s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') 
			s[i] += 32; //  s[i] - 'A' + 'a' = s[i] - 65 + 97
	}
}
void rule2(string& s) {
	for (int i = 0; i < s.length(); ) {
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9' || s[i] == '.' || s[i] == '-' || s[i] == '_') { i++;  continue; }
		s.erase(i, 1);
	}
}
void rule3(string& s) {
	int cnt = 0;
	for (int i = 0; i < s.length(); ) {
		if (s[i] == '.') {
			cnt++; i++;
		}
		else {
			if (cnt >= 2) {
				s.replace(i - cnt, cnt, ".");
				i = i - cnt + 1;
			}
			else i++;
			cnt = 0; 
		}
	}
	if (cnt >= 2) {
		s.replace(s.end() - cnt, s.end(), ".");
	}
}
void rule4(string& s) {
	if (s[0] == '.') s.erase(0, 1);
	if (s[s.length() - 1] == '.') s.erase(s.length() - 1, 1);
}
void rule5(string& s) {
	if (s.length() == 0) s = "a";
}
void rule6(string& s) {
	if (s.length() >= 16) s.erase(15);
	if (s[s.length() - 1] == '.') s.erase(s.length() - 1, 1);
}
void rule7(string& s) {
	if (s.length() <= 2) {
		char c = s[s.length() - 1];
		while (s.length() < 3) {
			s += c;
		}
	}
}

string solution(string new_id) {
	string answer = "";
	rule1(new_id);
	rule2(new_id);
	rule3(new_id);
	rule4(new_id);
	rule5(new_id);
	rule6(new_id);
	rule7(new_id);
	answer = new_id;
	return answer;
}
```



프로그래머스 2021 kakao, 신규 아이디 추천

