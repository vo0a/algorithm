## [programmers] 2018 kakao, 추석 트래픽

[문제](https://programmers.co.kr/learn/courses/30/lessons/17676)



```c++
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start, end;
    
    for(auto line : lines){
        string h, m, s, ms;
        int ih, im, is, process;
        
        line.pop_back(); // s제외
        h = line.substr(11, 2);
        m = line.substr(14, 2);
        s = line.substr(17, 2);
        ms = line.substr(20, 3);
        // 처리량을 ms로 표현
        process = stof(line.substr(24)) * 1000; 
        ih = stoi(h) * 3600 * 1000;
        im = stoi(m) * 60 * 1000;
        is = stoi(s) * 1000 + stoi(ms);
        
        start.push_back(ih + im + is - process + 1);
        end.push_back(ih + im + is);
    }
    
    for(int i = 0; i < lines.size(); i++){
        int end_time = end[i] + 1000; // 1초간 처리량 구하기
        int cnt = 0;
        for(int j = i; j < lines.size(); j++){
            if(start[j] < end_time) cnt++;
            //else break; -> 하면 틀림 정렬한게 아니기 때문에
        }
        if(answer < cnt) answer = cnt;
    }
    
    return answer;
}
```





프로그래머스 2018 KAKAO BLIND RECRUITMENT [1차] 추석 트래픽

