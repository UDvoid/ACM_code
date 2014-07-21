/*****************************************************
Author:		:UDvoid
Create time	:2014-07-21-13.24
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
int t, n, k;
#define mx 10005
int a[mx], b[mx], c[mx];
#define INF 0x3fffffff
double fmax(double x)
{
    double ans = -INF, val;
    for(int i = 0;i < k; i++)
    {
        val = (double)a[i]*x*x + (double)b[i]*x + (double)c[i];
        if(val > ans)
            ans = val;
    }
    return ans;
}
void work()//Èý·Ö·¨
{
    double l = 0.0, r = 1000.0;
    double mid, midmid;
    double res1, res2;
    for(int i = 0;i < 500; i++)
    {
        mid = (l + r)/2;
        midmid = (mid + r)/2;
        res1 = fmax(mid), res2 = fmax(midmid);
        if(res1 < res2)
            r = midmid;
        else
            l = mid;
    }
    printf("%.4lf\n", fmax(l));
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        for(int i = 0; i < k; i++)
            scanf("%d %d %d",&a[i], &b[i], &c[i]);
        work();
    }
    return 0;
}
