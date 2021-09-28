## [programmers] 위클리 챌린지, 6주차_복서 정렬하기

[문제](https://programmers.co.kr/learn/courses/30/lessons/85002?language=cpp)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 이긴 횟수, 몸무게가 무거운 복서를 이긴 횟수, 자기 몸무게
typedef struct {
    int num;
    double winRate;
    int heavyWin, weight;
} info;
bool cmp(const info &a, const info &b) {
    if(a.winRate == b.winRate) {
        if(a.heavyWin == b.heavyWin) {
            if(a.weight == b.weight)
                return a.num < b.num;
            else return a.weight > b.weight;
        }
        else return a.heavyWin > b.heavyWin;
    }
    else return a.winRate > b.winRate;
}

vector<info> result;
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    
    for(int i = 0; i < head2head.size(); i++) {
        int weight = weights[i];
        int win = 0, lose = 0, hwin = 0;
        for(int j = 0; j < head2head[i].size(); j++) {
            if(head2head[i][j] == 'W') {
                win++;
                if(weights[j] > weight) hwin++;
            }
            else if(head2head[i][j] == 'L') lose++;
        }
        double winRate = win > 0 ? (win / (double)(win + lose)) : 0;
        result.push_back({i + 1, winRate, hwin, weight});
    }
    sort(result.begin(), result.end(), cmp);
    
    for(auto e : result) {
        answer.push_back(e.num);
    }
    return answer;
}
```

- 정렬해서 출력하는 문제
- 정렬기준은
  1. 승률 내림차순(이긴 횟수가 없으면 0)
  2. 자신보다 몸무게가 무거운 복서를 이긴 횟수가 많은 순
  3. 몸무게 내림차순
  4. 복서의 번호 오름차순



프로그래머스 위클리 챌린지, 6주차_복서 정렬하기

