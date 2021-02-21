## [BOJ] #1701 Cubeditor

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 0.5 초    | 128 MB      | 33.280%   |

[문제](https://www.acmicpc.net/problem/1701)



| 메모리  | 시간  |
| ------- | ----- |
| 2020 KB | 96 ms |

```c++
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> preprocessing(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int main() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	string a;
	int ans = 0;
	for (char c : s) {
		a = c + a;
		vector<int> next = preprocessing(a);
		int m = next.size();
		for (int i = 0; i < m; i++) {
			if (ans < next[i]) ans = next[i];
		}
	}
	printf("%d", ans);
	return 0;
}
```

- KMP
- 어떤 문자열 내에서 부분 문자열이 두 번 이상 나오는 문자열을 찾는 기능이다. 이때, 두 부분 문자열은 겹쳐도 된다.
- 이러한 부분 문자열 중에서 가장 길이가 긴 것을 구하라.
  - suffix의 prefix를 찾아라
- 원래 KMP는 시작점이 0으로 고정되어 있지만, 이 문제에서는 부분 문자열 중 KMP를 찾아야 하기 때문에 문자열을 뒤집고, 하나씩 추가하면서 매번 KMP를 해본다.
  - KMP는 원래 O(N) 이고 반복횟수가 N으로 N\*N이된다. 
  - 이 문제에서 N은 5000 이므로 N*N이 가능하다.



- KMP 함수를 아래와 같이 작성하는 방법도 있음

```c++
vector<int> preprocessing(string p) {
    int m = p.size();
    vector<int> next(m);
    next[0] = 0;
    int j = 0;
    for (int i=1; i<m; i++) {
        while (j>0 && p[i] != p[j]) {
            j = next[j-1];
        }
        if (p[i] == p[j]) {
            next[i] = j+1;
            j += 1;
        } else {
            next[i] = 0;
        }
    }
    return next;
}
```

```c++
vector<int> preprocessing(string p) {
	int m = p.size();
	int j = 0;
	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
```





백준 15686 치킨 배달 boj acmicpc

