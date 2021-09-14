## [programmers] 위클리 챌린지, 1주차_부족한 금액 계산하기

[문제](https://programmers.co.kr/learn/courses/30/lessons/82612?language=cpp)



```c++
using namespace std;

long long solution(int price, int money, int count)
{    
    long long Price = 0;
    int cnt = 1;
    while(count--) {
        Price += (price * cnt);
        cnt++;
    }
    
    if(money >= Price) return 0;
    return Price - money;
}
```

- 놀이기구를 N번째 이용하면 원래 이용료의 N배를 받기로 했다.
- 놀이기구를 count 번 타게 되면 현재 자신이 가지고 있는 금액에서 얼마가 모자라는지 return 하는 문제. 금액이 부족하지 않으면 0을 반환함



프로그래머스 위클리 챌린지, 1주차_부족한 금액 계산하기

