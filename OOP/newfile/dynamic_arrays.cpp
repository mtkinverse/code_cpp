#include<iostream>
using namespace std;

int* takeInput(int* arr, int n) {
	cout << "Taking input in the array" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Value " << i + 1 << " : ";
		cin >> *(arr+i);
	}
	cout << "\nThe value has been stored successfully\n";
	return arr;
}

int main() {

	int ind;
	cout << "Enter the nunber of elements you want to store : ";
	cin >> ind;
	int* arr = new int[ind];

	int *newarr=takeInput(arr, ind);
	 
	cout << "The current array is : ";
	cout << *newarr;

	cout << endl;
	for (int i = 1; i < ind; i++) cout << "," << *(newarr + i);
	return 0;

}