/*****************************************************
Author:		:UDvoid
Create time	:2014-06-08-18.49
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
int ans[10000] = {0};
int flag[10000] = {0};

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        n += 2;
        while(n%3 == 0 && n != 0)
            n /= 3;
        while(n%5 == 0 && n != 0)
            n/= 5;
        if(n == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
