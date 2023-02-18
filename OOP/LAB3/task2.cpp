#include<iostream>
#include<string>
using namespace std;

class WaterBottle {
	string company, color;
	float cap_l, cap_ml, maxCap = 1000.00;

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

	void setCapl() {
		cap_l = maxCap/1000;
	}
	void setCapml() {
		cap_ml = maxCap;
	}

	float getCapl() { return cap_l; }
	float getCapml() { return cap_ml; }

	void updateCap(float val) {

		if (val > cap_ml)cout << "You cannot drink much water from the bottle\n";
		cap_ml -= val;
		cap_l -= (val / 1000);
		if (cap_ml <= 0) {
			cout << "The water in the bottle ended !\n";
			exit(1);
		}

	}
};

int main() {

	string temps;
	int tempno;

	WaterBottle bot;

	cout << "Give the name of the company of the bottle : ";
	fflush(stdin);
	getline(cin, temps);
	fflush(stdin);
	bot.setComp(temps);
	cout << "Give the color of the bottle : ";
	fflush(stdin);
	getline(cin, temps);
	fflush(stdin);
	bot.setCol(temps);
	bot.setCapl();
	bot.setCapml();
	float tempf;

	cout << "How many mili litres you drink the water from the bottle : ";
	cin >> tempf;
	bot.updateCap(tempf);
	cout << "The Current capacity of bottle in litres " << bot.getCapml() << "\nWhile in litres is " << bot.getCapl() << endl;



	return 0;
}