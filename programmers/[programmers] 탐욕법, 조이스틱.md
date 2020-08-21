## [programmers] 탐욕법, 조이스틱

[문제](https://programmers.co.kr/learn/courses/30/lessons/42860#)



```c++
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(string name) {
	int answer = 0, idx = 0, size = name.size();
	map<char, int> alphabet;

	for (int i = 0; i < 26; i++) {
		alphabet.insert({ 'A' + i, i });
	}

	string str = "";
	for (int i = 0; i < name.size(); i++) {
		str += "A";
	}

	int movement = 0, preIdx = 0;
	while (str != name) {
		if (name[idx] != str[idx]) { //  26 - alphabet 한 값 vs alphabet 그 자체
			// 알파벳 변환
			int cnt = min(alphabet[name[idx]], 26 - alphabet[name[idx]]);
			str[idx] = name[idx];
			answer += cnt;

			// 커서 이동 거리 : idx - 0 인지 size() - idx인지
			movement += min(idx - preIdx, size - idx + preIdx);

			preIdx = idx;
		}
		idx++;
	}
	answer += movement;
	return answer;
}
```

> ```
> 테스트 1
> 입력값 〉	"JEROEN"
> 기댓값 〉	56
> 실행 결과 〉	테스트를 통과하였습니다.
> 테스트 2
> 입력값 〉	"JAN"
> 기댓값 〉	23
> 실행 결과 〉	테스트를 통과하였습니다.
> 테스트 3
> 입력값 〉	"AZAAAZ"
> 기댓값 〉	5
> 실행 결과 〉	테스트를 통과하였습니다.
> 
> 입력값 〉"ABAAAAAAAAABB"
> 기댓값 〉7
> 실행 결과 〉실행한 결괏값 8이(가) 기댓값 7와(과) 다릅니다.
> 테스트 5
> 입력값 〉"ABABAAAAAAABA"
> 기댓값 〉10
> 실행 결과 〉실행한 결괏값 11이(가) 기댓값 10와(과) 다릅니다.
> ```
>
> 아래 두 케이스에서 1씩 많은 이유가 뭘까!





프로그래머스 고득점 키트 탐욕법 조이스틱

