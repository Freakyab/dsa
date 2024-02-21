#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int BinaryToInt(string s){
    //Learn how to use powers in c++!!!!
    int sum=0;
    for(int i=0;i<8;i++){
        if(s[i]=='1'){
            //int x=8;
            sum = sum + pow(2,7-i);
        }
        else{
            continue;
        }
        //cout<<pow(2,7-i)<<" ";
    }
    return sum;
}

void Class_Binary(string ip){
    char s1[8],s2[8],s3[8],s4[8];
    // s1="Hello";
    for(int i=0;i<8;i++){
        s1[i]=ip[i];
    }
    for(int i=0;i<8;i++){
        cout<<s1[i];
    }
    cout<<endl;
    int a;
    a=BinaryToInt(s1);
    cout<<a<<endl;
    if(0<=a<=126){
        cout << (0 <= a <= 126);
        cout<<"Class A"<<endl;
    }else if(127<=a<=191){
        cout<<"Class B"<<endl;
    }else if(192<=a<=223){
        cout<<"Class C"<<endl;
    }else if(224<=a<=239){
        cout<<"Class D"<<endl;
    }else if(240<=a<=255){
        cout<<"Class E"<<endl;
    }
}

int main(){
    string ip;
    cout<<"Enter ip : ";
    cin>>ip;
    cout<<ip<<endl;
    Class_Binary(ip);
}