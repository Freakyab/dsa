#include <iostream>
#include <algorithm>
using namespace std;

// class Job
// {
// public:
//     string jobName;
//     int deadline;
//     int profit;
// };

// bool compareJobs(const Job &a, const Job &b)
// {
//     return a.profit > b.profit;
// }

// void printJobSequence(Job jobSequence[], int n)
// {
//     int totalProfit = 0;
//     cout << "Selected Jobs:\n";
//     for (int i = 0; i < n; ++i)
//     {
//         if (jobSequence[i].profit != 0)
//         {
//             cout << "Job Name: " << jobSequence[i].jobName << ", Deadline: " << jobSequence[i].deadline << ", Profit: " << jobSequence[i].profit << endl;
//             totalProfit += jobSequence[i].profit;
//         }
//     }
//     cout << "Total Profit: " << totalProfit << endl;
// }

// void jobSequencing(Job jobs[], int n)
// {
//     int maxDeadline = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         maxDeadline = max(maxDeadline, jobs[i].deadline);
//     }

//     Job jobSequence[maxDeadline];

//     for (int i = 0; i < maxDeadline; ++i)
//     {
//         jobSequence[i].profit = 0;
//     }

//     for (int i = 0; i < n; ++i)
//     {
//         int k = min(maxDeadline, jobs[i].deadline);
//         while (k > 0) // Change the loop condition to k > 0
//         {
//             if (jobSequence[k - 1].profit == 0) // Adjust array index
//             {
//                 jobSequence[k - 1] = jobs[i]; // Adjust array index
//                 break;
//             }
//             k--;
//         }
//     }

//     printJobSequence(jobSequence, maxDeadline);
// }

// int main()
// {
//     int n;

//     cout << "Enter the no. of Jobs: ";
//     cin >> n;

//     Job jobs[n];

//     for (int i = 0; i < n; ++i)
//     {
//         cout << "Enter the job Name: ";
//         cin >> jobs[i].jobName;
//         cout << "Enter the deadline: ";
//         cin >> jobs[i].deadline;
//         cout << "Enter the profit: ";
//         cin >> jobs[i].profit;
//     }

//     sort(jobs, jobs + n, compareJobs);

//     jobSequencing(jobs, n);

//     return 0;
// }

class Job
{
public:
    int deadline;
    int profit;
    int jobNo;

    Job()
    {
        profit = 0;
    }
};

bool compareJobs(const Job &a, const Job &b)
{
    return a.profit > b.profit;
}


void printJobSequence(Job jobSequence[], int n)
{
    int totalProfit = 0;
    cout << "Selected Jobs:\n";
    for (int i = 0; i < n; ++i)
    {
        if (jobSequence[i].profit != 0)
        {
            cout << "Job Name: " << jobSequence[i].jobNo << ", Deadline: " << jobSequence[i].deadline << ", Profit: " << jobSequence[i].profit << endl;
            totalProfit += jobSequence[i].profit;
        }
    }
    cout << "Total Profit: " << totalProfit << endl;
}
void jobSeq(Job jobs[], int n)
{
    int Dmax = 0;
    for (int i = 0; i < n; i++)
    {
        Dmax = max(Dmax, jobs[i].deadline);
    }
    cout<<Dmax <<endl;
    Job newJob[Dmax];

    for (int i = 0; i < n; i++)
    {
        int k = min(Dmax, jobs[i].deadline);
        cout << k << " K value\n";
        while (k > 0)
        {
            if (newJob[k - 1].profit == 0)
            {
                newJob[k - 1] = jobs[i];
                break;
            }
            else
            {
                k--;
            }
        }
    }

    printJobSequence(newJob,Dmax);
}

int main()
{

    int n;

    cout << "Enter the no. of jobs: ";
    cin >> n;

    Job jobs[n];

    for (int i = 0; i < n; i++)
    {
        jobs[i].jobNo = i + 1;
        cout << "Enter the deadline: ";
        cin >> jobs[i].deadline;
        cout << "Enter the Profit: ";
        cin >> jobs[i].profit;
    }

    sort(jobs, jobs + n, compareJobs);

    jobSeq(jobs, n);
}