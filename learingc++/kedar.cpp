// // PRACTICAL 3:
// // Q.3
// #include <iostream>
// #include <string>
// using namespace std;
// class Student
// {
//     private:
//     int rollno,marks;
//     string name;
    
//     public:
//     void setdata(int r,int m,string n){
//         rollno=r;
//         marks=m;
//         name=n;
//     }
//     int getRoll(){
//         return rollno;
//     }
//     int getMarks(){
//         return marks;
//     }
//     string getName(){
//         return name;
//     }
//     float avg(){
//         return (marks/5);
//     }
// };

// int main(){
//     int r,m,n;
//     string name;
//     cout<<"Enter the total no. of students\n";
//     cin>>n;
//     Student s[n];
//     for(int i=0;i<n;i++){
//         cout<<"\n\nEnter details of student : "<<i+1;
//         cout<<"\nRoll No. : ";
//         cin>>r;
//         cout<<"\nMarks : ";
//         cin>>m;
//         cout<<"\nName : ";
//         cin>>name;
//         s[i].setdata(r,m,name);
//     }
//     cout<<"\n\nDetails of every Student: \n";
//     for(int i=0;i<n;i++){
//         cout<<"\nStudent:"<<i+1;
//         cout<<"\nName : "<<s[i].getName();
//         cout<<"\nRoll No. : "<<s[i].getRoll();
//         cout<<"\nMarks : "<<s[i].getMarks();
//         cout<<"\nAverage Marks : "<<s[i].avg()<<"\n";
//     }
//     int index=0;
//     int topper=0;
//         topper = s[0].getMarks();
// for(int i=1; i<n; i++){
//     if(s[i].getMarks() > topper){
//         topper = s[i].getMarks();
//         index = i;
//     }
// }
//     cout<<"\n\nTopper Marks : "<<topper;
//     cout<<"\nTopper Name : "<<s[index].getName();
//     return 0;
// }

//PRACTICAL 2
//Q.1
// 

// Example:

#include<iostream>
using namespace std;

class Test
{
public:
		Test()
	{
			cout<<"\n Constructor executed";
	}

	~Test()
		{
			cout<<"\n Destructor executed";
		}
};
main()
{
	Test t;
	
	return 0;
}
