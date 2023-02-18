#include<iostream>
#include<string>
using namespace std;

class WeekDays {
	string days[7];
	int currentday;

public:
  
	WeekDays() {
		days[0] = "Sunday";
		days[1] = "Monday";
		days[2] = "Tuesday";
		days[3] = "Wednesday";
		days[4] = "Thursday";
		days[5] = "Friday";
		days[6] = "Saturday";
	}

	WeekDays(int val) {
		if (val > 30)cout << "This day does not exist";
		else {
			currentday = val % 7;

			days[0] = "Sunday";
			days[1] = "Monday";
			days[2] = "Tuesday";
			days[3] = "Wednesday";
			days[4] = "Thursday";
			days[5] = "Friday";
			days[6] = "Saturday";
		}
	}

	string getCurrentDay() { 
		if ((currentday - 1) < 0)return days[6];
		else return days [currentday-1]; }
	string getNextDay() { return days[currentday]; }
	string getPreviousDay() { 
		if ((currentday - 2) < 0) {
			if ((currentday - 2) == -2)return days[5];
			else return days[6];
		}else
		return days[currentday-2]; }

	string getNthDay(int val){
		int i,ind = val % 7;
		
		for ( i = 1; i <= ind;i++) {
			if (i >= 7)i = 1;
		}

	return days[i-1];
	}

};

int main() {
	WeekDays obj(1);
	cout<<"The Current day is "<<
	obj.getCurrentDay();
	cout<<"\nThe next day is : "<<
	obj.getNextDay();
	cout<<"\nThe previous dya was : "<<
	obj.getPreviousDay();
	cout << "\nThe Nth day is : " << 
		obj.getNthDay(12);
	return 0;
}