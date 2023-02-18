#include<iostream>
#include<string>
using namespace std;

class BoardMarker {
	string company, color;
	bool stat=true, refill=true;
public:
	void setComp(string name) {
		company = name;
	}
	void setCol(string name) {
		color = name;
	}
	string getComp() {
		return company;
	}
	string getCol() {
		return color;
	}
	void setStat(int num) {
		stat = num;
	}
	void setRefill(int num) {
		refill = num;
	}
	bool getStat() { return stat; }
	bool getRefill() { return refill; }

	void write() {
		if (stat) {
			cout << "You can write with the board marker" << endl;
			stat = false;
		}
		else cout << "You cannot write with the marker" << endl;
	}
	void refillIt() {
		if (refill && (!(stat))) cout << "The board marker has been filled" << endl;
		else cout << "You cannot refill marker" << endl;
	}
};


int main(){
	string temps;
	int tempno;
	BoardMarker obj;
	cout << "Welcome and give the information of the board marker\nName of the company : ";
	fflush(stdin);
	getline(cin, temps);
	fflush(stdin);
	obj.setComp(temps);
	cout << "Give the color of the ink : ";
	fflush(stdin);
	getline(cin, temps);
	fflush(stdin);
	obj.setCol(temps);
	
	cout << "Is the marker refillable ?\n1- Yes\n 2- NO\nEnter your choice : ";
	cin >> tempno;

	switch (tempno) {
	case 1:
		obj.setRefill(1);
		break;
	case 2:
		obj.setRefill(0);
		break;
	default: cout << "Invalid Entry\n";
	}

	cout << "Is the ink in the marker currently filled\n1- Yes\n2- No\nEnter your choice : ";
	cin >> tempno;

	switch (tempno) {
	case 1:
		obj.setStat(1);
		break;
	case 2:
		obj.setStat(0);
		break;
	default: 
		cout << "Invalid Entry \n";
	}
		obj.write();
		obj.refillIt();

		return 0;
}