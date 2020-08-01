## [programmers] DFS/BFS, 단어변환

[문제](https://programmers.co.kr/learn/courses/30/lessons/43163#)



```c++
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int ans = 1e9, flg, chk[51];

void go(string cur, string target, vector<string> words, int cnt){
    if(cur == target){
        flg = true;
        ans = min(cnt, ans);
        return;
    }
    
    for(int i = 0; i< words.size(); i++){
        if(chk[i]) continue;
        int diff = 0;
        for(int j = 0; j < words[i].size(); j++){
            if(cur[j] != words[i][j]){
                diff++;
            }
        }
        if(diff == 1) {
            chk[i] = 1;
            go(words[i],target, words, cnt+1);
            chk[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    go(begin, target, words, 0);
    if(!flg) ans = 0;
    
    return ans;
}
```





프로그래머스 고득점 키트 DFS/BFS 단어변환

