#include<iostream>
#include<string>
using namespace std;

class Transaction;
class BankAccount {

	double Balance;
	int acc_no;
	string name;
public:
	friend void ProcessTransaction(BankAccount&, const Transaction&);
	BankAccount(){}
	BankAccount(double bal,int no,string val){
		Balance = bal;
		acc_no = no;
		name = val;
	}
	void Deposit(double amount) {
		Balance += amount; 
		cout << "Amount added succesfully to the account !\n";
	}
	void WithDraw(double amount) {
		if (amount <= Balance) {
			Balance -= amount;
			cout << "RS. " << amount << " deducted from your account !\n";
		}
		else cout << "Insufficint amount ! \n";
	}
	double getBalance()const { return Balance; }
};

class Transaction {
	friend void ProcessTransaction(BankAccount&,const Transaction&);
	int amount;
	string Description;
public:
	Transaction(int amount, string Description) {
		this->amount = amount;
		this->Description = Description;
	}

	string ToString() {
		return Description;
	}
    void setAmount(int val){amount=val;}
};

void ProcessTransaction(BankAccount& account, const Transaction& transaction) {
	if (transaction.amount <= 0) {
		if ((account.Balance + transaction.amount) < 0){
            cout<<"Insufficient ammount !\n";
            return;
            }
	}
	account.Balance += transaction.amount;

	int temp=transaction.amount;
	if (transaction.amount < 0) {
        cout<< "Withdrawl of ";
        temp*=-1;
    }
	else cout<< "Deposit of ";
	
    cout<<temp;
    cout<<" for "<<transaction.Description<<endl;
}


int main() {
	BankAccount acc(1200, 4609, "Muhammad Taha Khan");
	Transaction checque(200, "Electronics");
	ProcessTransaction(acc, checque);

    checque.setAmount(-500);

	cout << "The current balance is " << acc.getBalance() << endl<<endl;
    
    ProcessTransaction(acc,checque);
	cout << "The current balance is " << acc.getBalance() << endl<<endl;
	return 0;

}