## [programmers] 탐욕법, 조이스틱

[문제](https://programmers.co.kr/learn/courses/30/lessons/42860#)



## 시도 1

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



## 시도 2

시도 1 코드에서 `ABAAAAAAAAABB` 같은 경우에는 AB를 먼저 확인 후에 왼쪽으로 이동해서 BB를 확인해야 7이 나온다. 

그래서 방향을 어떻게 잡을지 고민하다가 DFS로 풀어봤는데 + 방향, - 방향가는 부분에서 이미 확인한 방향임을 체크하지 않다보니 무한루프에 빠지게 된다. 

어디서 어떻게 방향을 바꿔야할지 아직 더 고민해봐야할 것 같다. 

아니면 단순히 아래 세 가지 경우 중 최솟값을 출력해야 할듯.

1. 0 ~ N
2. 0 ~ i + N ~ j
3. N ~ j + 0~ i

```c++
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int ans = 1e9;

void go(string name, string str, int size, map<char, int> alphabet, int preIdx, int idx, int cnt) {
	if (ans < cnt) return;
	if (name == str) {
		ans = min(ans, cnt);
		return;
	}

	if (name[idx] != str[idx]) {
		// 알파벳 선택 횟수
		int count = min(alphabet[name[idx]], 26 - alphabet[name[idx]]);
		str[idx] = name[idx];
		cnt += count;

		int movement = idx > preIdx ? min(idx - preIdx, size - idx + preIdx) : min(preIdx - idx, size - preIdx + idx);
		cnt += movement;
		preIdx = idx;
	}
	// + 방향
	go(name, str, size, alphabet, preIdx, (idx + 1) % size, cnt);
	// - 방향
	go(name, str, size, alphabet, preIdx, (idx + size - 1) % size, cnt);	
}

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

	go(name, str, size, alphabet, 0, 0, 0);

	answer = ans;
	return answer;
}
```





프로그래머스 고득점 키트 탐욕법 조이스틱

