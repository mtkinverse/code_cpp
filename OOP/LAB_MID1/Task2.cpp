#include <iostream>
using namespace std;

class Vehicle {
	string type;
	float speed, location;
public:
	Vehicle(){}
	Vehicle(string type,float speed,float location){
		this->speed = speed;
		this->type = type;
		this->location = location;
	}
	void UpdateLocation(float time) {
        if(time>1)time=1;
		location += (speed * time);
	}
	float getLocation()const { return location; }
	float getSpeed()const { return speed; }
	string getName()const { return type; }
};

class Road {
	float length, speedLimit, trafficLevel;
	Vehicle* vcls;
public:
	~Road() { delete[] vcls; }
	Road() {
		length = 100;
		speedLimit = 70;
		trafficLevel = 0.5;
		vcls = new Vehicle;
	}
	void AddVehicle(Vehicle& veh) {
        
        if(veh.getSpeed()>speedLimit){
            
        cout<<"Vehicle cannot be added because of exceeding the speed limit !"<<endl;
        return;
        
		}
        
        int n = (sizeof(vcls) / sizeof(Vehicle));
		Vehicle* temp=new Vehicle[n];
		vcls = new Vehicle[n + 1];
		for (int i = 0; i < n; i++) {
			vcls[i] = temp[i];
		}
		delete[] temp;
		vcls[n] = veh;
	}
	float travelTime(Vehicle* vh) {
		return (length/vh->getSpeed());
	}
	void removeVehicle(Vehicle* vh) {
		int n = sizeof(vh) / sizeof(Vehicle);
		for (int i = 0; i < n; i++) {
			if (vh->getName().compare(vcls[i].getName())) {
				for (int j = i; j < n - 1; j++) {
					vcls[j] = vcls[j + 1];
				}
				Vehicle* temp = new Vehicle[n - 1];
				vcls = new Vehicle[n - 1];
				for (int i = 0; i < n - 1; i++) {
					vcls[i] = temp[i];
				}
				delete[] temp;
				return;
			}
		}
		cout << "Object not found!\n";
	}

};

int main()
{
	Vehicle car("Car", 20, 0);
	Vehicle truck("Truck", 10, 0);
	Road rd;
	rd.AddVehicle(car);
	rd.AddVehicle(truck);

	float time1 = rd.travelTime(&car);
	float time2 = rd.travelTime(&truck);

	 car.UpdateLocation(time1); 
 truck.UpdateLocation(time2); 

 cout << "The current location of car is " << car.getLocation() << " and truck is " << truck.getLocation()<<endl;

 return 0;
}