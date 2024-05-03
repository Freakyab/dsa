#include <iostream>
#include <algorithm>

using namespace std;

class jobScheduling
{
public:
    int jobname;
    int deadline, profit;
    jobScheduling()
    {
        profit = 0;
    }
};
void setValue(int index, int deadline, int profit, jobScheduling a[])
{
    a[index].deadline = deadline;
    a[index].profit = profit;
    a[index].jobname = index + 1;
}

int compareProfit(jobScheduling &a, jobScheduling &b)
{
    return a.profit > b.profit;
}

void printJobSequence(jobScheduling job[], int n)
{
    int totalProfit = 0;
    cout << "Selected Jobs:\n";
    for (int i = 0; i < n; ++i)
    {
        if (job[i].profit != 0)
        {
            cout << "Job Name: " << job[i].jobname
                 << ", Deadline: " << job[i].deadline
                 << ", Profit: " << job[i].profit << endl;
            totalProfit += job[i].profit;
        }
    }
    cout << "Total Profit: " << totalProfit << endl;
}

int main()
{
    int limit = 5;
    jobScheduling array[limit];
    setValue(0, 2, 60, array);
    setValue(1, 1, 100, array);
    setValue(2, 3, 20, array);
    setValue(3, 2, 40, array);
    setValue(4, 1, 20, array);

    sort(array, array + limit, compareProfit);

    int maxDead = 0;
    for (int i = 0; i < limit; i++)
    {
        maxDead = max(array[i].deadline, maxDead);
    }
    cout << maxDead << endl;

    jobScheduling result[maxDead];

    for (int i = 0; i < limit; i++)
    {
        int k = min(maxDead, array[i].deadline);

        while (k > 0)
        {
            if (result[k - 1].profit == 0)
            {
                result[k - 1] = array[i];
                break;
            }
            k--; // Move to the previous slot if the current slot is already occupied
        }
    }

    printJobSequence(result, maxDead);
}