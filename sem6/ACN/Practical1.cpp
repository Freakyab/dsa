#include <iostream>
#include <string>

using namespace std;

void checkValidate(string ip)
{
    // int octet[4], cell = 0, j = 0, digitCounter = 0;
    // for (int i = 0; i < ip.size(); i++)
    // {
    //     digitCounter++;
    //     if (ip[i] == '.' || i == ip.size()-1 )
    //     {
    //         if(i == ip.size()-1){
    //             octet[j] = digitCounter;
    //         }
    //         else{
    //             octet[j] = digitCounter-1;
    //             j++;
    //         }
    //         digitCounter =0;
    //     }
    // }
    // int k =0,l=0;

    for (int i = 0; i < ip.size(); i++)
    {
       if(ip[i] == '0'){
        if(ip[i-1] != '.' && ip[i+1] != '.' ){
            if(!ip[i-1]== '1' || '2'||'3') 
        break;
        }
       }
    }
}

int main()
{

    // Variables require
    string ipAddress;
    cin >> ipAddress;

    checkValidate(ipAddress);
}