/*
 * 29881 - Account Names
 * 89310964 helloneo 29881 맞았습니다!! 1232 0 C++17
 */
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int main()
{
    int n, i;
    map<string, string> dataset;
    char str1[50], str2[50];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s%s", str1, str2);
        dataset[str1] = str2;
    }
    for (i = 0; i < n; i++) {
        scanf("%s%s", str1, str2);
        printf("%s %s\n", dataset[str1].c_str(), str2);
    }
    return 0;
}
