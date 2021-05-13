## [programmers] 2020 kakao 인턴, 키패드 누르기

[문제](https://programmers.co.kr/learn/courses/30/lessons/67256)



```c++
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int, pair<int, int>> arr = { {1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}},
{4,{1, 0}}, {5, {1, 1}}, {6, {1, 2}},
{7,{2, 0}}, {8, {2, 1}}, {9,{2, 2}},
{0, {3, 1}} };

string solution(vector<int> numbers, string hand) {
	string answer = "";
	pair<int, int> Right = { 3,0 }, Left = { 3, 2 };
	for (int i = 0; i < (int)numbers.size(); i++) {
		int n = numbers[i];
		if (n == 1 || n == 4 || n == 7) {
			answer += 'L';
			Left = { arr[n].first, arr[n].second };
		}
		else if (n == 3 || n == 6 || n == 9) {
			answer += 'R';
			Right = { arr[n].first, arr[n].second };
		}
		else { // 더 가까운쪽 손으로 클릭. 
			int distL = abs(Left.first - arr[n].first) + abs(Left.second - arr[n].second);
			int distR = abs(Right.first - arr[n].first) + abs(Right.second - arr[n].second);
			if (distL < distR) {
				answer += 'L';
				Left = { arr[n].first, arr[n].second };
			}
			else if (distR < distL) {
				answer += 'R';
				Right = { arr[n].first, arr[n].second };
			}
			else { // 거리가 같다면 오른손잡이, 왼손잡이로 선택
				if (hand == "right") {
					answer += "R"; Right = { arr[n].first, arr[n].second };
				}
				else {
					answer += "L"; Left = { arr[n].first, arr[n].second };
				}
			}
		}
	}
	return answer;
}

int main() {
	string v = solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
	cout << v;

	return 0;
}
```





프로그래머스 2020 kakao 인턴, 키패드 누르기

