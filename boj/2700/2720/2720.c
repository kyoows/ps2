/*
 * 2720 - Quick Change
 * 91781097 helloneo 2720 맞았습니다!! 1112 0 C99
 */
/*
3389 - Quick Change
2006-11-04 02:55:22  Accepted 0.004 Minimum 4653 C
*/
#include <stdio.h>
int main()
{
	int t, cn;
	int cnt[4], n;
	scanf("%d", &t);
	cn = 1;
	while (t--) {
		scanf("%d", &n);
		cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
		cnt[0] = n / 25;
		n %= 25;
		cnt[1] = n / 10;
		n %= 10;
		cnt[2] = n / 5;
		n %= 5;
		cnt[3] = n;
		printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
	}
	return 0;
}