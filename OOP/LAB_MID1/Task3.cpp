#include <iostream>
#include<string>
using namespace std;
string dum;//just to make the input of string possible

class Product {
	string name;
	float price;
	int quantity;
public:
	Product(){}
	Product(string name,float price,int quantity){
		this->name = name;
		this->price = price;
		this->quantity = quantity;
	}
	void UpdateQuan(int val) {
		quantity += val;
	}
	string getName()const { return name; }
	float getPrice()const { return price; }
	float getQuan()const { return quantity; }

};

void PrintInventory(int n,Product* arr){
	for (int i = 0; i < n; i++) {
		cout << "\n-> Material " << i + 1 << " :\nName : " << arr[i].getName() << "\nPrice : " << arr[i].getPrice() << "\nQuantity : " << arr[i].getQuan() << endl;
}
}

int main(){
	cout << "How many products do you want to enter : ";
	int n;
	cin >> n;
	Product* arr = new Product[n];
	cout << "Enter the attributes of the product : ";

	for (int i = 0; i < n; i++) {
		string name;
		float price;
		int quantity;
		cout << "Product " << i + 1 << "\nName : ";
		cin.clear();
        getline(cin, dum);
		getline(cin, name);
		cin.clear();
		cout << "Price : ";
		cin >> price;
		cout << "Quantity : ";
		cin >> quantity;
		arr[i] = Product(name, price, quantity);
	}

	PrintInventory(n,arr);
	return 0;
}