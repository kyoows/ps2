#include <stdio.h>
#include <string.h>
int main()
{
    int cnt;
    int i, j, k;
    char map[10][10];
    for (i = 0; i < 8; i++) {
        scanf("%s", map[i]);
    }
    cnt = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (((i+j)%2 == 0) && map[i][j] == 'F')
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
