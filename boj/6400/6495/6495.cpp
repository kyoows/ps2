/*
6495 - Ballot evaluation
5472473 helloneo 6495 맞았습니다!! 2028 KB 72 MS C++14 / 수정 2461 B
2017-03-26
*/
#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
map<string, double> mm;
int main()
{
    int n, m;
    int sym;
    int i;
    char buf[10010];
    double res, temp;
    scanf("%d%d", &n, &m);
    mm.clear();
    for (i = 0; i < n; i++) {
        scanf("%s%lf", buf, &temp);
        mm[buf] = temp;
    }
    for (i = 0; i < m; i++) {
        res = 0;
        while (1) {
            scanf("%s", buf);
            if (!strcmp(buf, "=")) {
                sym = 1;
                break;
            }
            if (!strcmp(buf, ">")) {
                sym = 2;
                break;
            }
            if (!strcmp(buf, "<")) {
                sym = 3;
                break;
            }
            if (!strcmp(buf, ">=")) {
                sym = 4;
                break;
            }
            if (!strcmp(buf, "<=")) {
                sym = 5;
                break;
            }

            if (!strcmp(buf, "+")) {
            }
            else {
                res = res + mm[buf];
            }
        }
        scanf("%lf", &temp);
        switch (sym) {
            case 1:
                if (fabs(res-temp) < 1e-12)
                    printf("Guess #%d was correct.\n", i+1);
                else
                    printf("Guess #%d was incorrect.\n", i+1);
                break;
            case 2:
                if (res > temp+1e-12)
                    printf("Guess #%d was correct.\n", i+1);
                else
                    printf("Guess #%d was incorrect.\n", i+1);
                break;
            case 3:
                if (res < temp-1e-12)
                    printf("Guess #%d was correct.\n", i+1);
                else
                    printf("Guess #%d was incorrect.\n", i+1);
                break;
            case 4:
                if (res+1e-12 > temp)
                    printf("Guess #%d was correct.\n", i+1);
                else
                    printf("Guess #%d was incorrect.\n", i+1);
                break;
            case 5:
                if (res < temp+1e-12)
                    printf("Guess #%d was correct.\n", i+1);
                else
                    printf("Guess #%d was incorrect.\n", i+1);
                break;
        }

    }
    return 0;
}
