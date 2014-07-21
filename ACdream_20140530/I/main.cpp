#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int t, n, m;
bool a[10001];
int from[10001];
int mat[10001][10001];
int to[10001];
typedef struct node{
    vector<pair<int, int> > next;
}ma;
ma cou[10001];
queue <int > q;
int main()
{
    int ai, bi, ci;
    int i, j, mi, len;
    scanf("%d",&t);
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(from, 0, sizeof(from));
        memset(to, 0, sizeof(to));
        while(!q.empty())
            q.pop();
        scanf("%d %d",&n, &m);
        for(i = 1; i < n; i++)
            cou[i].next.clear();
        for(i = 0;i < m; i++)
        {
            scanf("%d %d %d", &ai, &bi, &ci);
            cou[bi].next.push_back(make_pair(ai, ci));
            mat[bi][ai] = 1;
            from[bi]++;
            to[ai]++;
        }
        for(i = 1; i <= n; i++)
        {
            if(from[i]*to[i] == 0)
                a[i] = 1;
        }
        j = 0;
        for(i = 1; i <= n; i++)
            if(a[i] == 0)
                j = 1;
        if(j == 0)
        {
            printf("0\n");
            continue;
        }

        mi = 2 << 29;

        for(i = 1; i <= n; i++)
        {
            if(a[i] == 1)
                continue;
            len = cou[i].next.size();
            for(j = 0; j < len; j++)
                if(a[cou[i].next[j].first] == 0 && cou[i].next[j].second < mi)
                    mi = cou[i].next[j].second;
        }
        printf("%d\n",mi);
    }
    return 0;
}
