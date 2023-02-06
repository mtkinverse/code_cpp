#include<iostream>
#include<string>
using namespace std;
string dum;

struct airplane {
	int model;
	string  role, orig, manu;
	bool status=true;
};

void TakeInput(struct airplane* arr,int ind) {
	cout << "Enter The information about the planes\n";
	for (int i = 0; i < ind; i++) {
		cout << "Plane " << i + 1 << endl;
		fflush(stdin);
		getline(cin, dum);
		cout << "Role : "; getline(cin, arr[i].role);
		cout << "Origin : "; getline(cin, arr[i].orig);;
		cout << "Manufacturer : "; getline(cin, arr[i].manu);
		fflush(stdin);
		cout << "Status\n0- Not in service\n1-Service\nEnter The value 0-1 : ";
		cin >> arr[i].status;
		cout << "Model : "; cin >> arr[i].model;
		fflush(stdin);
		cout << endl;
	}
}

void display(struct airplane* arr, int ind) {
	cout << "Displaying the information you stored\n";
	for (int i = 0; i < ind; i++) {
		cout << "Airplane " << i + 1 << endl << "Model : " << arr[i].model << endl << "Role :  " << arr[i].role << endl << "Origin : " << arr[i].orig << endl << "Manufacturer : " << arr[i].manu<<endl<<"service : ";
		if (arr[i].status)cout << "In service";
		else cout << "Not in service";
		cout << endl<<endl;
	}
}
int main() {
	airplane* arr;
	int ind;
	cout << "How many planes do you want to store : ";

	cin >> ind;
	fflush(stdin);

	arr = new airplane[ind];
	
	TakeInput(arr,ind);
	display(arr, ind);
	return 0;
}