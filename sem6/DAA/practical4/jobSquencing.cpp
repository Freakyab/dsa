#include <iostream>
#include <algorithm> // for std::min
using namespace std;

class Job
{
public:
    string jobName;
    int deadline;
    int profit;
    int n;

    void compareTheProfits(Job jobList[])
    {
        cout << n;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (jobList[j].profit < jobList[j + 1].profit)
                {
                    swap(jobList[j], jobList[j + 1]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (jobList[i].deadline != 0)
            {
                cout << "\tDetails for timeSlot: " << i + 1 << " :\n";
                cout << "Job Name: " << jobList[i].jobName << "\n";
                cout << "Deadline: " << jobList[i].deadline << "\n";
                cout << "Profit: " << jobList[i].profit << "\n";
            }
        }
    }


    int getDmax(Job jobList[])
    {
        int max = jobList[0].deadline;
        for (int i = 0; i < n; i++)
        {
            if (jobList[i].deadline > max)
            {
                max = jobList[i].deadline;
            }
        }
        return max;
    }

    void jobOrder(Job jobList[], int Dmax)
    {
        Job timeSlot[Dmax];
        for (int i = 0; i < Dmax; i++)
        {
            timeSlot[i].deadline = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int k = min(Dmax, jobList[i].deadline);
            while (k != 0)
            {
                if (timeSlot[k - 1].deadline == 0)
                {
                    timeSlot[k - 1].deadline = jobList[i].deadline;
                    timeSlot[k - 1].jobName = jobList[i].jobName;
                    timeSlot[k - 1].profit = jobList[i].profit;
                    break;
                }
                else
                {
                    k--;
                }
            }
        }

        int maxProfit = 0;
        for (int i = 0; i < Dmax; i++)
        {
            if (timeSlot[i].deadline != 0)
            {
                cout << "\tDetails for timeSlot: " << i + 1 << " :\n";
                cout << "Job Name: " << timeSlot[i].jobName << "\n";
                cout << "Deadline: " << timeSlot[i].deadline << "\n";
                cout << "Profit: " << timeSlot[i].profit << "\n";
                maxProfit += timeSlot[i].profit;
            }
        }
        cout << "Total Profit: " << maxProfit << endl;
    }
};

void getJobDetails(int N, Job jobList[])
{
    jobList->n = N;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the job Name: ";
        cin >> jobList[i].jobName;
        cout << "Enter the deadline: ";
        cin >> jobList[i].deadline;
        cout << "Enter the profit: ";
        cin >> jobList[i].profit;
    }
}

int main()
{
    int n, Dmax;

    cout << "Enter the no. of Jobs: ";
    cin >> n;

    Job jobList[n];

    // Get the required details for the Job list
    getJobDetails(n, jobList);

    // Sort the order
    for (int i = 0; i < n; i++)
    {
        cout << "running\n";
        jobList[i].compareTheProfits(jobList);
    }

    // Find Dmax
        cout << "running\n";
    Dmax = jobList[0].getDmax(jobList);

    // Make table
    for (int i = 0; i < n; i++)
    {
        cout << "running\n";
        jobList[i].jobOrder(jobList, Dmax);
    }

    return 0;
}
