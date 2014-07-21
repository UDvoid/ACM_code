/*****************************************************
Author:		:UDvoid
Create time	:2014-07-20-13.34
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
#define mx1 10001
#define mx2 401
int a[mx1], b[mx1], c[mx1];
int x[mx2/2];
int ma[mx2][mx2];
int t, n, m;
void add(int i)
{
    if(c[i] == 0)
        ma[a[i] + n][b[i]] = 1, ma[b[i] + n][a[i]] = 1;
    if(c[i] == 2)
        ma[a[i]][b[i] + n] = 1, ma[b[i]][a[i] + n] = 1;
    if(c[i] == 1)
        ma[a[i]][b[i]] = 1, ma[b[i]][a[i]] = 1;
}
void del(int i)
{
    if(c[i] == 0)
        ma[a[i] + n][b[i]] = 0, ma[b[i] + n][a[i]] = 0;
    if(c[i] == 2)
        ma[a[i]][b[i] + n] = 0, ma[b[i]][a[i] + n] = 0;
    if(c[i] == 1)
        ma[a[i]][b[i]] = 0, ma[b[i]][a[i]] = 0;
}
int judge(int k)
{
    int mm = 2 * n;
    for(i = 0;i < mm; i++)
        for(j = 0; j < mm; j++)
            ma[i][j] = -1;

    i = k;
    for(i = 0; i < k; i++)
        add[i];

}
void work()
{
    int l, r, i;
    l = 0, r = m - 1;
    k = (l + r)/2;
    judge(k);

}
int main()
{
    int i, ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n, &m);
        for(i = 0; i < m; i++)
            scanf("%d %d %d",&a[i], &b[i], &c[i]);
        work();
    }
    return 0;
}
