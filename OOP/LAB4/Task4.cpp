#include<iostream>
#include<string>
using namespace std;
string blankarr[] = { "","","" };
string blank = "";
class Office {
	string location,fur[3];
	int seatingCap;

public:
	Office(string loc=blank, int seatcap = 0 , string arr[]=blankarr):location(loc),seatingCap(seatcap) {
		for (int i = 0; i < 3; i++)fur[i] = arr[i];
	}
	
};

int main() {
	string arr[] = { "chair","Table","stationary" };
	Office obj("pakistan",15, arr);
	Office obj1("karachi");
	Office obj2("Punjab", 200);

	
	return 0; }