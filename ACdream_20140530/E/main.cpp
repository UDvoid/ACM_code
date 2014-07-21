#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int a[1000001] = {0};
int b[1000001] = {0};
int main()
{
    scanf("%d",&t);
    int i;
    for(i = 0; i < t; i++)
        scanf("%d",&a[i]);
    for(i = 0; i < t - 1; i++)
        scanf("%d",&b[i]);
    sort(a, a + t);
    sort(b, b + t - 1);
    for(i = 0;i < t - 1;i++)
        if(a[i] != b[i])
            break;
    printf("%d\n",a[i]);
    return 0;
}
