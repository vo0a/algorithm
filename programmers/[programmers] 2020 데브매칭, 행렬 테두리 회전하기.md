## [programmers] 2020 데브매칭, 행렬 테두리 회전하기

[문제](https://programmers.co.kr/learn/courses/30/lessons/77485)



```c++
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int arr[102][102];
int pre[4];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	int num = 1;
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= columns; j++) {
			arr[i][j] = num++;
		}
	}

	int t = queries.size();
	int cnt = 0;
	while (t--) {
		int Min = 10001;
		int stx = queries[cnt][0], sty = queries[cnt][1], edx = queries[cnt][2], edy = queries[cnt][3];
		// 열 이동
		pre[0] = arr[stx][edy];
		for (int j = edy; j > sty; j--) {
			arr[stx][j] = arr[stx][j - 1];
			Min = min(Min, arr[stx][j]);
		}
		// 행 이동
		pre[1] = arr[edx][edy];
		for (int i = edx; i > stx + 1; i--) {
			arr[i][edy] = arr[i - 1][edy];
			Min = min(Min, arr[i][edy]);
		}
		arr[stx + 1][edy] = pre[0];
		// 열 이동
		pre[2] = arr[edx][sty];
		for (int j = sty; j < edy - 1; j++) {
			arr[edx][j] = arr[edx][j + 1];
			Min = min(Min, arr[edx][j]);
		}
		arr[edx][edy - 1] = pre[1];
		// 행 이동
		for (int i = stx; i < edx - 1; i++) {
			arr[i][sty] = arr[i + 1][sty];
			Min = min(Min, arr[i][sty]);
		}
		arr[edx - 1][sty] = pre[2];
		Min = min(Min, min(pre[0], min(pre[1], pre[2])));
		answer.push_back(Min);
		cnt++;
	}

	return answer;
}

int main() {
	vector<int> v = solution(6, 6, { { 2, 2, 5, 4 }, { 3, 3, 6, 6 }, {5, 1, 6, 3} }); // 8, 10, 25
	for(auto e: v)
	cout << e << ' ';
	return 0;
}
```



프로그래머스 2020 데브매칭, 행렬 테두리 회전하기

