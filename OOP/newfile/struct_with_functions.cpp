#include<iostream>
#include<string>
using namespace std;
struct pokemon {
	float height, weight;
	string strarr[3];

	void attack() {
		cout << "Attacked with one of its move" << endl;
	}

	void dodge() {
		cout << "Dodge successfully" << endl;
	}
};

void showdetails(struct pokemon var) {
	cout << "Types\n";
	for (int i = 0; i < 3; i++) cout << var.strarr[i] << endl;
	cout << "Height : " << var.height << endl << "Weight : " << var.weight << endl;
	var.attack();
	var.dodge();
}

int main() {



	pokemon var;

	var.height = 6.00;
	var.weight = 12.00;
	var.strarr[0] = "Electric";
	var.strarr[1] = "Water";
	var.strarr[2] = "Fire";
	showdetails(var);
	return 0;
}