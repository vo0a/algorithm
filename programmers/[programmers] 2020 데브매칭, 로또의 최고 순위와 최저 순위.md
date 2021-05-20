## [programmers] 2020 데브매칭, 로또의 최고 순위와 최저 순위

[문제](https://programmers.co.kr/learn/courses/30/lessons/77484)



```c++
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int Rank[7] = { 6, 6, 5, 4, 3, 2, 1 };

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	map<int, int> my;
	for (int i = 0; i < 6; i++) {
		my[lottos[i]]++;
	}
	int correct = 0;
	for (int i = 0; i < 6; i++) {
		if (my.find(win_nums[i]) != my.end()) correct++;
	}
	answer.push_back(Rank[correct + my[0]] );
	answer.push_back(Rank[correct]);
	return answer;
}

int main() {
	vector<int> v = solution({ 45, 4, 35, 20, 3, 9}, { 20, 9, 3, 45, 4, 35 }); // 1, 1
	for(auto e: v)
	cout << e << ' ';
	return 0;
}
```



프로그래머스 2020 데브매칭, 로또의 최고 순위와 최저 순위

