/*
12400 - Speaking in Tongues (Small)
5423438 helloneo 12400 ¸Â¾Ò½À´Ï´Ù!! 1116 KB 0 MS C / ¼öÁ¤ 1010 B
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int tc, cn;
    int i, j, k;
    int len;
    char buf[110];
    char map[128];

    map[' '] = ' ';
    map['a'] = 'y';
    map['c'] = 'e';
    map['d'] = 's';
    map['e'] = 'o';
    map['f'] = 'c';
    map['g'] = 'v';
    map['h'] = 'x';
    map['i'] = 'd';
    map['j'] = 'u';
    map['k'] = 'i';
    map['l'] = 'g';
    map['m'] = 'l';
    map['n'] = 'b';
    map['o'] = 'k';
    map['p'] = 'r';
    map['r'] = 't';
    map['s'] = 'n';
    map['t'] = 'w';
    map['u'] = 'j';
    map['v'] = 'p';
    map['w'] = 'f';
    map['x'] = 'm';
    map['y'] = 'a';

    map['b'] = 'h';
    map['q'] = 'z';
    map['z'] = 'q';

    scanf("%d", &tc);
    gets(buf);
    for (cn = 1; cn <= tc; cn++) {
        gets(buf);
        len = strlen(buf);
        printf("Case #%d: ", cn);
        for (i = 0; i < len; i++) {
            printf("%c", map[buf[i]]);
        }
        printf("\n");
    }
    return 0;
}