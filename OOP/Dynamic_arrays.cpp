#include<iostream>
using namespace std;

int main(){            /////*************UNCMOPLETED**************
    int* arr;
    int n=0;
    while(*(arr+(n-1)) != 13){
        ++n;
        arr = new int [n];
        cout<<"Enter the new value : ";
        cin>>*(arr+(n-1));
    }
    cout<<"You have entered "<<n<<" numbers \n";

    for(int i=0;i<n;i++)cout<<"Number "<<i+1<<" : "<<*(arr+i)<<endl;

    cout<<endl<<endl<<"\t\tThanks\n";
    delete arr;
}