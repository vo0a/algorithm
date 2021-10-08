## [programmers] 위클리 챌린지, 8주차_최소직사각형

[문제](https://programmers.co.kr/learn/courses/30/lessons/86491)



```c++
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int width = 0, height = 0;
    for(int i = 0; i < sizes.size(); i++) {
        int w = sizes[i][0], h = sizes[i][1];
        
        if(w >= h) {
            width = max(width, w);
            height = max(height, h);
        }
        else {
            width = max(width, h);
            height = max(height, w);
        }        
    }
    
    return width * height;
}
```

- 명함들이 주어지면, 명함 모두를 넣을 수 있는 지갑의 크기를 구하려고 한다. 
- 이때 명함을 적절히 돌려서 지갑의 최소 사이즈를 구해야 한다.
- 적절히 돌리는게 무엇일까 생각해 봤는데, sizes의 길이가 최대 10000 이기 때문에 브루트 포스는 안될 거라고 생각을 했고, 무조건 가로, 세로 길이 중 큰 것 끼리의 MAX를 구하는건 어떨까 생각하고 문제를 풀게 되었다.



프로그래머스 위클리 챌린지, 8주차 최소직사각형

