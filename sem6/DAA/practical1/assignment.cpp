#include <stdio.h>
#include <stdlib.h>

struct Interval
{
    int start;
    int end;
};

int compareIntervals(const void *a, const void *b)
{
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}

char *checkFight(int C, int N, int K, struct Interval *intervals)
{

    qsort(intervals, N, sizeof(struct Interval), compareIntervals);

    if (K == 0)
    {
        for (int i = 1; i < 2; i++)
        {
            if (intervals[i].start <= intervals[i - 1].end)
                return "Bad";
        }
    }

    else
    {
        for (int i = 1; i < N; i++)
        {
            if (intervals[i].start <= intervals[i - 1].end)
            {
                if (intervals[i].start - intervals[i - 1].start < intervals[i].end - intervals[i - 1].end)
                {
                    intervals[i].start - intervals[i - 1].start;
                }
                else
                {
                    intervals[i - 1].end - intervals[i].end;
                }

                for (int j = i + 1; j < N; j++)
                {
                    if (intervals[j].start <= intervals[j - 1].end)
                    {
                        return "Bad";
                    }
                }
                return "Good";
            }
        }
        return "Good";
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int C, N, K;
        scanf("%d %d %d", &C, &N, &K);
        struct Interval intervals[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &intervals[i].start, &intervals[i].end);
        }
        printf("%s\n", checkFight(C, N, K, intervals));
    }
    return 0;
}
