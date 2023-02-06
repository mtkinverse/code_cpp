#include<iostream>
using namespace std;
enum Alph{A,B,C,D,E,F};

void display(char var1, char var2, char var3) {
	cout << var1 << " " << var2 << " " << var3 << endl;
}

char storeValues(Alph val) {

	switch (val) {
	case 0: return 'a'; break;
	case 1: return 'b'; break;
	case 2: return 'c'; break;
	case 3: return 'd'; break;
	case 4: return 'e'; break;
	case 5: return 'f'; break;
	}
}
int main() {
	Alph val = A;
	char var1 = storeValues(val);
	val = C;
	char var2 = storeValues(val);
	val = E;
	char var3 = storeValues(val);

	display(var1, var2, var3);
	return 0;
}