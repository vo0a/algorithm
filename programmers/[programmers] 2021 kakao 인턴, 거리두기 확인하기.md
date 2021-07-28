## [programmers] 2021 kakao 인턴, 거리두기 확인하기

[문제](https://programmers.co.kr/learn/courses/30/lessons/81302#)



```c++
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int arr[5][5], chk[5][5];
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

bool BFS(int x, int y) {
    memset(chk, 0, sizeof(chk));
    queue<pair<int, int>> q;
    q.push({x, y});
    chk[x][y] = 1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int cnt = chk[r][c];
        
        for(int i =0; i <4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0|| nc < 0|| nr >= 5 || nc >= 5 || chk[nr][nc] || arr[nr][nc] == 'X') continue;
            if(arr[nr][nc] == 'P' && cnt + 1 <= 3) return false;
            chk[nr][nc] = cnt + 1;
            q.push({nr, nc});
        }
        
    }
    return true;
}

int go(vector<string>& place) {
    for(int i = 0; i < place.size(); i++) {
        for( int j = 0; j < 5; j++) {
            arr[i][j] = place[i][j];
        }
    }
    
    for(int i = 0; i < place.size(); i++) {
        for( int j = 0; j < 5; j++) {
            if(arr[i][j] == 'P') {
                if(!BFS(i, j)) return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto& place : places){
        answer.push_back(go(place));
    }
    return answer;
}
```



프로그래머스 2021 kakao 인턴, 거리두기 확인하기

