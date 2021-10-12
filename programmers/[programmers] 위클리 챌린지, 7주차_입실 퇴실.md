## [programmers] 위클리 챌린지, 7주차_입실 퇴실

[문제](https://programmers.co.kr/learn/courses/30/lessons/86048)



```c++
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int Cnt[1001];

vector<int> solution(vector<int> enter, vector<int> leave) {
	vector<int> answer;
	int N = enter.size();
	map<int, int> room;

	int j = 0;
	for (int i = 0; i < N; i++) {
		int out = leave[i];
		if (!room.count(out)) {
			for (; j < N; j++) {
				if (out == enter[j]) { j++;  break; }
				room[enter[j]] = j;
			}
			Cnt[out] = room.size();
			for (auto e : room) {
				Cnt[e.first]++;
			}
			continue;
		}
		else {
			for (auto e : room) {
				if (e.first == out) Cnt[e.first] += room.size() - 1;
				else Cnt[e.first]++;
			}
			room.erase(out);
		}
	}

	for (int i = 1; i <= N; i++) {
		answer.push_back(Cnt[i]);
	}
	return answer;
}
```

- 입실 시각, 퇴실 시각이 주어졌을 때, 각 사람별로 반드시 만난 사람은 몇 명인지 구하는 문제

- room.size() 로 구하려고하니 반례가 존재해서 N^2 이 걸리더라도 일일이 ++로 1씩 증가시켰다.

- room 에는 입장한 사람이 저장되어 있는데, 반복문 기준을 퇴실자 순서대로 보기 때문에, room에서 퇴실자가 없다면 

  - enter 배열에서 현재 퇴실자를 만날때까지 room 에 저장한다.

  - 그렇게하면, room에 존재한 인원수가 퇴실자가 반드시 만나는 사람의 수가 되고 `Cnt[out] = room.size();`

  - 방에 있는 사람들은 퇴실자를 반드시 만난다.

    ```
    for (auto e : room) {
    	Cnt[e.first]++;
    }

- room에 현재 퇴실자가 존재한다면

  - 퇴실자가 반드시 만난 사람은 room.size() - 1 명이 추가되고

  - 퇴실자가 아닌 사람들은 퇴실자를 반드시 만나게 되므로 1씩 증가시킨다.

  - 그리고 퇴실자를 room에서 완전히 삭제함

    ```
    else {
        for (auto e : room) {
        	if (e.first == out) Cnt[e.first] += room.size() - 1;
        	else Cnt[e.first]++;
        }
        room.erase(out);
    }
    ```

- 이제 인원수를 Cnt 배열에 저장했으니 vector<>형태로 바꿔 반환한다.



프로그래머스 위클리 챌린지, 7주차_입실 퇴실

