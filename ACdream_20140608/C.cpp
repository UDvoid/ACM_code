/*****************************************************
Author:		:UDvoid
Create time	:2014-06-08-19.54
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
int t, n, m;
int cap;
int ans;
int a[105], b[105];
int flag[100005];
int c[100005];
int len;
void work(int ca,int k)
{
    if(k == len)
        return;
    if(ca + c[k] > cap)
        return;
    if(ca + c[k] <= cap)
    {
        if(flag[ca + c[k]] == 0)
            flag[ca + c[k]] = 1;
        work(ca + c[k], k + 1);
        work(ca, k + 1);
    }
    else
        work(ca,  k + 1);
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    int t0 = t;
    int i, j, k;
    while(t--)
    {
        scanf("%d %d", &n, &cap);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(flag, 0, sizeof(flag));
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for(j = 0, i = 0; i < n; i++)
        {
            for(k = 1; k <= b[i]; k *= 2)
            {
                c[j++] = k * a[i];
                b[i] -= k;
            }
            if(b[i] > 0)
                c[j++] = b[i] * a[i];
        }
        len = j;
        work(0, 0);
        ans = 0;
        for(i = 1;i <= cap; i++)
            if(flag[i] == 1)
                ans ++;
        printf("Case %d: %d\n",t0 - t, ans);
    }
    return 0;
}
