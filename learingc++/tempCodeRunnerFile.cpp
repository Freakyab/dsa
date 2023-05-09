class Teacher
{
private:
    int rollNo;
    string name;
    int marks[2];
    int avg;

public:
    void setData(int rollStu, string nameStu, int marksStu[])
    {
        rollNo = rollStu;
        name = nameStu;
        for (int i = 0; i < 2; i++)
            marks[i] = marksStu[i];
    }
    string getName()
    {
        return name;
    }
    int getRoll()
    {
        return rollNo;
    }
    int *getMarks()
    {
        return marks;
    }
    double getAvg()
    {
        double avg;
        int totalMarks = 0, count = 0;
        for (int i = 0; i < 2; i++)
        {
            totalMarks = totalMarks + *(this->getMarks() + i);
            count++;
        }
        avg = totalMarks / count;
        return avg;
    }
};
string getTopper(Teacher str[])
{
    string topperName;
    for (int i = 0; i < 2; i++)
    {
        if (str[i].getAvg() < str[i + 1].getAvg())
            topperName = str[i + 1].getName();
    }
    return topperName;
}
int main()
{
    Teacher str[70];
    for (int i = 0; i < 2; i++)
    {
        int rollno;
        string name;
        int marks[5];
        cout << "Enter the name of student :";
        cin >> name;
        cout << "Enter the roll no of student :";
        cin >> rollno;
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter the no of marks for subject " << j + 1 << " ";
            cin >> marks[j];
        }
        str[i].setData(rollno, name, marks);
        for (int j = 0; j < 2; j++)
        {
            cout << *(str[i].getMarks() + j) << endl;
        }
    }
    cout << getTopper(str);
}