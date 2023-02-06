#include<iostream>
#include<string>
using namespace std;

void breakIt(string str,int no,int count,int ind){

if(count<4)
{
    if(((ind+1)%no)!=0){
        cout<<str[ind];
        breakIt(str,no,count,++ind);
    }
    else {
        cout<<str[ind]<<" ";
        breakIt(str,no,++count,++ind);
    }
}
else for(ind;ind<str.length();ind++)cout<<str[ind];
}

int main(){

 string str;

cout<<"Enter the string : ";
cin>>str;

int no=str.length();
no/=4;

cout<<endl<<endl;
breakIt(str,no,1,0);
cout<<endl<<endl;
    return 0;
}