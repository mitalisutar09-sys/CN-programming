#include<iostream>
#include<string>
using namespace std;
int main()
{
string frame;
string div;
string frame;
string div;
cout<<"enter frame:";
cin>>frame;
cout<<"enter div:";
cin>>div;
int n=div.length();
string originalframe=frame;
     for(int i=0;i<=(frame.length())-n;i++)
     {
        if(frame[i]=='1')
        {
            for(int j=0;j<n;j++)
            {
                if(frame[i+j]==div[j])
                  frame[i+j]='0';
                else
                  frame[i+j]='1';
            }
        }
     }
     string reminder=frame.substr(frame.length()-(n-1));
     cout<<"received codeword:"<<;
     cout<<"div:"<<div;
     cout<<"reminder:" <<reminder;
     if(reminder=="00")
         cout<<"there is no error";
     else
         cout<<"there is error";   
}    
