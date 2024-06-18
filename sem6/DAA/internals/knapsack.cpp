// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// class Job
// {
// public:
//     int objId, wi, vi;
//     Job()
//     {
//         objId = 0;
//         wi = 0;
//         vi = 0;
//     }
// };

// int compare(const Job &a, const Job &b)
// {
//     return a.vi > b.vi;
// }

// int getMax(const Job a[], int remains)
// {
//     float maxProfit = 0;
//     float remainingCap = remains;

//     for (int i = 0; i < 5; i++)
//     {
//         if (remainingCap >= a[i].wi)
//         {
//             remainingCap -= a[i].wi;
//             maxProfit += a[i].vi;
//             cout << a[i].objId << "\t\t";
//         }
//         else if (remainingCap > 0)
//         {
//             float fraction = remainingCap / a[i].wi;
//             maxProfit += fraction * a[i].vi;
//             remainingCap = 0;
//         }
//     }

//     cout << maxProfit << endl;
// }

// int main()
// {
//     Job jobList[5];
//     float remainingCap;
//     cin >> remainingCap;
//     for (int i = 0; i < 5; i++)
//     {
//         int wi, vi;
//         cout << "Enter the wi: ";
//         cin >> wi;
//         cout << "Enter the vi: ";
//         cin >> vi;
//         jobList[i].vi = vi;
//         jobList[i].wi = wi;
//         jobList[i].objId = i + 1;
//     }

//     sort(jobList, jobList + 5, compare);
//     getMax(jobList, remainingCap);
// }

#include <iostream>
#include <algorithm>

using namespace std;

class ObjDetails
{
public:
    int objId;
    int wi;
    int vi;
};

int setValue(ObjDetails a[], int index, int wi, int vi)
{
    a[index].objId = index + 1;
    a[index].vi = vi;
    a[index].wi = wi;
}

int compareMAX(const ObjDetails &a, const ObjDetails &b)
{
    return a.vi > b.vi;
}
int compareMIN(const ObjDetails &a, const ObjDetails &b)
{
    return a.wi < b.wi;
}
int compareRATIO(const ObjDetails &a, const ObjDetails &b)
{
    float value1 = (float) a.vi / a.wi;
    float value2 =(float) b.vi / b.wi;
    return value1 > value2;
}

int knapsack(ObjDetails table[], int remains)
{
    float remainingCap = remains;
    int maxProfit = 0;

    for (int i = 0; i < 5; i++)
    {
        if (remainingCap >= table[i].wi)
        {
            remainingCap -= table[i].wi;
            maxProfit += table[i].vi;
        }
        else if (remainingCap > 0)
        {
            float fra = remainingCap / table[i].wi;
            cout << fra << endl;
            maxProfit += table[i].vi * fra;
            remainingCap = 0;
        }
    }
    cout << maxProfit;
}

int main()
{
    ObjDetails table[5];

    int remains = 100;
    setValue(table, 0, 10, 20);
    setValue(table, 1, 20, 30);
    setValue(table, 2, 30, 66);
    setValue(table, 3, 40, 40);
    setValue(table, 4, 50, 60);

    sort(table, table + 5, compareRATIO);
    knapsack(table, remains);
}