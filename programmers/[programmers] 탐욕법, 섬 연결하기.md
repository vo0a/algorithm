## [programmers] 탐욕법, 섬 연결하기

[문제](https://programmers.co.kr/learn/courses/30/lessons/42861#)



```c++
#include <string>
#include <vector>
#include <algorithm>

#define max_int 101
using namespace std;

//시간 복잡도: O(elogn) (n: 정점의 개수, e: 간선의 개수)
//공간 복잡도: O(en)
//사용한 알고리즘: 크루스칼 알고리즘
//사용한 자료구조: 인접리스트


// d[i]는 정점 i의 부모 정점을 넣는다.
int d[max_int];


// find는 최상위 부모를 찾는 함수 - Find
int find(int node){
    // 1) 만약 부모가 자기자신이면 현재 노드가 최상위 부모이다.
    if(node == d[node]) return node;
  
    // 2) 아니라면 최상위 부모의 부모를 찾는다. 
    else return d[node] = find(d[node]);
}


// 간선의 가중치를 기준으로 오름차순 정렬
bool cmp(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 1. d[i] = i의 부모를 담는다. 처음에는 자기 자신이 부모이다.
 	// disjoint-set을 사용하기 위해 초기화
    for(int i=0; i<n; i++){ 
        d[i] = i;
    }
    
  
    // 2. 간선의 가중치 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);
    
  
    // 3. 모든 간선을 검사한다.
    for(int i=0; i<costs.size(); i++){
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int cost = costs[i][2];
        
      
        // 4. start와 end가 아직 연결되지 않았다면
        if(start != end){
            // 1) start의 부모를 end로 설정하고 - Union
            d[start] = end;
          
            // 2) 간선의 가중치를 결과에 더해준다.
            answer += cost;
        }
    }
    
    return answer;
}
```

[출처]([https://velog.io/@skyepodium/programmers-%EC%84%AC%EC%97%B0%EA%B2%B0%ED%95%98%EA%B8%B0](https://velog.io/@skyepodium/programmers-섬연결하기))

> 한줄요약: 1) 크루스칼 알고리즘으로, 2) 최소 스패닝 트리를 만든다.
>
> - 최소 스패닝 트리
>   정점이 n개인 그래프의 간선중 일부인 n-1개의 간선을 선택해서 모든 정점을 연결한 트리중 가중치의 합이 최소인 트리
> - 크루스칼 알고리즘
>   최소 스패닝 트리를 찾는 알고리즘



`최소 스패닝 트리`, `크루스칼 알고리즘`, `유니온 파인드` 각각 들어보긴 했지만 연결이 안됐었는데 블로그를 찾아보고 알게 되었다. 

최소 스패닝 트리를 만들기 위한 것이 크루스칼 알고리즘이고, 크루스칼 알고리즘이 유니온 파인드다!



프로그래머스 고득점 키트 탐욕법 섬 연결하기

