#include<iostream>
#include<string>
using namespace std;

class Book {
	string name, author;
	int ISBN, numOfpages, read;

public : 
	Book(){}
	Book(string Name,string Author,int isbn,int nop,int nor){
		name = Name;
		author = Author;
		ISBN = isbn;
		numOfpages = nop;
		read = nor;
	}

	void readPage() {
		if (!(read >= numOfpages)) {
			cout << "a page is read from the book" << endl;
			read++;
		}
		else cout << "The page cannot be read !" << endl;
	}
};

int main() {
	Book obj("OOP","Taha Khan",4609,10,5);
	for(int i=0;i<6;i++)
	obj.readPage();
	


	return 0;
}