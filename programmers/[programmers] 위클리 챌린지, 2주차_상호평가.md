## [programmers] 위클리 챌린지, 2주차_상호평가

[문제](https://programmers.co.kr/learn/courses/30/lessons/83201)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char Grade(int average) {
    if(average >= 90) return 'A';
    else if(average >= 80) return 'B';
    else if(average >= 70) return 'C';
    else if(average >= 50) return 'D';
    else return 'F';
}

vector<vector<int>> Scores;
int Average(int student_num) {
    vector<pair<int, int>> score;
    int sum = 0, num = Scores.size();
    for(int i = 0; i < Scores.size(); i++) {
        score.push_back({Scores[i][student_num], i});
        sum += Scores[i][student_num];
    }
    
    sort(score.begin(), score.end());
    
    if(score[0].second == student_num && score[1].first != score[0].first) {
        sum -= score[0].first; num--;
    }
    else if(score[num - 1].second == student_num
       && score[num - 1].first != score[num - 2].first) {
        sum -= score[num - 1].first; num--;
    }
    
    return sum/num;
}

string solution(vector<vector<int>> scores) {
    Scores = scores;
    string answer = "";
    
    for(int i = 0; i < scores.size(); i++) {
        int avg = Average(i);
        answer += Grade(avg);
    }
    
    return answer;
}
```

- N*N 표가 주어지고, i행, j열에는 i 번째 학생이 j 번째 학생을 평가한 점수가 담겨있다.
- 각 학생들이 받은 점수의 평균을 구하여 기준에 따라 학점을 부여하는 문제이다.
- 단, 학생들이 자기 자신을 평가한 점수가 `유일한 최고점` 또는 `유일한 최저점`이면 그 점수는 제외하고 평균을 구해야 한다.
- 2 ≤ `scores`의 행의 길이(학생 수) ≤ 10 인 조건이 있어서 score의 사이즈를 고려하지 않고 풀 수 있었다.



프로그래머스 위클리 챌린지, 2주차_상호평가

