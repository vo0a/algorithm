## [programmers] 완전탐색, 소수찾기

https://programmers.co.kr/learn/courses/30/lessons/42839



```c++
#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 10000005
using namespace std;
int prime[MAX], chk[MAX];
vector<int> v;

void prime_chk() {
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (!prime[i]) {
			for (int j = i * 2; j <= MAX; j += i) {
				prime[j] = 1;
			}
		}
	}
}

void make_num(string numbers, string now, int len, int idx) {
	if (now.size() > 0) {
		v.push_back(stoi(now));
	}
	if (len == idx) return;
	
	for (int i = 0; i < numbers.size(); i++) {
		if (chk[i]) continue;
		chk[i] = 1;
		now.push_back(numbers[i]);
		make_num(numbers, now, len, idx+1);
		now.pop_back();
		chk[i] = 0;
	}
	return;
}

int solution(string numbers) {
	int cnt = 0;
	prime_chk();
	prime[0] = prime[1] = 1;

	// 숫자 만들기
	string tmp;
	make_num(numbers, tmp, numbers.size(), 0);

	// 중복제거
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	// 소수판별
	for (int i = 0; i < v.size(); i++) {
		if (!prime[(v[i])]) cnt++;
	}
	return cnt;
}

using namespace std;
int main() {
	string numbers;
	cin >> numbers;
	
	printf("%d", solution(numbers));
	
	return 0;
}
```





프로그래머스 고득점 키트 완전탐색 소수 찾기

