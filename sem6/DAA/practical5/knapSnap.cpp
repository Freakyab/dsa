// Write the knapSnap code in cpp
#include <iostream>
#include <algorithm>
using namespace std;

class Object
{
public:
    int Object_no;
    int wi;
    int vi;
};

bool compareMax(const Object &a, const Object &b)
{
    return a.vi > b.vi;
}
bool compareMin(const Object &a, const Object &b)
{
    return a.wi < b.wi;
}
bool compareDiv(const Object &a, const Object &b)
{
    float value = (float)a.vi / a.wi;
    float value1 = (float)b.vi / b.wi;
    return value > value1;
}

void getMax(Object AllObject[], int n, float capacity)
{
    float maxProfit = 0;
    float remainingCapacity = capacity;
    cout << "\t Object | \t weight | \t profit\n";
    for (int i = 0; i < n; i++)
    {
        if (remainingCapacity >= AllObject[i].wi)
        {
            remainingCapacity -= AllObject[i].wi;
            maxProfit += AllObject[i].vi;
            cout << AllObject[i].Object_no << "\t\t" << AllObject[i].wi << "\t\t" << AllObject[i].vi << "\t\t" << remainingCapacity << endl;
        }
        else if (remainingCapacity > 0) 
        {
            float fraction = remainingCapacity / AllObject[i].wi;
            maxProfit += fraction * AllObject[i].vi;
            remainingCapacity = 0;
            cout << AllObject[i].Object_no << "\t\t" << AllObject[i].wi << "\t\t" << fraction * AllObject[i].vi << "\t\t" << 0 << endl;
        }
    }
    cout << "Maximum Profit: " << maxProfit << endl;
}


int main()
{
    int n;
    float remainingCapacity = 0;
    cout << "Enter the total no: ";
    cin >> n;
    cout << "ENter the remaining capacity: ";
    cin >> remainingCapacity;
    Object AllObject[n];
    for (int i = 0; i < n; i++)
    {
        AllObject[i].Object_no = i + 1;
        cout << "Enter the wi: ";
        cin >> AllObject[i].wi;
        cout << "Enter the vi: ";
        cin >> AllObject[i].vi;
    }

   // Sort based on maximum profit
    sort(AllObject, AllObject + n, compareMax);
    cout << "Max vi" << endl;
    getMax(AllObject, n, remainingCapacity);

    // Sort based on minimum weight
    sort(AllObject, AllObject + n, compareMin);
    cout << "Min wi" << endl;
    getMax(AllObject, n, remainingCapacity);

    // Sort based on profit-to-weight ratio
    sort(AllObject, AllObject + n, compareDiv);
    for(int i = 0 ; i< n;i++){
        cout << AllObject[i].Object_no << " " << AllObject[i].wi <<" "<<endl;
    }
    cout << "Max vi/wi" << endl;
    getMax(AllObject, n, remainingCapacity);
}
