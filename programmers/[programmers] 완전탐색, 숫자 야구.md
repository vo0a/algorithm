## [programmers] 완전탐색, 숫자 야구

https://programmers.co.kr/learn/courses/30/lessons/42841



```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	for (int i = 123; i <= 987; i++) {
		string num = to_string(i);
		if (num[0] == '0' || num[1] == '0' || num[2] == '0') continue;
		if (num[0] == num[1] || num[1] == num[2] || num[2] == num[0]) continue;
		bool flg = false;
		for (int i = 0; i < baseball.size(); i++) {
			int bb = baseball[i][0], strike = baseball[i][1], ball = baseball[i][2];
			string ballnum = to_string(bb);
			int s = 0, b = 0;
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (ballnum[j] == num[k]) {
						if (j == k) {
							s++;
						}
						else {
							b++;
						}
					}
				}
			}
			if (strike != s || ball != b) {
				flg = true; break;
			}
		}
		if (!flg)answer++;
	}
	return answer;
}
```





프로그래머스 고득점 키트 완전탐색 숫자 야구

