## [programmers] 2020 데브매칭, 다단계 칫솔 판매

[문제](https://programmers.co.kr/learn/courses/30/lessons/77486)



```c++
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> num; // 사람의 번호
vector<int> answer;
void dfs(vector<vector<int>> &adj, int man, int price) {
	int divi = price * 0.1;
	if (divi < 1) answer[man] += price;
	else {
		answer[man] += price - divi;
		for (auto next : adj[man]) {
			dfs(adj, next, divi);
		}
	}
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	int size = enroll.size();
	for (int i = 0; i < size; i++) {
		string name = enroll[i];
		num[name] = i;
	}
	vector<vector<int>> adj(size + 1);
	answer.resize(size);
	// 나를 조직에 참여 시킨사람을 가리키도록 트리를 만들어야 함.
	// 추천인이 없으면 - 로 기입되고 그 위는 center 라고 생각해야 함.
	for (int i = 0; i < size; i++) {
		string name = enroll[i];
		string ref = referral[i];
		if (ref != "-") {
			adj[num[name]].push_back(num[ref]);
		}
	}
	int t = seller.size();
	for (int i = 0; i < t; i++) {
		string name = seller[i];
		int price = amount[i] * 100;
		dfs(adj, num[name], price);
	}

	return answer;
}

int main() {
	vector<int> v = solution(
		{ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" },
		{ "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" },
		{ "young", "john", "tod", "emily", "mary" },
		{ 12, 4, 2, 5, 10 }
	); // 360, 958, 108, 0, 450, 18, 180, 1080
	for(auto e: v)
	cout << e << ' ';
	return 0;
}
```



프로그래머스 2020 데브매칭, 다단계 칫솔 판매

