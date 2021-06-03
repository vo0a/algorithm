## [programmers] 2020 kakao, 블록 이동하기

[문제](https://programmers.co.kr/learn/courses/30/lessons/60063)



```c++
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct Point {
    int row, col, dir, time;
};

int D[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int Drot[2][4][2] = {{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}},
                     {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}}};
int Dcor[2][4][2] = {{{-1, 1}, {1, 1}, {1, -1}, {-1, -1}},
                     {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}}};

vector<vector<int>> Board;
int N;
queue<pair<Point, Point>> Q;
bool visited[100][100][4]; // up, right, down, left

bool isValid(Point pt[2]) {
    for (int i = 0; i < 2; i++){
        if (pt[i].row < 0 || pt[i].row > N - 1 || pt[i].col < 0 || pt[i].col > N - 1) return false;
        if (Board[pt[i].row][pt[i].col]) return false;
        if (visited[pt[i].row][pt[i].col][pt[i].dir]) return false;
    }
    return true;
}

int rotate(Point curr[2], int ccw, int idx) {
    Point newPt[2];
    int a = idx, b = (idx + 1) % 2;
    int dir = curr[a].dir; // 회전축의 방향
    newPt[0] = { curr[a].row, curr[a].col, 
                (curr[a].dir + (ccw ? 3 : 1)) % 4, curr[a].time + 1 };
    newPt[1] = { curr[b].row + Drot[ccw][dir][0], curr[b].col + Drot[ccw][dir][1], 
                (curr[b].dir + (ccw ? 3 : 1)) % 4, curr[b].time + 1 };
    if (isValid(newPt) == false) return 0;
    if (Board[curr[a].row + Dcor[ccw][dir][0]][curr[a].col + Dcor[ccw][dir][1]] == 1) return 0;
    
    for (int i = 0; i < 2; i++) {
        if ( newPt[i].row == N - 1 && newPt[i].col == N - 1) return newPt[i].time;
        visited[newPt[i].row][newPt[i].col][newPt[i].dir] = true;
    }
    Q.push({newPt[a], newPt[b]});
    return 0;
}


int solution(vector<vector<int>> board) {
	Board = board;
    N = board.size();
	
    Q.push({{0, 0, RIGHT, 0}, {0, 1, LEFT, 0}});
    visited[0][0][RIGHT] = true;
    visited[0][1][LEFT] = true;
    
    while(!Q.empty()) {
        Point curr[2], newPt[2];
        curr[0] = Q.front().first;
        curr[1] = Q.front().second;
        Q.pop();
        
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 2; i++){
                newPt[i] = {curr[i].row + D[j][0], curr[i].col + D[j][1], 
                            curr[i].dir, curr[i].time + 1};
            }
            
            if (isValid(newPt) == false) continue;
            
            for (int i = 0; i < 2; i++) {
                if(newPt[i].row == N - 1 && newPt[i].col == N - 1) return newPt[i].time;
                visited[newPt[i].row][newPt[i].col][newPt[i].dir] = true;
            }
            Q.push({newPt[0], newPt[1]});
        }
        
        // 회전
        // 0 시계방향, 1 반시계 방향
        for (int ccw = 0; ccw < 2; ccw++) {
            // 회전 축
            for(int i = 0; i < 2; i++) {
                int ret = rotate(curr, ccw, i);
                if (ret) return ret;
            }
        }
        
    }
}
```



프로그래머스 2020 kakao, 블록 이동하기

