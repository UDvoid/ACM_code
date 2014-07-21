/*****************************************************
Author:		:UDvoid
Create time	:2014-06-21-22.58
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
int t;
long long n;
int main()
{
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        scanf("%lld", &n);
        while(n)
        {
            ans = ans << 1 | n & 1;
            n >>= 1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
