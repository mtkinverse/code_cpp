//8.40
#include<iostream>
#include<string>
using namespace std;

class Book{
    string title,author,ISBN;
    static int TotalBooksBor;
    public:
    Book(){}
    Book(string title,string author,string ISBN){
        this->title=title;
        this->author=author;
        this->ISBN=ISBN;
        ++TotalBooksBor;
    }

    int getTotalBooksBor()const {
      return TotalBooksBor;
    }

};
int Book::TotalBooksBor=0;

class Student{
    string name,ID;
    const int booksbor;
    Book *arr;
    public:
    Student():booksbor(booksbor){}
    Student(string name,int booksbor,Book* arr):booksbor(booksbor){
        this->name=name;
        this->arr=arr;
    }
    int getBooksbor()const { return booksbor;}
    string getName()const{return name;}

};

int main(){
    Book books[]={Book("The Catcher in the Rye","J.D Saliger","0101010101010"),Book("To kill Mocking Bird","Harper Lee","010101010111"),Book("1984","George Overwell","0101010111111")};
    Student sts[]={Student("John Smith",2,books),Student("Jane Doe",2,books)};
    cout<<"All borrowed books "<<books[0].getTotalBooksBor()<<"\n"<<sts[0].getName()<<" has borrowed "<<sts[0].getBooksbor()<<"\n"<<sts[1].getName()<<" has borrowed "<<sts[1].getBooksbor()<<endl;
    
    return 0;
}
//9.00