/*****************************************************
Author:		:UDvoid
Create time	:2014-07-20-12.15
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
#define mx 10000001
int a[mx], b[mx];
int t, m, n;
void work()
{
    int i, j;
    int k;
    int id, mi, sum;
    for(i = 1; i <= n; i++)
    {//b
        for(j = 1, mi = 1000001, id = -1;j <= m; j++) // a
        {
            k = b[i]^a[j];
            sum = 0;
            while(k != 0)
                sum += k&1, k >>= 1;
            if(sum < mi)
                mi = sum, id = a[j];
            if(sum == mi && a[j] < id)
                id = a[j];
        }
        printf("%d\n", id);
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//
    int i;
    scanf("%d", &t);
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%d %d",&m, &n);
        for(i = 1; i <= m; i++)
            scanf("%d", &a[i]);
        for(i = 1;i <= n; i++)
            scanf("%d", &b[i]);
        work();
    }
    return 0;
}
