## [programmers] 탐욕법, 큰 수 만들기

[문제](https://programmers.co.kr/learn/courses/30/lessons/42883#)



```c++
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int idx = 0, len = number.size();
	while (k > 0) {
        if (idx == number.size() - 1) {
			number = number.substr(0, len - k); break;
		}
		int first = number[idx] - '0';
		int second = number[idx + 1] - '0';
		if (first < second) {
			number.erase(idx, 1);
			k--;
			idx = 0;
		}
		else idx++;
	}
	answer = number;
	return answer;
}
```

> "1111", 1 이 주어질 때 "111"을 출력하기 위해서 아래 조건을 추가하고 정답을 받을 수 있었다.
>
> ```c++
>  if (idx == number.size() - 1) {
>      number = number.substr(0, len - k); break;
>  }
> ```





프로그래머스 고득점 키트 탐욕법 큰 수 만들기

