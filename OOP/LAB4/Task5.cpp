#include<iostream>
#include<string>
using namespace std;
string blankarr[] = { "","","" };
string blank = "";

class Office {
	string location, *fur;
	int seatingCap;

public:
	Office(string loc = blank, int seatcap = 0, int lenarr=1) :location(loc), seatingCap(seatcap) {
		fur = new string[lenarr];
	}
	~Office() {
		cout << "Destroying the object\n";
	}
};

int main() {
	string arr[] = { "chair","Table","stationary" };

	Office * ptr = new Office;
	*ptr = Office("Karachi", 20, 3);

	cout << "The created object has been deleted\n";


	return 0;
}