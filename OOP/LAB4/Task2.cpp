#include<iostream>
#include<string>
using namespace std;

class Book {
	string name, author;
	int ISBN, numOfpages, read;

public:
	
	Book() {
		numOfpages = 1000;
		read = 0;
	}

	void setName(string val) { name = val; }
	void setAuthor(string val) { author = val; }
	void setISBN(int val) { ISBN = val; }
	void setPages(int val) { numOfpages = val; }
	void setPagesRead(int val) { read = val; }

	int getPages() { return numOfpages; }
	int getPagesRead() { return read; }
	int getISBN() { return ISBN; }
	string getName() { return name; }
	string getAuhtor() { return author; }

	void readPage() {
		if (!(read >= numOfpages)) {
			cout << "a page is read from the book" << endl;
			read++;
		}
		else cout << "The book is finished !" << endl;
	}

	void showBookInfo() {
		cout << "The Information of the book is\nName : " << name << "\nAuthor : " << author << "\nISBN : " << ISBN << "\nTotal number of pages : " << numOfpages << "\nPages read : " << read << endl;
	}
};

int main() {
	Book obj;
	obj.showBookInfo();
	obj.setName("The book");
	obj.setAuthor("Author");
	obj.setISBN(4609);
	obj.setPages(10);
	obj.setPagesRead(8);
	
	obj.showBookInfo();

	for (int i = 0; i < 3; i++) obj.readPage();
	
	



	return 0;
}