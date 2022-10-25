#include <stdio.h>
#include <algorithm.h> //因为要用sort算法
#define N 100
using namespace std; //必须引用名字空间std
struct ant_type
{
    int pos;
    char name[11];
} ants[N];
struct event_type
{
    int drop_time;
    char dir;
} events[N];
bool cmp_ant(const ant_type& p, const ant_type& q)
{
    return p.pos < q.pos;
}
bool cmp_event(const event_type& p, const event_type& q)
{    return p.drop_time < q.drop_time;
}
int main()
{
    char dir[2];
    int i, k, n, L, R, T;
    scanf("%d", &T);
    for (k = 1; k <= T; k++)
    {
        scanf("%d%d", &n, &L);
        for (i = 0; i < n; i++)
        {
            scanf("%s%d%s", ants[i].name, &ants[i].pos, dir);
            events[i].dir = dir[0];
            events[i].drop_time = (dir[0] == 'L' ?
                                                        ants[i].pos : L - ants[i].pos);
        }
sort(ants, ants + n, cmp_ant);
        sort(events, events + n, cmp_event);
        printf("Case #%d:\n", k);
        L = 0;        R = n - 1;
        for (i = 0; i < n; i++)
        {
            if (events[i].dir == 'L')
            {
                printf("%d %s\n", events[i].drop_time, ants[L].name);
                L++;
            }
            else
            {
                printf("%d %s\n", events[i].drop_time, ants[R].name);
                R--;
            }}}
    return 0;
}
