/*****************************************************
Author:		:UDvoid
Create time	:2014-07-19-12.29
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

#define IF 10000
#define mx 110
int d[mx][mx];
int id, num, sum, t = 0;
void floyed()
{
    int i, j, k;
    int a, b;
    while(~scanf("%d %d",&a, &b) && !(!a && !b))
    {
        num = 0,sum = 0, id = 0;

        for(i = 1;i < mx; i++)
            for(j = 1;j < mx;j++)
                d[i][j] = d[j][i] = IF;

        for(i = 1;i < mx; i++)
            d[i][i] = 0;

        id = max(a, b);
        d[a][b] = 1;

        while(~scanf("%d %d",&a, &b) && !(!a && !b))
        {
            id = max(id, max(a, b));
            d[a][b] = 1;
        }

        for(k = 1;k <= id; k++)
            for(i = 1;i <= id; i++)
                for(j = 1;j <= id; j++)
                    if(i != j && i != k && j != k && d[i][j] > d[i][k] + d[k][j])
                        d[i][j] = d[i][k] + d[k][j];

        for(i = 1;i <= id; i++)
            for(j = 1;j <= id; j++)
                if(i != j && d[i][j] != IF)
                    sum += d[i][j], num++;

        printf("Case %d: average length between pages = %.3lf clicks\n",++t,(double)sum/(double)num);
    }
}
int main()
{
    floyed();
    return 0;
}
