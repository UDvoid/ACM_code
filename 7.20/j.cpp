/*****************************************************
Author:		:UDvoid
Create time	:2014-07-20-16.15
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
#define mx 10001
#define mx2 28
using namespace std;
int t, n, m;
char a[mx];
char b[mx];
int flag[28];
int lx[28], ly[28];
int ma[28][28];
int ch[27];
#define INF 111111111
bool path(int u)
{
    sx[u] = true;
    for(int v = 0; v < n; v++)
        if(sy[v]&&lx[u] + ly[v] == ma[u][v])
        {
            sy[v] = true;
            if(match[v] == -1 || path(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    return false;
}
int km()
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        lx[i] = 0x80000000;
        ly[i] = 0;
        for(j = 0;j < n; j++)
        {
            if(lx[i] < ma[i][j])
                lx[i] = ma[i][j];
        }
    }
    memset(match, -1, sizeof(match));
    for(int u = 0; u < n;u++)
    {
        while(1)
        {
            memset(sx, 0, sizeof(sx));
            memset(sy, 0, sizeof(sy));
            if(path(u))
                break;
            intdx = 0x7fffffff;
            for(i = 0; i < n; i++)
                if(sx[i])
                    for(j = 0; j < n; j++)
                        if(!sy[j])
                            dx = min(lx[i] + ly[j] - ma[i][j], dx);
            for(i = 0; i < n; i++)
            {
                if(sx[i])
                    lx[i] -= dx;
                if(sy[i])
                    ly[i] += dx;
            }
        }
        int sum = 0;
        for(i = 0;i < n; i++)
            sum += ma[match[i]][i];
        return sum;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    int kk = 0;;
    while(t--)
    {
        scanf("%d %d %d",&n, &k, &m);
        memset[flag, 0, sizeof(flag));
        for(i = 0;i < n; i++)
        {
            scanf("%c", &c);
            if(flag[c - 'a'] == 0)
                flag[c - 'a'] = kk++;
            lx[i] = flag[c - 'a'];
        }
        while(m--)
        {
            for(i = 0;i < n; i++)
                for(j = 0;j < n; j++)
                    ma[i][j] = -INF;
            memset[flag, 0, sizeof(flag));
            for(i = 0;i < n; i++)
            {
                scanf("%c", &c);
                if(flag[c - 'a'] == 0)
                    flag[c - 'a'] = kk++;
                b



                [i] = flag[c - 'a'];
            }for(i = 0; i < n;i++)
                ma[a[i]][b[i]]++, ma[b[i]][a[i]]++;
            work();
        }
    }
    return 0;
}
