## [programmers] Summer/Winter Coding(2019) 멀쩡한 사각형

[문제](https://programmers.co.kr/learn/courses/30/lessons/62048)



```c++
using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    for(int i = 0; i < w; i++){
        answer += ((long long)h * (long long)i) / w;
    }
    return answer * 2;
}
```





프로그래머스 Summer/Winter Coding(2019) 멀쩡한 사각형

