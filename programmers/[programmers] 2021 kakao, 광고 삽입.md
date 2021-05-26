## [programmers] 2021 kakao, 광고 삽입

[문제](https://programmers.co.kr/learn/courses/30/lessons/72414)



```c++
#include <iostream>
#include <vector>
#include <string>
#define MAX 360000 // 99:59:59초
using namespace std;

int strToSec(string S) {
	int hour = stoi(S.substr(0, 2)) * 3600;
	int minute = stoi(S.substr(3, 2)) * 60;
	int sec = stoi(S.substr(6));

	int total = hour + minute + sec;
	return total;
}

string secToStr(int T) {
	string S = "";
	int hour = T / 3600;
	int minute = (T % 3600) / 60;
	int sec = T % 60;

	if (hour <= 9) S += "0";
	S += to_string(hour) + ":";
	if (minute <= 9) S += "0";
	S += to_string(minute) + ":";
	if (sec <= 9) S += "0";
	S += to_string(sec);
	return S;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	int Play_Time = strToSec(play_time);
	int Adv_Time = strToSec(adv_time);

	vector<int> total_Play_Time(MAX, 0);
	for (string log : logs) {
		int Start = strToSec(log.substr(0, 8));
		int End = strToSec(log.substr(9));
		for (int j = Start + 1; j <= End; j++) 
			total_Play_Time[j]++;
	}

	long long cur = 0, Max = 0;
	int Time = 1;
	// 초기화 : 0초에 광고를 삽입할 경우
	for (int i = 1; i <= Adv_Time; i++) {
		cur += total_Play_Time[i];
	}
	Max = cur;
	// 1초부터 광고가 들어갈 수 있는 시간까지 광고를 모두 삽입해봄
	for (int i = 2; i <= (Play_Time - Adv_Time + 1); i++) {
		cur += (long long)(total_Play_Time[i + Adv_Time - 1] - total_Play_Time[i - 1]);
		if (cur > Max) {
			Max = cur;
			Time = i;
		}
	}
	answer = secToStr(Time - 1);
	return answer;
}
```



프로그래머스 2021 kakao, 광고 삽입

