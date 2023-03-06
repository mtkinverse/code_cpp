#include<iostream>
#include<string>
using namespace std;

class Engine {
	string model;
	int mfgyear,cap;
public:
	Engine(){}
	Engine(string model,int mfgyear,int cap){
		this->model = model;
		this->mfgyear=mfgyear;
		this->cap = cap;
	}
	void setCap(int cap) {
		this->cap = cap;
	}
	void setModel(string model) {
		this->model = model;
	}
	void setmfgyear(int mfgyear) {
		this->mfgyear= mfgyear;
	}
	string getModel()const {
		return model;
	}
	int getmfgyear()const {
		return mfgyear;
	}
	int getCap()const {
		return cap;
	}
};
class wheels {
	string company;
	int mfgyear;
	float pressure;
public:
	wheels(){}
	wheels(string company,int mfgyear,float pressure){
		this->mfgyear = mfgyear;
		this->pressure = pressure;
		this->company = company;
	}
	string getComp()const { return company; }
	float getPressure()const { return pressure; }
	float getMfgyear()const { return mfgyear; }

	void setComp(string company) { this->company = company; }
	void setPressure(float pressure) { this->pressure= pressure; }
	void setMfgyear(int mfgyear) { this->mfgyear= mfgyear; }

};

class headlights {
	string company;
	int mfgyear;
public:
	headlights(){}
	headlights(string company,int mfgyear){
		this->company = company;
		this->mfgyear = mfgyear;
	}
	void setComp(string company) { this->company = company; }
	void setMfgyear(int  mfgyear) { this->mfgyear = mfgyear; }

	string getComp()const { return company; }
	int getMfgyear()const { return mfgyear; }
};

class steering{
	string model;
	int mfgyear;
public:
	steering(){}
	steering(string model,int mfgyear){
		this->mfgyear = mfgyear;
		this->model = model;
	}

	void setModel(string model) {
		this->model = model;
	}
	void setModel(int mfgyear) {
		this->model = mfgyear;
	}

	string getModel()const { return model; }
	int getMfgyear()const { return mfgyear; }
};
class car {
	string model,regno;
	Engine* eng;
	wheels* wh;
	headlights* hd;
	steering* st;
public:
    ~car(){
        cout<<"\nIn the destructor of car\n";
        delete eng;
        delete wh;
        delete hd;
        delete st;
    }
		//note the eng and all other objects we decalre dynamically will remain even if the car calss is destroyed because it has only pointer and not the object
// I have assumed that all four wheels will be of same company and will be updated at a time together
	car() {
		eng = new Engine;
		wh = new wheels;
		hd = new headlights;
		st = new steering;
	}
	car(string model,  string regno){
		this->model = model;
		this->regno = regno;
	}
	car(Engine* eng, wheels* wh, headlights* hd,steering* st,string model,string regno) {

		this->eng = new Engine;
		this->wh = new wheels;
		this->hd = new headlights;
		this->st = new steering;

		this->hd = hd;
		this->wh = wh;
		this->eng = eng;
		this->model = model;
		this->regno = regno;
		this->st = st;

	}
	void setModel(string model) {
		this->model = model;
	}
	void setRegno(string regno) {
		this->regno= regno;
	}
	string getModel()const {
		return model;
	}
	string getRegno()const {
		return regno;
	}

	void GiveInfo()const{
		cout << "\nThe car " << model << " has model " << regno << ". Which has an engine of " << eng->getCap() << "cc with a model of " << eng->getModel() << " and is manufactured in " << eng->getmfgyear() << " and following different components\n\n~Steering:\nModel : " << st->getModel() << "\nManufactured year : " << st->getMfgyear() << "\n\n~Wheels:\nCompany : " << wh->getComp() << "\nManufactured year : " << wh->getMfgyear() << "\nBearing pressure : " << wh->getPressure() << "\n\n~Head lights:\nCompany : " << hd->getComp() << "\nMFG year : " << hd->getMfgyear() << endl;
	}

    void changeEngine(Engine* eng){
        this->eng=new Engine;
        this->eng=eng;
    }
    void changeWheels(wheels* wh){
        this->wh=new wheels;
        this->wh=wh;
    }
    void changeSteering(steering* st){
        this->st=new steering;
        this->st=st;
    }
    void changeLights(headlights* hd){
        this->hd=new headlights;
        this->hd=hd;
    }
	 
};


int main() {

	Engine eng("SLN2021", 2021, 1200);
	wheels wh("Panther", 2021, 800);
	headlights hd("HD", 2021);
	steering st("ST002", 2021);

	car toyota(&eng,&wh,&hd,&st,"Dont Know", "22k-4609");
	toyota.GiveInfo();
	
    headlights hd1("NEw HD",2022);
    toyota.changeLights(&hd1);
    cout<<endl<<" -->> After changing the lights"<<endl;
    toyota.GiveInfo();

	return 0;
}