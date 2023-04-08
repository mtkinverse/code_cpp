#include <iostream>
#include <string>
using namespace std;
class MenuItems {
	string name,type;
	float price;
public:
	MenuItems(){}
	MenuItems(string name,string type,float price){
		this->name = name;
		this->price = price;
		this->type = type;
	}
	string getName()const { return name; }
	string getType()const { return type; }
	float getPrice()const { return price; }
};

class Restraunt {
	MenuItems* items; 
	string name,phone,address;
	float rating;
public:
    ~Restraunt(){delete[] items;}
	Restraunt(){}
	Restraunt(MenuItems arr[],string name,string phone,string address,float rating){
		this->name = name;
		this->phone = phone;
		this->address = address;
		this->rating = rating;
		int n =(sizeof(arr)/sizeof(MenuItems));
		items = new MenuItems[n];
		for (int i = 0; i < n; i++) {
			items[i] = arr[i];
		}
	}

	void add_menuItem(int n) {
		int size = sizeof(items) / sizeof(MenuItems);
		if (n == (size + 1)) {
			MenuItems* temp = new MenuItems[size];
			for (int i = 0; i < size; i++)temp[i] = items[i];
			items = new MenuItems[n];
			for (int i = 0; i < size; i++)items[i] = temp[i];
			string name, type;
			float price;
			cout << "Give the Information of the new item\nName : ";
			cin.clear();
			getline(cin, name);
			cin.clear();
			cout << "Type : ";
			cin.clear();
			getline(cin, type);
			cin.clear();
			cout << "Price : ";
			cin >> price;
			cout << "NEw Item added\n";

		}
	}

	MenuItems* GetMenu()const {
		return items;
	}
};

class Italian : public Restraunt {
	string pastaType, pizzaType;
public: 
	Italian(){}
	Italian(string pastaType,string pizzaType,MenuItems arr[], string name, string phone, string address, float rating): Restraunt(arr,name,phone,address,rating){
		this->pastaType=pastaType;
		this->pizzaType=pizzaType;
	}
 void makePasta(string type){
	cout<<"Makng pasta of "<<type<<" type\n";
	pastaType=type;
	}	

 void makePizza(string type){
	cout<<"Makng pizza of "<<type<<" type\n";
	pizzaType=type;
	}	
};

class Mexican : public Restraunt{
	int spiceLevel;
	string salsaType;
	public:
	Mexican(){}
	Mexican(int spiceLevel,string salsaType,MenuItems arr[],string name,string phone,string address,float rating):Restraunt(arr,name,phone,address,rating){
		this->spiceLevel=spiceLevel;
		this->salsaType=salsaType;
	}
	void makeTaco(string filling){cout<<"Taco prepared with the "<<filling<<" filling"<<endl; }
	void makeBuretto(string filling){cout<<"Buretto prepared with the "<<filling<<" filling"<<endl; }
};

int main()
{
   //since no task specified 
   MenuItems mexican[3]={MenuItems("Name1","Type1",20.00),MenuItems("Name2","Type2",25.00),MenuItems("Name3","Type3",15.50)};

//    cout<<"Size of mexican : "<<sizeof(mexican)/sizeof(MenuItems)<<endl;

   MenuItems italian[2]={MenuItems("Name4","Type4",12.35),MenuItems("Name5","Type5",14.50)};

   Mexican mexica(2,"Type of salsa",mexican,"The Mexican Restraunt","030629236598","Adress of Mexican Restraunt",4.35);

   Italian italiat("Type of Pasta","Type of Pizza",italian,"The Italian Restraunt","03012992395","Adress of Italian Restraunt",3.9);

   mexica.makeTaco("FillngName");
   italiat.makePizza("PizzaType");
   return 0;
   }