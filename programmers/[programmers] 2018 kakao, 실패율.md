## [programmers] 2018 kakao, 실패율

한 번 실패했는데 어떤 부분을 고쳤냐면

> 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 `0` 으로 정의한다

```
testcase
7
1,2,3,4,5,6
[6,5,4,3,2,1,7]
```

이 때 Max = -1 로 초기화 시켰기 때문에 7을 전혀 고려하지 않는 상황이 발생하여 틀리게 됨.



```c++
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double, int> p;

bool cmp(p a, p b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<p> v;
	int arr[502] = { 0 }, Max = N;
	for (int i = 0; i < stages.size(); i++) {
		arr[stages[i]]++;
		Max = stages[i] > Max ? stages[i] : Max;
	}
	int people = 0;
	for (int i = Max; i > 0; i--) {
		people += arr[i];
		if (i <= N) {
			if (!arr[i])v.push_back({ 0, i });
			else v.push_back({ ((double)arr[i] / people), i });
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		answer.push_back(v[i].second);
	}
	return answer;
}

int main() {
	solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
	return 0;

}
```