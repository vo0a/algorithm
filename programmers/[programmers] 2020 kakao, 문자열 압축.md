## [programmers] 2020 kakao, 문자열 압축

[문제](https://programmers.co.kr/learn/courses/30/lessons/60057)



```c++
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solution(string input) {
    
    int len = input.length() / 2;
	int ans = input.size();
	for (int i = 1; i <= len; i++) {
		string s = "", num = "";
		int j = i, cnt = 1;
		string sub = input.substr(0, i);
		while (j < input.length()) {
			if (input.substr(j, i) == sub) {
				cnt++;
			}
			else {
				if (cnt > 1) {
					num = to_string(cnt);
					s += num;
				}
				s += sub;
				sub = input.substr(j, i);
				cnt = 1;
			}
			j += i;
		}
		if (cnt > 1) {
			num = to_string(cnt);
			s += num;
		}
		s += sub;
		int size = s.length();
		ans = min(ans, size);
	}
    
    return ans;
}
```





프로그래머스 2020 KAKAO BLIND RECRUITMENT, 문자열 압축

