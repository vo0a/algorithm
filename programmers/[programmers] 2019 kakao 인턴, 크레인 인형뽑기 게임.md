## [programmers] 2019 kakao 인턴, 크레인 인형뽑기 게임

[문제](https://programmers.co.kr/learn/courses/30/lessons/64061)



```c++
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> doll;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int N = board.size();
    
    for(auto position : moves) {
        for(int i = 0; i < N; i++) {
            if(board[i][position - 1] != 0) {
                doll.push_back(board[i][position - 1]);
                board[i][position - 1] = 0;
                break;
            }
        }
        
        if(doll.size() < 2) continue;
        if(doll[doll.size() - 1] == doll[doll.size() - 2]) {
            doll.pop_back();
            doll.pop_back();
            answer += 2;
        }
    }
    
    return answer;
}
```

