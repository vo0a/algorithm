## [programmers] 완전탐색, 카펫

https://programmers.co.kr/learn/courses/30/lessons/42842



```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	vector<int> width, height;
	int total = brown + red;
	for (int i = 1; i <= sqrt(total); i++) {
		if (!(total % i)) {
			int tmp = total / i;
			if (i >= tmp) {
				width.push_back(i);
				height.push_back(tmp);
			}
			else {
				width.push_back(tmp);
				height.push_back(i);
			}
		}
	}
	
	for(int i = 0; i < width.size(); i++) {
		int w =width[i], h = height[i];
		if ((w * 2 + (h - 2) * 2) == brown && (w - 2) * (h - 2) == red) {
			answer.push_back(w);
			answer.push_back(h);
			break;
		}		
	}
	return answer;
}
```





프로그래머스 고득점 키트 완전탐색 카펫

