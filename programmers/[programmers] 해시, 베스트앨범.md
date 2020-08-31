## [programmers] 해시, 베스트앨범

[문제](https://programmers.co.kr/learn/courses/30/lessons/42579)



```c++
#include <string>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
typedef pair<int, int> p;

struct Album {
	int playCnt;
	vector<p> play;
};

Album album[MAX];

int getHashKey(string str) {
	int key = 0;
	for (int i = 0; str[i]; ++i) {
		key *= 26;
		key += str[i] - 'a';
	}
	return key % MAX;
}

bool cmp(const Album& p1, const Album& p2) {
	return p1.playCnt > p2.playCnt;
}

bool cmp2(const p& p1, const p& p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	else return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	for (int i = 0; i < genres.size(); i++) {
		int position = getHashKey(genres[i]);
		album[position].playCnt += plays[i];
		album[position].play.push_back({ plays[i], i });
	}

	sort(album, album + MAX, cmp);

	for (int i = 0; i < MAX; i++) {
		if (!album[i].playCnt) break;
		sort(album[i].play.begin(), album[i].play.end(), cmp2);
		answer.push_back(album[i].play[0].second);
		if(album[i].play.size() >= 2)
			answer.push_back(album[i].play[1].second);
	}
	return answer;
}
```





프로그래머스 고득점 키트 해시 베스트앨범

