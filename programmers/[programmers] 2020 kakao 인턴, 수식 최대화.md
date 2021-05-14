## [programmers] 2020 kakao 인턴, 수식 최대화

[문제](https://programmers.co.kr/learn/courses/30/lessons/67257)



```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> op = { "*", "+", "-" };
// 연산자에 대한 우선순위
vector<vector<int>> turn = { {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, { 3, 2, 1 }, { 3, 1, 2 }};

long long cal(string a, string b, string _op) {
	long long ret = 0;
	if (_op == "*") {
		ret = stol(a) * stol(b);
	}
	else if (_op == "+") {
		ret = stol(a) + stol(b);
	}
	else ret = stol(a) - stol(b);
	return ret;
}


long long solution(string expression) {
	long long answer = 0;
	vector<string> ex;
	string s = "";
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
			ex.push_back(s);
			// string op{ expression[i] };
			ex.push_back({ expression[i] });
			s = "";
		}
		else s += expression[i];
	}
	ex.push_back(s);

	for (int i = 0; i < 6; i++) {
		long long sum = 0;
		vector<string> v = ex;
		for (int j = 0; j < 3; j++) { // 우선순위
			string find_op = op[turn[i][j] - 1]; // 찾고 있는 연산자			

			vector<string> tmp;
			string pre = "";
			for (int i = 0; i < (int)v.size(); i++) {
				if (v[i] == find_op) {
					long long result = cal(pre, v[i + 1], find_op);
					tmp.pop_back();
					tmp.push_back(to_string(result));
					i += 1;
				}
				else tmp.push_back(v[i]);
				pre = tmp.back();
			}
			v = tmp;
		}
		sum = stol(v[0]);
		answer = max(abs(sum), answer);
	}

	return answer;
}

int main() {
	long long v = solution("100 - 200 * 300 - 500 + 20"); //60420
	cout << v;

	return 0;
}
```





프로그래머스 2020 kakao 인턴, 수식 최대화

