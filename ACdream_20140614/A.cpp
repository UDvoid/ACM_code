/*****************************************************
Author:		:UDvoid
Create time	:2014-06-14-19.28
*****************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int n;
const int ma = 5000005;
long long a[ma];
int part(int l, int r)
{
    int i, j, x;
    i = l;
    j = r;
    x = a[l];
    while(i < j)
    {
        while(a[j] <= x && i < j) j--;
        a[i] = a[j];
        while(a[i] >= x && i < j) i++;
        a[j] = a[i];
    }
    a[i] = x;
    return i;
}
void work(int l, int r, int k)
{
    int t;
    t = part(l, r);
    if(k == t - l + 1)
    {
        printf("%lld\n",a[t]);
        return;
    }else if(k > t - l + 1)
    {
        k = k - t + l - 1;
        work(t + 1, r, k);
    }else
        work(l, t - 1, k);
    return;
}
int scan( )
{
    char ch[10];
    int m, num, bit;
    m = num = 0, bit = 1;
    while( ( ch[++num] = getchar( ) ))
        if(ch[num] == 32 || ch[num] == 10)
            break;
    num--;
    while( num ) m += ( ch[num--]-48 )*bit, bit *= 10;
    return m;
}
int main()
{
    int k;
    memset(a, 0, sizeof(a));
    scanf("%d %d", &n, &k);
    getchar();
    for(int i = 1; i <= n; i++)
        a[i] = scan();
    work(1, n, k);
    return 0;
}
