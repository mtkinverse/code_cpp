#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
		string temps,st;

	ifstream rfile("Lab11.txt", ios::in);
	
	
	while (!rfile.eof()) { 
		getline(rfile, temps);
		st.append(temps); 
	}
	int fullstop, Vowels, spaces, Capital;
	fullstop = Vowels = spaces = Capital = 0;

	for (int i = 0; i < st.length(); i++) {
		switch (st[i]) {
		case'A':case 'E':case 'I':case 'O':case 'U':
			Capital++;
			Vowels++;
			break;
		case 'a':case 'e':case 'i':case 'o':case 'u': Vowels++; break;
		case '.':fullstop++; break;
		case 32: spaces++; break;
		}
		if (st[i] >= 65 && st[i] <= 90 && st[i] != 'A' && st[i] != 'E' && st[i] != 'I' && st[i] != 'O' && st[i] != 'U') Capital++;
	}

	char ch; 
	int foundFullstop=0, ind=0;
    rfile.seekg(0);
    while(!rfile.eof()){
        ch=rfile.get();
        if(ch =='.'){
            foundFullstop++;
            }
        if(ch =='.' && foundFullstop>1){
            break;
        }
        ind++;
    }

    cout<<"The index appers As : "<<ind<<endl;
	rfile.close();

fflush(stdin);

	fstream outfile("Lab11.txt",ios_base::ate|ios::in|ios::out);
    outfile.seekp(ind);
	outfile<< fullstop << " " << Vowels << " " << spaces << " " << Capital ;
	outfile.close();
	cout << " -> The new materila is \n";
	string temps1;
	ifstream newfile("Lab11.txt", ios::in);
	while (getline(newfile, temps1)) { cout << temps1 << endl; }
	newfile.close();
}