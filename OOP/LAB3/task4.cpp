#include<iostream>
#include<string>
using namespace std;

class Phone {
	string company;
	int model, RAM, ROM, storage;
	int resol[2];

public:
	void setComp(string name) {
		company = name;
	}
	void setMod(int val) {
		model = val;
	}
	void setRam(int val) {
		RAM = val;
	}
	void setRom(int val) {
		ROM = val;
	}
	void setStor(int val) {
		storage = val;
	}
	void setResol(int val1, int val2) {
		resol[0] = val1;
		resol[1] = val2;
	}

	string getComp() {
	return company;
	}
	int getMod() {
	return model;
	}
	int getRes1() {
	return resol[0];
	}
	int getRes2() {
	return resol[1];
	}
	int getRam() {
	return RAM;
	}
	int getRom() {
	return ROM;
	}
	int getStor() {
	return storage;
	}
	
	void makeCall() {
		cout << "A phone call has been made\n";
	}
	void sendMess() {
		cout << "A message has been sent\n";
	}
	void connWifi() {
		cout << "Connnected to the wifi\n";
	}
	void Browse() {
		cout << "Browsing at the internet\n";
	}
};


int main() {
	string temps;
	int tempno1,tempno2,tempno;

	Phone *obj=new Phone[2];
	for (int i = 0; i < 2; i++) {
		cout << "Give the information of the mobile " << i + 1 << endl;
		cout << "Give the name of the company : ";
		fflush(stdin);
		getline(cin, temps);
		fflush(stdin);
		obj[i].setComp(temps);

		cout << "Give the model of the phone : ";
		cin >> tempno;
		obj[i].setMod(tempno);

		cout << "Give the features of the phone\n-> Resolution : ";
		cin >> tempno1 >> tempno2;
		obj[i].setResol(tempno1, tempno2);
		cout << "-> RAM : ";
		cin >> tempno;
		obj[i].setRam(tempno);
		cout << "-> ROM : ";
		cin >> tempno;
		obj[i].setRom(tempno);
		cout << "-> Storage : ";
		cin >> tempno;
		obj[i].setStor(tempno);
		fflush(stdin);
	}

	for (int i = 0; i < 2; i++) {
		cout << "The information you stored about mobile" << i + 1 << "\nCompany : " << obj[i].getComp() << "\nModel : " << obj[i].getMod() << "\nResolution : " << obj[i].getRes1() << "x" << obj[i].getRes2() << "\nRAM : " << obj[i].getRam() << "\nROM : " << obj[i].getRom() << "\nStorage : " << obj->getStor() << endl << endl;
	}
	
	return 0;
}