//22k-4609 Starting time 6.15
#include<iostream>
using namespace std;

class k224609{
    mutable int n,k,w,*arr;
    public:
     k224609(){}
     k224609(int n,int k,int w){
        this->n=n;
        this->k=k;
        this->w=w;
        arr=new int[n];
     }
     void TakeInput()const{
        cout<<"Enter the Heights of flower\n";
        for(int i=0;i<n;i++){
            cout<<"Flower "<<i+1<<" : ";
            cin>>arr[i];
        }
        }
      void waterTheFlower()const{
        int smallestind=0,smallestNum=arr[0];
        for(int i=1;i<n;i++){
           if(smallestNum<arr[i]){
            smallestNum=arr[i];
            smallestind=i;
           }

        int num=n-w-1;
        if(smallestind<num){
            for(int i=0;i<w;i++){
                ++arr[i];
            }
        }else for(int i=num;i<w+num;i++)++arr[i];

        }
      }  
     Display()const{
        cout<<"{";
        for(int i=0;i<n;i++)cout<<arr[i]<<",";
        cout<<"}";
     }
};

int main(){
    int n,k,w;
    cin>>n>>k>>w;
const k224609 obj(n,k,w);
obj.TakeInput();
for(int i=0;i<k;i++)
        obj.waterTheFlower();
obj.Display();
    return 0;
}

//6.50