#include<iostream>
#include<string>
using namespace std;

class NumDays {
	float days, hours;
public:
	NumDays(float hours= 0) {
		this->hours= hours;
		setDays();
	}
	void setDays() {
		days = hours / 8;
	}
	void setHours(float hours) { 
		this->hours = hours; 
		setDays();
	}
	float getDays()const { return days; }
	float getHours()const { return hours; }

	NumDays operator+(const NumDays& obj) {
		NumDays temp(hours+obj.hours);
		return temp;

	}
	NumDays operator-(const NumDays& obj) {
		NumDays temp(hours-obj.hours);
		return temp;
	}
	void operator++() {
		hours++;
		setDays();
	}
	void operator++(int) {
		operator++();
		setDays();
	}
	void printDetails() {
		cout << "Hours : " << hours << "\tDays : " << days << endl;
	}


};

int main() {
	NumDays obj1(12);
	cout << obj1.getDays() << " numbe of days in first object" << endl;
	NumDays obj2(18);
	cout << obj2.getDays() << " numbe of days in second object" << endl;

	NumDays AddObj = obj1 + obj2;
	cout << "Added Object\n\t";
	AddObj.printDetails();
	NumDays SubbObj = obj1 - obj2;
	cout << "Subtracted Object\n\t";
	SubbObj.printDetails();
	cout << "After the increment of the added object\nAdded object\n\t";
	AddObj++;
	AddObj.printDetails();
	cout << "After the increment of the subtracted object\nSubtracted object\n\t";
	++SubbObj;
	SubbObj.printDetails();

	return 0;
}