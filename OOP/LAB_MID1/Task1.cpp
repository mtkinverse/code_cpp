#include <iostream>
#include<string>
using namespace std;
string dum;
class process {
	string pid, name, priority;
	int memory;
public : 
	process(){
		pid = "Default Pid";
		name = "Default Name";
		priority = "Default Priority";
		memory = 3;
	}
	process(string pid,string name,string priority,int memory){
		this->pid = pid;
		this->name = name;
		this->priority = priority;
		this->memory = memory;
	}

	void displayDetails()const{
		cout << "Pid : " << pid << "\nName : " << name << "\npriority : " << priority <<"\nMemory :"<<memory<< endl;
	}

	void setPid(string pid) { this->pid = pid; }
	void setName(string name) { this->name = name; }
	void setPriority(string priority) { this->priority = priority; }
	void setMemory(int memory) { this->memory = memory; }
};

class Sheduler {
	int maxProcess, numProcess;
	process* arr;
public:
	Sheduler() {
		maxProcess = 3;
		numProcess = 0;
		arr = new process[maxProcess];
		numProcess += 3;
	}
	Sheduler(int maxProcess) {
		this->maxProcess = maxProcess;
		numProcess = maxProcess;
		arr = new process[maxProcess];

		for (int i = 0; i < maxProcess; i++) {
			string pid, name, priority;
			int memory;
			cout << "- process " << i + 1 << " :\nPid : ";
			cin.clear();
			getline(cin, dum);
			getline(cin, pid);
			cin.clear();
			cout << "Name : ";
			cin.clear();
			getline(cin, dum);
			getline(cin, name);
			cin.clear();
			cout << "Priority : ";
			cin.clear();
			getline(cin, dum);
			getline(cin, priority);
			cin.clear();
			cout << "memory :"; cin >> memory;
			arr[i].setMemory(memory);
			arr[i].setPid(pid);
			arr[i].setName(name);
			arr[i].setPriority(priority);

		}
	}
		void displayall()const {

			for (int i = 0; i < maxProcess; i++) {
				cout << endl;
				arr[i].displayDetails();
			}
		}
	
};




int main()
{
	Sheduler obj1;
	Sheduler obj2(5);
	cout << "\n-->> Constructed with default one\n";
	obj1.displayall();
	cout << "\n-->> Constructed with parameterz\n";
	obj2.displayall();

}