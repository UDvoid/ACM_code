/*****************************************************
Author:		:UDvoid
Create time	:2014-06-22-15.56
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
int a[16];
int used[16];
int t;
int flag = 0;
void work()
{
    int ans = 0;
    int found = 0;
    int i, j, l, k;
    memset(used, 0, sizeof(used));
    for(i = 1;i < 16; i++)
    {
        if(!a[i] || used[i])
            continue;
        used[i] = 1;
        l = a[i];
        a[i] = 0;
        flag = 0;
        found = 0;
        for(j = i + 1; j < 16; j++)
        {
            if(a[j] == 0)
            {
                if(found == 0)
                    ans++;
                break;
            }
            if(a[j] < l || used[j] == 1)
            {
                ans++;
                break;
            }
            if(used[j])
                continue;
            if(a[j] == l && !flag)
            {
                used[++i] = 1;
                a[i] = 0;
            }
            if(a[j] > l)
                flag = 1;
            if(a[j] == l && flag)
            {
                ans++;
                found = 1;
                a[j] = 0;
                j++;
                while(j < 16 && a[j] != 0)
                {
                    if(a[j] == l)
                    {
                        used[j] = 1;
                        a[j] = 0;
                    }
                    j++;
                }
                if(a[j] == 0)
                    break;
            }
        }
    }
    printf("%d\n", ans);
}
int main()
{
    int i, j;
    scanf("%d", &t);
    while(t--)
    {
        for(i = 0;i < 16; i++)
            scanf("%d",&a[i]);
        printf("%d ",a[0]);
        work();
    }

    return 0;
}
