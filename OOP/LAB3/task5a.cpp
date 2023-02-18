#include<iostream>
#include<string>
using namespace std;

class Shop {
	string name[10];
	float price[10];

public:
	void setName(string val,int no) {
		name[no] = val;
	}
	void setPrice(float val,int no) {
		price[no] = val;
	}

	string getName(int no) { return name[no]; }
	float getPrice(int no) { return price[no]; }

	void genRec() {
		int tempno,*itemno,*quan;
		cout << "Give the number of items customer has bought : ";
		cin >> tempno;
		itemno = new int[tempno];
		quan = new int[tempno];
		for (int i = 0; i < tempno; i++) {
			cout << "Give the number of item number " << i + 1 << " : ";
			cin >> itemno[i];
			itemno[i] -= 1;
			cout << "Give the quantity of this item : ";
			cin >> quan[i];
		}

		cout << "-->> The Customer have bought \n";
		float tempprice = 0;
		for (int i = 0; i < tempno; i++) {
			cout << quan[i] << " " << name[itemno[i]] << " : " << price[itemno[i]] * quan[i]<<endl;
			tempprice+= price[itemno[i]] * quan[i];
		}

		cout << "The net price is : " << tempprice << "\n\nTHANKS\n";
	}
};

void displayAll(Shop obj) {

	cout << "Displaying the items in the shop\n";

	for (int i = 0; i < 10; i++) {
		cout << "Item " << i + 1 << "\nName : " << obj.getName(i) << "\nPrice : " << obj.getPrice(i) << endl << endl;
	}
}

int main() {
	Shop obj;
	string temps;
	int tempno;
	float tempf;
	for (int i = 0; i < 10; i++) {

		cout << "Give the name of the material "<<i+1<<" : ";

		fflush(stdin);
		getline(cin,temps);
		fflush(stdin);
		obj.setName(temps, i);

		cout << "Give the price of the material : ";
		cin >> tempf;
		obj.setPrice(tempf, i);
		cout << endl;
		fflush(stdin);
		getline(cin, temps);
	}

	while (1) {
		cout << "Select the number according to your desired operation\n 1-> Display All items\n 2-> Edit price\n 3-> Fetch list\n 4-> Generate receipt\n 5-> Exit\nEnter your choice : ";
		cin >> tempno;

		switch (tempno) {
		case 1: displayAll(obj); break;
		case 2: 
			cout << "Give the number of the material you want to edit : ";
			cin >> tempno;
			if (tempno > 0 && tempno <= 10) {
				cout << "Give the new price : ";
				cin >> tempf;
				obj.setPrice(tempf, tempno - 1);
			}
			else cout << "Invalid Entry !\n";

			break;

		case 3:
			cout << "The list of the current items is\n";
			for (int i = 0; i < 10; i++)cout << obj.getName(i) << endl;
			break;

		case 4: 
			obj.genRec();
			break;
		case 5: exit(0); break;
		}
	}
	return 0;
}
	