#include<iostream>

using namespace std;
int arr[10];

void takeInput() {
	cout << "Enter the values in the array" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Value " << i + 1 << " : ";
		cin >> arr[i];
	}
}
void takeInput2() {
	cout << "Enter the index 0-9 you want to store the value : ";
	int ind;
	cin >> ind;
	if (ind < 0 || ind>9) cout << "You have entered the wrong index" << endl;
	else {
		cout << "Enter the value at this index : ";
		cin >> arr[ind];
	cout << "The value has been stored successfully" << endl;
	}
}

void clearSpecific() {
	int ind;
	cout << "Enter the index you want to clear between 0-9 : ";
	cin >> ind;
	if (ind < 0 || ind>9) cout << "You have entered the wrong index" << endl;
	else {
		arr[ind] = 0;
	cout << "The value has been removed successfully" << endl;
	}
}

void clearAll() {
	cout << "Clearing all the array " << endl;
	for (int i = 0; i < 10; i++) arr[i] = 0;

}


void display() {
	cout << endl;
	cout << "The current array is : ";
	cout << arr[0];
	for (int i = 1; i < 10; i++) cout << "," << arr[i];
	cout << endl;
}

int main() {

	cout << "Welcome to the program" << endl;
	takeInput();
	display();
	takeInput2();
	display();
	clearSpecific();
	display();
	clearAll();
	display();

	return 0;
}