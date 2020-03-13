## [구름LEVEL] A4 용지를 만들자

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | 40%    |





```c++
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll n, m, a, b, square;
int main() {
	scanf("%lld %lld", &n, &m);

	a = (n / 40) * (m / 20);
	b = (m / 40) * (n / 20);
	
	square = 2 * (n / 40) * (m / 40);
	printf("%lld", a + b - square);
	return 0;
}
```





구름LEVEL A4 용지를 만들자 goorm goormlevel

