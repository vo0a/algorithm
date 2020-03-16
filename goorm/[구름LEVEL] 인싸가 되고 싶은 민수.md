## [구름LEVEL] 인싸가 되고 싶은 민수

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | 40.6%  |





```c++
#include <iostream>
using namespace std;
int a, b;
int leastDivisor(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (!(num % i)) return i;
	}
	return num;
}
int main() {
	scanf("%d %d", &a, &b);

	if (a != b) printf("2");
	else printf("%d", leastDivisor(a));

	return 0;
}
```





구름LEVEL 인싸가 되고 싶은 민수 goorm goormlevel

