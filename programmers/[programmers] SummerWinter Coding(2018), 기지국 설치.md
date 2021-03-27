## [programmers] Summer/Winter Coding(2018), 기지국 설치

[문제](https://programmers.co.kr/learn/courses/30/lessons/12979)



```c++
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ans = 0;       
    vector<pair<int, int>> v; //전파가 안통하는 구간(st, end)
    if(stations[0] - w - 1 >= 1)
        v.push_back({1, stations[0] - w - 1});
    for(int i = 1; i < stations.size(); i++){
        int st = stations[i - 1] + w + 1;
        int ed = stations[i] - w - 1;
        if(st <= ed) v.push_back({st, ed});       
    }
    if(stations[stations.size() - 1] + w + 1 <= n)
        v.push_back({stations[stations.size() - 1] + w + 1, n});
    
    for(auto e: v){
        int len = e.second - e.first + 1;
        if(len <= w * 2 + 1) ans++;
        else{
            ans += len/(w * 2 + 1);
            if(len % (w * 2 + 1)) ans++;
        }           
    }  

    return ans;
}
```

- 그리디
- N범위가 크기 때문에(2 * 10의8승) stations(최대 10000개)를 가지고 전파가 안통하는 구간을 구한다.
- 각각 전파가 안통하는 구간의 길이를 확인하면서 기지국을 몇개 세워야하는지 알 수 있다. 



프로그래머스 Summer/Winter Coding(2018) 기지국 설치

