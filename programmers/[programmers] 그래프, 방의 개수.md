## [programmers] 그래프, 방의 개수

[문제](https://programmers.co.kr/learn/courses/30/lessons/49190?language=cpp#)



## 시행착오

```c++
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> p;
map<p, int> m;
int dir[][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int solution(vector<int> arrows) {
	int answer = 0;
	p cur = { 0, 0 };
	m[cur] = 1;
	for (auto d : arrows) {
		cur.first += dir[d][0], cur.second += dir[d][1];
		m[cur]++;
	}

	for (auto e : m) {
		if (e.second > 2) answer += (e.second - 1);
		else if (e.second == 2) answer++;
	}
	return answer;
}
```

정점을 지날 때마다 m[cur] 의 개수를 ++시켜서 두 번 이상 지났는지 확인하여 방의 개수를 세려고 했다.

그런데 간선을 고려하지 않은 채 정점 방문 횟수로만 문제를 푸려니 틀려서 고민하다가 답을 찾아봤다.



## 정답 코드

```c++
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
 
int solution(vector<int> arrows) 
{
    int roomCnt = 0;
    map<pair<int, int>, int> vertex_visited;
    map<pair<pair<int, int>, pair<int, int>>, int> edge_visited;
 
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int x = 0;
    int y = 0;
    vertex_visited[{x, y}] = 1;
    for(int i = 0; i < arrows.size(); i++)
    {
        // X자의 교차 형태도 세줘야해서 2배
        for(int j = 0; j < 2; j++)
        {
            int xpos = x + dx[arrows[i]];
            int ypos = y + dy[arrows[i]];
            
            if(vertex_visited[{xpos, ypos}] == 1)
            {
                if(edge_visited[{{x, y}, {xpos, ypos}}] == 0 || edge_visited[{{xpos, ypos}, {x, y}}] == 0)
                {
                    roomCnt++;
                }
            }
 
            // vertex 체크
            vertex_visited[{xpos, ypos}] = 1;
            
            // edge 체크
            edge_visited[{{x, y}, {xpos, ypos}}] = 1;
            edge_visited[{{xpos, ypos}, {x, y}}] = 1;
            
            x = xpos;
            y = ypos;            
        }   
    }
 
    return roomCnt;
}
```

[출처](https://coding-insider.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-5-%EB%B0%A9%EC%9D%98-%EA%B0%9C%EC%88%98-CC-%E2%98%85%E2%98%85%E2%98%85)

답을 보고 나서도 'X자의 교차 형태도 세줘야 해서 2배' 가 잘 이해되지 않아 많이 생각해 봤다.



![화면 캡처 2020-09-17 170610](https://user-images.githubusercontent.com/44438366/93454301-c2707200-f915-11ea-9b29-004f1121ae18.png)

위와 같은 경우, 

- 주어진 도형의 한 변의 길이가 1인 삼각형 교차로 주어지게 되면 
  - 코드에서는 방이 2개라고 인식한다.
- 주어진 도형의 한 변의 길이가 1인 삼각형을 2배로 늘려 저장하게 되면
  - 교차되는 지점에 점이 생기게 되므로 코드에서 방이 3개라고 알 수 있다.

이렇게 그림을 그려보면서 코드를 이해할 수 있었다.





프로그래머스 고득점 키트 그래프 방의 개수

