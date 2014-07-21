#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int r1, r2, a, b;
int t;
void work()
{
    int tmp;
    if(a < b)
    {
        tmp = a; a = b; b = tmp;
    }
    if(r1 < r2)
    {
        tmp = r1; r1 = r2; r2 = tmp;
    }
    if(r1 * 2 > b)
    {
        printf("NO\n");
        return;
    }
    int x1, y1, x2, y2;
    x1 = y1 = r1;
    x2 = a - r2;
    y2 = b - r2;
    double l1, l2;
    l1 = sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
    l2 = double(r1 + r2);
    if(l1 >= l2)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d", &a, &b, &r1, &r2);
        work();
    }
    return 0;
}
