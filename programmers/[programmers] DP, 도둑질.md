## [programmers] DP, 도둑질

[문제](https://programmers.co.kr/learn/courses/30/lessons/42897)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000005];

int solution(vector<int> money) {
    int answer = 0;
    dp[1] = money[0];
    for(int i = 2; i <= money.size(); i++){
        dp[i] = max(dp[i - 1], dp[i- 2] + money[i - 1]);
    }
    answer = dp[money.size()];
    return answer;
}
```

이 코드부터 시작해서 모든 집들이 동그랗게 배치되어 있기 때문에 첫 번째 집을 포함하고있는 값을 판단하기 위해서 이차원 배열로 dp 배열을 변형했다.



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000005][2]; // maxSum, firstSelect
int dp2[1000005];

int solution(vector<int> money) {
    int answer = 0;
    dp[1][0] = money[0];
    dp[1][1] = 1;
    for(int i = 2; i <= money.size(); i++){
        if(i == money.size()){
            if(!dp[i - 2][1]){
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + money[i - 1]);
            }
            else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0]);
            }
            break;
        }
        if(dp[i - 1][0] > dp[i- 2][0] + money[i - 1]){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
        else {
            dp[i][0] = dp[i - 2][0] + money[i - 1];
            dp[i][1] = dp[i - 2][1];
        }        
    }
    
    dp2[money.size() - 1] = money[money.size() - 1];
    for(int i = money.size() -2 ; i > 0; i--){
        dp2[i] = max(dp2[i + 1], dp2[i + 2] + money[i]);
    }
    
    answer = max(dp[money.size()][0], dp2[1]);
    return answer;
}
```

> [10, 1, 1, 1, 1, 1, 100] 일 때, 102가 나와야 하지만 12가 나왔어서
>
> 
>
> ```c++
> int dp2[1000005];
> 
> ...
>     
> dp2[money.size() - 1] = money[money.size() - 1];
> for(int i = money.size() -2 ; i > 0; i--){
>     dp2[i] = max(dp2[i + 1], dp2[i + 2] + money[i]);
> }
> 
> answer = max(dp[money.size()][0], dp2[1]);
> ```
>
> dp2를 추가하여 무조건 마지막 집을 포함하는 경우도 같이 고려했다.
>
> 배열 두 개를 쓰기 싫어서 다른 방법이 있지 않을까 고민했는데 결국은 배열 두개를 이용하게 됐다.. 





### 다른 풀이

```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp1[1000005];
int dp2[1000005];
 
int solution(vector<int> money) 
{
    
    // 출발점 : 첫번째 집
    dp1[0] = money[0];
    dp1[1] = money[0];
    for(int i = 2; i < money.size()-1; i++)
    {
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    }
    
    // 출발점 : 두번째 집
    dp2[1] = money[1];
    for(int i = 2; i < money.size(); i++)
    {
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }
    
    return max(dp1[money.size()-2], dp2[money.size()-1]);
}
```

- 첫 번째 집을 포함하는 경우 마지막 집을 제외
- 두 번째 집을 포함하는 경우 마지막 집을 포함

이 두 경우로 나눠서 풀면 간단히 풀린다.





프로그래머스 고득점 키트 DP 도둑질

