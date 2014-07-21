/*****************************************************
Author:		:UDvoid
Create time	:2014-06-08-18.07
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
char c[105] = {0};
char ch[27] = {0};
int t, n, m;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d", &t);
    int len, i, j, k, ma, ans;
    char ch0;
    while(t--)
    {
        memset(c, 0, sizeof(c));
        memset(ch, 0, sizeof(ch));
        scanf("%s", c);
        len = strlen(c);
        ans = 1;
        ch0 = -1;
        for(i = 0; i < len; i++)
        {
            if(c[i] == ch0)
            {
                ans++;
            }
            else
            {
                if(ans > ch[ch0 - 'a'])
                    ch[ch0 - 'a'] = ans;
                ans = 1;
                ch0 = c[i];

            }
            if(i == len - 1)
            {
                if(ans > ch[ch0 - 'a'])
                    ch[ch0 - 'a'] = ans;
            }
        }

        ma = -1;
        for(i = 0; i < 26; i++)
            if(ma < ch[i])
                ma = ch[i];
        printf("%d\n", ma);
    }
    return 0;
}
