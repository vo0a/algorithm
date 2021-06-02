## [programmers] 2020 kakao, 외벽 점검

[문제](https://programmers.co.kr/learn/courses/30/lessons/60062)



```c++
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define INF 1e9
int N, MinCnt;
vector<int> Weak, Dist;

void solve(int cnt, int pos, int visited){
    if(cnt > Dist.size()) return;
    if(cnt >= MinCnt) return;
    
    for(int i = 0; i < Weak.size(); i++) {
        int nextPos = (pos + i) % Weak.size();
        int diff = Weak[nextPos] - Weak[pos];
        if(nextPos < pos) diff += N;
        
        if(diff > Dist[Dist.size() - cnt]) break;
        visited |= 1 << nextPos;
    }
    
    if(visited == (1 << Weak.size()) - 1) {
        // MinCnt = min(MinCnt, cnt);
        // 12 번줄로 가지치기를 해서 min으로 감싸지 않아도 됨
        MinCnt = cnt;
        return;
    }
    
    for(int i = 0; i < Weak.size(); i++) {
        if(visited & (1 << i)) continue;
        solve(cnt + 1, i, visited);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end());
    N = n;
    Weak = weak;
    Dist = dist;
    MinCnt = INF;
    
    for(int i = 0; i < weak.size(); i++) {
        solve(1, i, 0);
    }
    
    if(MinCnt == INF) MinCnt = -1;
    return MinCnt;
}
```



프로그래머스 2020 kakao, 외벽 점검

