#include <iostream>
#include <cstdio>
using namespace std;
int t, n;
void work()
{
    if(n <= 0)
    {
        printf("ich bin dumm\n");
        return;
    }
    if(n == 1)
        printf("1\n");
    int i, j;
    i = 1;
    j = n;
    while(i < j)
    {
        printf("%d %d ",i, j);
        i++;
        j--;
    }
    if(i == j)
        printf("%d\n",i);
    else
        printf("\n");
    return;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        work();
    }
    return 0;
}
