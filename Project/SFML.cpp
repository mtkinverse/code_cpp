
#include<iostream>
#include<string>
#include<sstream>
#include<ctime>
#include<cstring>
#include<fstream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace std;

char blank[30] = "";

void CopyToLast(char arr[], char arr2[]) {
	int n = strlen(arr2);
	int n1 = strlen(arr);
	if (n == n1) {
		for (int i = 0; i < n; i++) {
			arr[i] = arr2[i];
		}
	}
}

class Position {

	float x, y;
	sf::Vector2i mosPos1;
	sf::Vector2f mosPos2;

public:

	Position(float x = 0, float y = 0) {
		this->x = x;
		this->y= y;
		mosPos1.x = 0;
		mosPos1.x = 0;
		mosPos2.x = 0;
		mosPos2.y = 0;
	}

	void setX(float val) {
		this->x = val;
	}

	void setY(float val) {
		this->y = val;
	}

	 
	const float getX() const { return x; }
	
	const float getY() const { return y; }
	

	void moveFront(float x) { this->x+=x; }

	void moveBackward(float x) { this->x-=x; }

	void moveUp(float y) { this->y+=y; }

	void moveDown(float y) { this->y-=y; }

	void move(float x, float y) {

		this->x += x;
		this->y += y;

	}

};

class Game;
class Surfaces;
class Enemy;

class Player {


protected:

	Position pos;
	string name;
	int xValue;
	int ID,lifes,score;
	sf::Sprite Shape;
	sf::Texture texture;
	friend class Game;

public:

	Player(){
		ID = lifes = score = xValue= 0;
	}
	Player(string name, int ID, int lifes, int score):xValue(0) {
		
		this->ID = ID;
		this->lifes = lifes;
		this->score = score;
		this->name = name;
		pos.setX(200.0f);
		pos.setY(200.0f);
	}

	void setName(string val) { this->name = val; }
	void setID(int val) { this->ID= val; }
	void setLifes(int val) { this->lifes= val; }
	void setScore(int val) { this->score= val; }
 
	virtual sf::Sprite getShape()=0;
	virtual bool CheckItem(int val)=0;
	virtual void EnableItem(int val)=0;
	virtual void DisableItem(int val)=0;
	virtual sf::Texture getTexture()=0;

	virtual void drawShape(sf::RenderWindow* window) {
		window->draw(this->Shape);
	}

	virtual void MoveFront() {
		if (xValue < 135)
			xValue += 45;
		else xValue = 0;
		this->Shape.setTextureRect(sf::IntRect(xValue, 70, 45, 62));
		
	}

	virtual void MoveBackword() {

		if (xValue > 0)
			xValue = xValue - 45;
		else xValue = 135;
		this->Shape.setTextureRect(sf::IntRect(xValue, 131, 45, 62));

	}

	virtual void MakeItMove(float x, float y) {
		this->Shape.move(sf::Vector2f(x, y));
		pos.move(x, y);
	}

	virtual void MoveUpward(float x, float y) {

		Shape.move(sf::Vector2f(x,-y));

	}

	virtual void MoveDownward(float x, float y) {

		Shape.move(sf::Vector2f(x, y));

	}

	virtual void StandStraight() {

		this->Shape.setTextureRect(sf::IntRect(0, 131, 15, 62));

	}

	virtual void Jump() = 0;
	virtual void JumpForward(sf::RenderWindow* window, float* XValueGround, int* KeyDetector, Surfaces* surface, Game& game)=0;
	virtual ~Player() = 0;

};

Player :: ~Player() {  }

class Mario : virtual public Player {

protected:
	
	bool isHammer, isShield;

public:

	Mario() {
		isHammer = false;
		isShield = false;
		setTexture();
	}

	Mario(string name, int ID, int lifes, int score) :Player(name, ID, lifes, score){
		isHammer = false;
		isShield = false;
		setTexture();
		}

	void  StandStraight() {
		xValue = 140;
		this->Shape.setTextureRect(sf::IntRect(xValue, 0, 45, 65));

	}

	void setTexture() {

		if (!texture.loadFromFile("spritesheet1.png") ) {

			cout << "\n\n ___Error in loading the file of mario____\n";

			system("pause");
		}

		Shape.setTexture(texture);
		Shape.setScale(sf::Vector2f(1.0f, 1.0f));
		Shape.setPosition(pos.getX(),pos.getY());
		Shape.setTextureRect(sf::IntRect(0, 70, 45, 62));

		pos = Position(200.0f, 200.0f);

	}


		void EnableItem(int val) {

			switch (val) {

			case 1: isHammer = true; break;
			case 2: isShield = true; break;

			}

		}


		void DisableItem(int val) {
		
			switch (val) {

			case 1: isHammer = false; break;
			case 2: isShield = false; break;

			}

		}

		bool CheckItem(int val) {
			
			switch (val) {

			case 1: return isHammer;  break;
			case 2: return isShield; break;
			case 3: return lifes; break;
			case 4: return score; break;

			}

		}

		sf::Sprite getShape(){ return this->Shape; }
		
	
		sf::Texture getTexture(){ return texture; }

		void Jump() {

			while (this->Shape.getPosition().y > 150.0f) this->Shape.move(sf::Vector2f(0.0f, -5.0f));

		}

		void JumpForward(sf::RenderWindow* window, float* XValueGround, int* KeyDetector, Surfaces* surface, Game& game);

		~Mario() {
			
		}
};

class Ninja : virtual public Player {

protected :

	bool isArmed, SpecialMove;

public:

	Ninja() {
		isArmed = false;
		SpecialMove = false;
		setTexture();
	}

	Ninja(string name, int ID, int lifes, int score) :Player(name, ID, lifes, score) {
		isArmed= false;
		SpecialMove = false;
		setTexture();
	}

	void setTexture() {
		pos = Position(200.0f, 200.0f);
		if (!texture.loadFromFile("spritesheet2.png") ) {
			cout << "\n\n ___Error in loading the file of mario____\n";
			system("pause");
		}
		Shape.setTexture(texture);
		Shape.setScale(sf::Vector2f(1.8f, 1.8f));
		Shape.setPosition(pos.getX(), pos.getY());
		Shape.setTextureRect(sf::IntRect(0, 0, 30, 30));
		
	}

	void StandStraight() {
		this->Shape.setTextureRect(sf::IntRect(5, 10, 30, 30));
	}

	 void MoveFront() {
		if (xValue < 135)
			xValue += 30;
		else xValue = 15;
		this->Shape.setTextureRect(sf::IntRect(xValue, 45, 30, 30));

	}
	void MoveBackword() {
		if (xValue > 410)
			xValue -= 30;
		else xValue = 500;
		this->Shape.setTextureRect(sf::IntRect(xValue, 45, 30, 30));
		
	}

	void Jump() {

		while (this->Shape.getPosition().y > 150.0f)
			this->Shape.move(sf::Vector2f(0.0f,-3.0f));

	}

	void JumpForward(sf::RenderWindow* window, float* XValueGround, int* KeyDetector, Surfaces* surface, Game& game);

		

	void EnableItem(int val) {
		switch (val) {
		case 1: isArmed = true;  break;
		case 2: SpecialMove = true; break;
		}
	}
	void DisableItem(int val) {
		switch (val) {
		case 1: isArmed = false;  break;
		case 2: SpecialMove = false; break;
		}
	}
	bool CheckItem(int val) {
		switch (val) {
		case 1: return isArmed;  break;
		case 2: return SpecialMove; break;
		case 3: return lifes; break;
		case 4: return score; break;
		}
	}
	sf::Sprite getShape() { return this->Shape; }

	sf::Texture getTexture() { return this->texture; }

	~Ninja(){}
};

class ArmedMario : public Mario, public Ninja {


public:

	ArmedMario(string name, int ID, int lifes, int score) :Player(name, ID, lifes, score){
		
		for (int i = 0; i < 4; i++) DisableItem(i + 1);
		xValue = 60;
		setTexture();

	}

	void setTexture() {

		pos = Position(200.0f, 200.0f);
		if (!texture.loadFromFile("ArmedMarioSheet.png")) {
			cout << "\n\n ___Error in loading the file of mario____\n";
			system("pause");
		}
		Shape.setTexture(texture);
		Shape.setScale(sf::Vector2f(0.7f, 0.7f));
		Shape.setPosition(pos.getX(), pos.getY());
		Shape.setTextureRect(sf::IntRect(110, 100, 70, 100));

	}

	void StandStraight() {

		Shape.setTextureRect(sf::IntRect(100.0,100.0,70,700));

	}

	void MoveFront() {

		if (xValue < 450)
			xValue += 70;
		else xValue = 100;
		
		this->Shape.setTextureRect(sf::IntRect(xValue, 630, 70, 100));

		DisableItem(2);


	}
	 
	void MoveBackword() {

		if (xValue > 775)
			xValue += 70;
		else xValue = 1125;
		
		this->Shape.setTextureRect(sf::IntRect(xValue, 635,70,100));


	}

	sf::Sprite getShape() { return this->Shape; }

	bool CheckItem(int val) {

		switch (val) {

		case 3: return this->SpecialMove; break;
		case 1: return this->isHammer; break;
		case 2: return isShield; break;
		case 4: return isArmed; break;
		}
	}

	void EnableItem(int val) {

		switch (val) {

		case 1: this->isHammer = true; break;
		case 3: this->isArmed = true; break;
		case 2: this->isShield = true; break;
		case 4: this->SpecialMove = true; break;

		}
		
	}

	void DisableItem(int val) {

		switch (val) {

		case 1: this->isHammer = false; break;
		case 3: this->isArmed = false; break;
		case 2: this->isShield = false; break;
		case 4: this->SpecialMove = false; break;

		}
	}
	

	void Jump() {

		while (this->Shape.getPosition().y > 100.0f) this->Shape.move(sf::Vector2f(0.0f, -2.0f));

	}

	
   void JumpForward(sf::RenderWindow* window, float* XValueGround, int* KeyDetector, Surfaces* surface, Game& game);

	
	sf::Texture getTexture() { return this->texture; }

};

class Obstacles {

protected:
	
	sf::Sprite sprite;
	sf::Texture texture;
	Position pos;
	int damage;
	bool Draw;
	
public:

	Obstacles(int damage = 0) {
		this->damage = damage;
		Draw = false;
	}

	bool ShouldDraw() { return Draw; }

	void MakeDrawTrue() { this->Draw = true; }

	void FalseDraw() { this->Draw = false; }

	float GetposX()const{
		return pos.getX();
	}

	float GetposY()const{
		return pos.getY();
	}

	void SetDamage(int val) { this->damage = val; }

	int gtDamage() const { return this->damage; }

	virtual void draw(sf::RenderWindow*) = 0;

	virtual ~Obstacles(){}
};

class Surfaces : public Obstacles{

	int surfaceType;
	friend class Game;

public:

	Surfaces(int surfacetype = 0,int damage =0 ):Obstacles(damage) {
		this->surfaceType = surfacetype;
		setTexture();
	}
	float getPosition(char val) {
		switch (val){
		case 'x':
			return this->sprite.getPosition().x;
		break;
		case 'y':
			return this->sprite.getPosition().y;
		break;
		}
	 }

	void setSprite(const sf::Sprite& sprite) { this->sprite = sprite; }

	void setTexture() {

		if (!this->texture.loadFromFile("Grass.png"))system("pause");
		sprite.setTexture(this->texture);
		sprite.setPosition(0, 150.0f);
		sprite.setScale(sf::Vector2f(2.0f, 1.3f));

		switch (this->surfaceType) {

		case 1:
			sprite.setTextureRect(sf::IntRect(130, 300, 500, 180));
			break;

		case 2:
			sprite.setTextureRect(sf::IntRect(630, 300, 370, 180));
			break;
		}
		
		
		
	}

	void MoveIt(int x, int y) {
		sprite.setTextureRect(sf::IntRect(x, y,500,180));
	}

	void setType(int surfaceType) { 
		this->surfaceType = surfaceType;
		setTexture();
	}

	int getType() const { return this->surfaceType; }

	void draw(sf::RenderWindow* window) {
		window->draw(this->sprite);
	}

	sf::Sprite& getSprite() { 
	
		return this->sprite;

	}

};

class Enemy : public Obstacles{
	
	sf::CircleShape fires;
	int ID;
	friend class Game;

public:

	Enemy(int id= 0, int damage = 0) :Obstacles(damage) {
		this->ID = id;
		SetTexture();
	}

	void SetPosition(float x, float y) {

		fires.setPosition(x, y);
		pos.setX(x+pos.getX());
		pos.setY(y+pos.getY());

	}

	void SetTexture() {

		switch (this->ID) {

		case 1:
			
			fires.setPosition(pos.getX(),pos.getY());
			fires.setFillColor(sf::Color::Red);
			fires.setRadius(3.0f);

			break;
		
		}
	}

	void setID(int id) {
		this->ID= id;
		SetTexture();
	}

	void MoveIt(float x, float y) {

		fires.move(sf::Vector2f(x, y));
		pos.setX(pos.getX()+x);
		pos.setY(pos.getY()+y);

	}

	int getID() const { return this->ID; }

	void draw(sf::RenderWindow* window) {

		switch (this->ID)
		{
		case 1:
			window->draw(this->fires);	break;
		case 2: window->draw(this->sprite); break;
		}
		
	}

	~Enemy(){}
};

class User;

bool checkUser(const User&, int&);


class User {

protected:

	char name[30], password[30], LoginID[30];
	friend bool checkUser(const User&,int&);

public:

	User() {

		CopyToLast(this->LoginID,blank);
		CopyToLast(this->name, blank);
		CopyToLast(this->password,blank);

	}
	
	User(char* name, char* password, char* LoginID) {

		for (int i = 0; i < 30; i++) {

			this->name[i] = name[i];
			this->password[i] = password[i];
			this->LoginID[i] = LoginID[i];

		}

	}


	void setName(char name[] ){ 


	for(int i=0;i<strlen(name);i++)
	   this->name[i] = name[i];

	   this->name[strlen(name)] = '\0';

}

	void setPass(char pass[] ) {


		for (int i = 0; i < strlen(pass); i++)
			this->password[i] = pass[i];

		this->password[strlen(pass)] = '\0';

	}


	void setLoginID(char LoginID[] ) {

		for (int i = 0; i < strlen(LoginID); i++)
			this->LoginID[i] = LoginID[i];

		this->LoginID[strlen(LoginID)] = '\0';


	}

	const char* getName()const { return this->name; }

	const char* getPass()const { return this->password; }

	const char* getLoginID()const { return this->LoginID; }

	bool operator ==(const User& obj) {

		if (strcmp(this->LoginID, obj.LoginID) == 0)return true;

		else return false;

	}

	void displayValues() {
		cout << this->name << " " << this->password << " " << this->LoginID << endl;
	}

};

bool checkUser(const User& obj,int &n ) {

	User temp;
	ifstream file("UserData.bin", ios::binary );

	while (file.read((char*)&temp, sizeof(temp))) {
		n++;
		if (temp == obj){
			file.close();
			return true;
	}
	}
	file.close();
	n = 0;
	return false;
}

class Engine {

public:

	Engine(){}

	static void simulate();

	static bool Login( User& obj, int &n ) {
		
			
				ifstream file("UserData.bin", ios::binary);
				file.seekg((n-1) * sizeof(User));
				User temp;
				file.read((char*)&temp, sizeof(temp));


				if (strcmp((char*)temp.getPass(),(char*)obj.getPass()) == 0){
					
					obj = User((char*)temp.getName(),(char*) temp.getPass(),(char*) temp.getLoginID());
					
				file.close();

				    return true;	
				}
				else {
					
					cout << "\n >> Incorrect Password !\n"<< endl;
				file.close();
					return false;
				}
			
	}

	static bool SignUp(const User& obj) {


		int num=0;

		if(!checkUser(obj,num)){

			ofstream file("UserData.bin", ios::binary | ios::app);
			file.write((char*)&obj, sizeof(obj));
			file.close();

			return true;

		}
		else {
			cout << "\nUser already exist please try again with different login id ! \n";
			return false;
		}

	}

	static bool deleteUser(const User& obj) {

		bool deleted = false;
		int n = 0;

		if (checkUser(obj, n)) {

			User tempobj;
			int temp = 0;

			ifstream file("UserData.bin", ios::binary);
			file.seekg((n-1) * sizeof(User));
			file.read((char*)&tempobj, sizeof(tempobj));

			if (strcmp((char*)tempobj.getPass(),(char*)obj.getPass()) == 0);
			else {
				file.close();
				return false;
			}

			fstream newFile("new.bin", ios::binary|ios::out);
			
			file.seekg(0);
			while (file.read((char*)&tempobj, sizeof(User))) {

				if (temp != (n - 1)) {
					newFile.write((char*)&tempobj, sizeof(tempobj));
				}
				else{
					deleted = true;
					cout <<endl<<n - 1 << endl;
			}
					temp++;
			}

			file.close();
			newFile.close();

			remove("UserData.bin");
			int val = rename("new.bin", "UserData.bin");
			
		}
			return deleted;

	}

	static bool UpdateUser(const User& obj1, const User& obj2) {

		if (deleteUser(obj1)) {

			int n = 0;

			fstream file("UserData.bin", ios::binary | ios::app);
			file.write((char*)&obj2, sizeof(obj2));
			file.close();

			return true;
		}

		else return false;

	}
};

class Game {

	float x = 200, y = 200;
	sf::Texture texture3 , texture ;
	sf::Sprite BackGround[2], Hammer;
	sf::Text GameOver, scoreValue, lifeValue;
	sf::Font font , font2,font3;
	sf::Event Eve;
	int KeyDetector[2] = { 0 };
	sf::RenderWindow* GameWindow;
	Player* mario;
	Enemy* enemies;
	Surfaces* surface;

	void NewWindow() {

		cout << "Enter the Character you want to play with :\n\n 1 - Mario\n\n 2 - Ninja\n\n 3 - Super Ninja\n\nEnter your choice : ";
		int choice;
		cin >> choice;
		try {

			if (choice == 1)
				mario = new Mario("Mario", 1, 3, 0);
			else if (choice == 2)
				mario = new Ninja("Ninja", 2, 3, 0);
			else if (choice == 3) 
				mario = new ArmedMario("Armed Mario", 3, 5, 0);

			else throw 0;

		}

		catch (int val) {

			cout << "No Such player exist ! \n";

			return;

		}

		this->GameWindow = new sf::RenderWindow(sf::VideoMode(800, 400), " -->> V e R t E x ", sf::Style::Titlebar | sf::Style::Close);
		this->GameWindow->setFramerateLimit(30);

	}

	void NewVar() {

		this->GameWindow = nullptr;

	}

public:

	void NewObjects() {


		for (int i = 0; i < 2; i++) {
			surface[i].setType(i + 1);
			surface[i].SetDamage(0);
			surface[i].MakeDrawTrue();
		}

		for (int i = 0; i < 10; i++) {
			enemies[i].SetPosition(float(GameWindow->getSize().x) + rand() % 50, 10.0f + rand() % 250);
			enemies[i] = Enemy(1, 1);
		}


	}

	bool IsWindowOpen()const {
		return this->GameWindow->isOpen();
	}

	Game() {


		surface = new Surfaces[2];

		srand(time(NULL));

		enemies = new Enemy[10];

		NewVar();

		for (int i = 0; i < 10; i++)enemies[i].MakeDrawTrue();


		if (!font.loadFromFile("Arially.otf") || !font2.loadFromFile("Arially.otf") || !font3.loadFromFile("Arially.otf"))cout << "\nError Loading file\n";

		GameOver.setFont(font);
		GameOver.setCharacterSize(100);
		GameOver.setFillColor(sf::Color::White);
		GameOver.setPosition(160.0f, 130.0f);
		GameOver.setString(" Game Over ! ");

		if (!texture.loadFromFile("BackGround.jpg")) cout << "\n\n ___Error in loading the file____\n";

		BackGround[0].setTexture(texture);
		BackGround[1].setTexture(texture);
		BackGround[0].setScale(sf::Vector2f(2.8f, 2.5f));
		BackGround[1].setScale(sf::Vector2f(2.8f, 2.5f));
		BackGround[0].setTextureRect(sf::IntRect(0, 0, 150, 163));
		BackGround[1].setTextureRect(sf::IntRect(150, 0, 150, 163));
		BackGround[1].setPosition(sf::Vector2f(420.0f, 0.0f));


		if (!texture3.loadFromFile("Hammer.png") ) {
			cout << "\n\n ___Error in loading the file of mario____\n";
			system("pause");
		}

		Hammer.setTexture(texture3);
		Hammer.setScale(sf::Vector2f(0.25f, 0.25f));

		scoreValue.setFont(font2);
		scoreValue.setFillColor(sf::Color::Black);
		scoreValue.setString("0");
		scoreValue.setPosition(sf::Vector2f(650.0f,10.0f));

		lifeValue.setFont(font3);
		lifeValue.setFillColor(sf::Color::Black);
		lifeValue.setString("0");
		lifeValue.setPosition(sf::Vector2f(650.0f, 30.0f));
		


	}

	void playIT() {

		NewWindow();
		NewObjects();

	}

	void MoveWindowRight(float* XValueGround) {

		if (KeyDetector[0] % 2 == 0)
			this->mario->MoveFront();

		if (XValueGround[0] >= (500.0f + 130.0f)) {

			XValueGround[0] = 130.0f;

		}
		else {

			XValueGround[0] += 500.0f / 110.0f;

		}
		if (XValueGround[1] >= (630.0f + 130.0f)) {

			XValueGround[1] = 130.0f;

		}
		else {
			XValueGround[1] += 500.0f / 100.0f;
		}

		surface[0].MoveIt(XValueGround[0], 300);
		surface[1].MoveIt(XValueGround[1], 300);

	}



	void MoveWindowLeft(float* XValueGround) {

		if (KeyDetector[1] % 2 == 0) {

			this->mario->MoveBackword();

		}


		for (int i = 0; i < 10; i++) this->enemies[i].MoveIt(10.0f, 0.0f);

		if (XValueGround[0] > 130.0f) {
			XValueGround[0] -= 130.0f / 32.5f;
		}
		else {
			XValueGround[0] = 630.0f + 130.0f;
		}
		if (XValueGround[1] > (130.0f)) {
			XValueGround[1] -= 130.0f / 37.5f;
		}
		else {
			XValueGround[1] = 630.0f + 130.0f;
		}
		surface[0].MoveIt(XValueGround[0], 300);
		surface[1].MoveIt(XValueGround[1], 300);

	}


	void MoveWindowRightSpecialWay(float* XValueGround, int val) {

		if (val == 1) {

			if (KeyDetector[0] % 2 == 0)mario->MoveFront();


			surface[0].sprite.setTextureRect(sf::IntRect(130, 300, 200, 180));
			surface[1].sprite.setTextureRect(sf::IntRect(130, 300, 200, 180));

			//surface[1].sprite.setPosition(sf::Vector2f(600.0f, 150.0f));

			if (surface[0].sprite.getPosition().x > -180)
				surface[0].sprite.move(sf::Vector2f(-10.0f, 0.0f));
			else surface[0].sprite.setPosition(sf::Vector2f(400.0f, 150.0f));

			if (surface[1].sprite.getPosition().x > -220) {
				surface[1].sprite.move(sf::Vector2f(-10.0f, 0.0f));
			}
			else surface[1].sprite.setPosition(sf::Vector2f(600.0f, 150.0f));

		}
	}



	void MoveWindowLeftSpecial(float* XValueGround, int val) {

		if (val == 1) {

			if (KeyDetector[0] % 2 == 0)mario->MoveBackword();


			if (surface[0].sprite.getPosition().x < this->GameWindow->getSize().x) {
				surface[0].sprite.move(sf::Vector2f(+10.0f, 0.0f));
			}
			else surface[0].sprite.setPosition(sf::Vector2f(-100.0f, 150.0f));

			if (surface[1].sprite.getPosition().x < this->GameWindow->getSize().x) {
				surface[1].sprite.move(sf::Vector2f(+10.0f, 0.0f));
			}
			else surface[1].sprite.setPosition(sf::Vector2f(-500.0f, 150.0f));


			
		}
	}




	void DrawAllOnWindow() {	

		stringstream ss,ss1;
		ss<<"Score : ";
		ss << mario->score;

		scoreValue.setString(ss.str());

		ss1 << "Lifes : ";
		ss1 << mario->lifes;

		lifeValue.setString(ss1.str());

	this->GameWindow->clear();
	this->GameWindow->draw(this->BackGround[0]);
	this->GameWindow->draw(this->BackGround[1]);
	this->GameWindow->draw(this->scoreValue);
	this->GameWindow->draw(this->lifeValue);

	if (surface[0].ShouldDraw()) {
		surface[0].draw(this->GameWindow);
	}

	this->GameWindow->draw(this->mario->Shape);

	if (mario->CheckItem(1)) {
		Hammer.move(sf::Vector2f(10.0f, 0.0f));
		this->GameWindow->draw(this->Hammer);
	}

	for (int i = 0; i < 10; i++) {
		if (enemies[i].ShouldDraw()) {
			enemies[i].draw(this->GameWindow);

		}
	}

	if (surface[1].ShouldDraw())surface[1].draw(this->GameWindow);

	this->GameWindow->display();

	for (int i = 0; i < 10; i++) enemies[i].MoveIt(-10.0f, 0.0f);

	CheckIntersections();

}



	void Update() {

		if (this->mario->lifes <= 0) GameHasOver();

		static float XValueGround[2] = { 130 };

		
		while (this->GameWindow->pollEvent(this->Eve)) {
			
			switch (Eve.type)
			{
			case sf::Event::Closed: GameWindow->close();
				break;
			case sf::Event::KeyPressed: 

				switch (Eve.key.code) {
				case sf::Keyboard::Escape:
					GameWindow->close();
					break;
				case sf::Keyboard::W:
					this->mario->Shape.move(sf::Vector2f(0.0f, -50.0f));
					break;
				case sf::Keyboard::S:
					if(mario->Shape.getPosition().y < this->GameWindow->getSize().y-200.0f)
						this->mario->Shape.move(sf::Vector2f(0.0f, 10.0f));
					break;

				case sf::Keyboard::D:

					KeyDetector[0]++;
					if(KeyDetector[1]>0)
					KeyDetector[1]--;

					if(KeyDetector[0]<200)
					MoveWindowRight(XValueGround);
					if (KeyDetector[0] >= 200) {
						MoveWindowRightSpecialWay(XValueGround, 1);
					}

					if (KeyDetector[1] == 0 && KeyDetector[0] % 10 == 0) mario->score++;

		    break;

				case sf::Keyboard::Space:

					Hammer.setPosition(mario->Shape.getPosition().x, mario->Shape.getPosition().y );
					mario->EnableItem(1);

				break;

				case sf::Keyboard::E:
					this->mario->JumpForward(this->GameWindow,XValueGround,KeyDetector,this->surface,*this);
					
					KeyDetector[0] += 5;

					if (KeyDetector[1] > 0)
						KeyDetector[1] -= 5;

					if (KeyDetector[1] < 0)KeyDetector[1] = 0;
					
					if (KeyDetector[1] == 0 ) mario->score++;


				break;
				

				case sf::Keyboard::Q:
					
					mario->MakeItMove(0, -50);

					if (KeyDetector[1] < 10)
					{

						if (KeyDetector[0] < 200)
							MoveWindowLeft(XValueGround);

						else MoveWindowLeftSpecial(XValueGround, 1);

						KeyDetector[1] += 5;

						if (KeyDetector[0] > 0)
							KeyDetector[0] -= 5;

						if (KeyDetector[0] < 0)KeyDetector[0] = 0;
					
					}

				break;

				case sf::Keyboard::A:

					if (KeyDetector[1] < 10) {

						KeyDetector[1]++;

						if (KeyDetector[0] > 0)
							KeyDetector[0]--;

						if (KeyDetector[0] < 50) {
							for (int i = 0; i < 2; i++) {
								surface[i].sprite.setPosition(sf::Vector2f(0.0f, 150.0f));
								surface[i].sprite.setTextureRect(sf::IntRect(XValueGround[i], 300, 500, 180));
								MoveWindowLeft(XValueGround);
							}
						}
						else MoveWindowLeftSpecial(XValueGround, 1);

					}

		break;


				default: this->mario->StandStraight();
				}

				
				break;

			}
			    
			
		}


		if ((mario->Shape.getPosition().y) >= (this->GameWindow->getSize().y)) {
			GameHasOver();
		}
		
		

		 if (mario->Shape.getPosition().y <= 0) {
			mario->Shape.setPosition(x, 0);
			}

		//if (mario->Shape.getPosition().y >= surface[0].getPosition('y') + 60.0f) mario->Shape.setPosition(sf::Vector2f(x, surface[0].getPosition('y') + 60.0f));

		for (int i = 0; i < 10; i++) {
			if (enemies[i].GetposX() <= 0) {
				enemies[i].SetPosition(4000.0f, 10.0f + rand() % 300);
				enemies[i].MakeDrawTrue();
			}
		}
		if (this->Hammer.getPosition().x > this->GameWindow->getSize().x)mario->DisableItem(1);
	
		
}

void CheckIntersections() {

		bool found = false;

	for (int i = 0; i < 10; i++) {

		if (this->mario->Shape.getGlobalBounds().intersects(enemies[i].fires.getGlobalBounds())) {
			
			if (!this->mario->CheckItem(2)) {
					found = true; 
					enemies[i].MoveIt(-10.0f, 0.0f);
			}
		}


		
		else if (this->Hammer.getGlobalBounds().intersects(enemies[i].fires.getGlobalBounds())) {

			enemies[i].FalseDraw();
			enemies[i].MoveIt(0.0f, -500.0f);

		}

		if (this->mario->CheckItem(2) && (this->mario->Shape.getGlobalBounds().intersects(enemies[i].fires.getGlobalBounds())))
		{
			enemies[i].FalseDraw();
			enemies[i].MoveIt(0.0f, -500.0f);

			this->mario->DisableItem(2);
		}
	}

		if (found) mario->lifes-=enemies[0].gtDamage();


}
/*
void MoveBallsLeft() {

	for (int i = 0; i < 10; i++)
	{
		if (enemies[i].GetposX() > 0.0f) {
			enemies[i].MoveIt(-10.0f, 0.0f);
			cout << "Movinf left ";
		}
		else {
			enemies[i].SetPosition(8000.0f, 245.0f - rand() % 200);
			cout << "Setting position ";
		}
	}
}
*/

	void Render() {

		DrawAllOnWindow();

		CheckIntersections();
		

		if (surface[0].sprite.getGlobalBounds().contains(mario->Shape.getPosition()) || surface[1].sprite.getGlobalBounds().contains(mario->Shape.getPosition()))
		{
			if (mario->Shape.getPosition().y < this->GameWindow->getSize().y - 200.0f)
			{
				mario->MakeItMove(0, this->mario->Shape.getPosition().y / 20.0f );
			}
			else mario->Shape.setPosition(sf::Vector2f(x, this->GameWindow->getSize().y - 200.0f));
		}
		else {
			mario->MakeItMove(0, this->mario->Shape.getPosition().y / 20.0f);
		}

		/*
		if (KeyDetector[0] % 50 == 0) {
			int pos = 0;
			for (int i = 0; i < 10; i++) {
				if (enemies[i].GetposX() > 0.0f) pos++;
			}
			if (pos <= 0 )
				move = 100;
			else cout << "Invalid POS "<<pos<<" MOVE "<<move<<endl;
		}
		
		if (move > 0) {
			for (int i = 0; i < 10; i++) {
				enemies[i].MoveIt(-10.0f, 0.0f);
			}
			move--;
		}
		*/


	}



	void GameHasOver() {

		stringstream ss;


		ss << "Your Score : ";
		ss << mario->score;
	    
		scoreValue.setString(ss.str());
		scoreValue.setFillColor(sf::Color::White);
		scoreValue.setPosition(sf::Vector2f(GameOver.getPosition().x + 150.0f, GameOver.getPosition().y - 50.0f));

		this->GameWindow->clear();
		this->GameWindow->draw(scoreValue);
		this->GameWindow->draw(GameOver);
		this->GameWindow->display();
		sf::sleep(sf::seconds(3.0f));
		this->GameWindow->close();
		return;

	}

	~Game() {
		delete[] enemies;
		delete this->GameWindow;
		delete mario;
	}
};


void Ninja::JumpForward(sf::RenderWindow* window, float* XValueGround, int* KeyDetector, Surfaces* surface, Game& game){

	while (this->Shape.getPosition().y > 130.0f) {

		this->Shape.move(sf::Vector2f(0.0f, -3.0f));
		MoveFront();

		
		if (KeyDetector[0] < 200)
		{
			if (KeyDetector[0] % 2 == 0)
				MoveFront();

			if (XValueGround[0] >= (500.0f + 130.0f)) {

				XValueGround[0] = 130.0f;

			}
			else {

				XValueGround[0] += 500.0f / 110.0f;

			}
			if (XValueGround[1] >= (630.0f + 130.0f)) {

				XValueGround[1] = 130.0f;

			}
			else {
				XValueGround[1] += 500.0f / 100.0f;
			}

			surface[0].MoveIt(XValueGround[0], 300);
			surface[1].MoveIt(XValueGround[1], 300);



		}
		else {

			if (KeyDetector[0] % 2 == 0)MoveFront();

			surface[0].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));
			surface[1].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));

			//surface[1].sprite.setPosition(sf::Vector2f(600.0f, 150.0f));

			if (surface[0].getSprite().getPosition().x > -180)
				surface[0].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			else surface[0].getSprite().setPosition(sf::Vector2f(400.0f, 150.0f));

			if (surface[1].getSprite().getPosition().x > -220) {
				surface[1].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			}
			else surface[1].getSprite().setPosition(sf::Vector2f(600.0f, 150.0f));

		}
		
		game.DrawAllOnWindow();
		
	}

	while (this->Shape.getPosition().y < window->getSize().y - 200.0f) {

		this->Shape.move(sf::Vector2f(0.0f, 3.0f));
		MoveFront();

		if (KeyDetector[0] < 200)
		{
			if (KeyDetector[0] % 2 == 0)
				MoveFront();

			if (XValueGround[0] >= (500.0f + 130.0f)) {

				XValueGround[0] = 130.0f;

			}
			else {

				XValueGround[0] += 500.0f / 110.0f;

			}
			if (XValueGround[1] >= (630.0f + 130.0f)) {

				XValueGround[1] = 130.0f;

			}
			else {
				XValueGround[1] += 500.0f / 100.0f;
			}

			surface[0].MoveIt(XValueGround[0], 300);
			surface[1].MoveIt(XValueGround[1], 300);



		}
		else {

			if (KeyDetector[0] % 2 == 0)MoveFront();

			surface[0].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));
			surface[1].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));

			//surface[1].sprite.setPosition(sf::Vector2f(600.0f, 150.0f));

			if (surface[0].getSprite().getPosition().x > -180)
				surface[0].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			else surface[0].getSprite().setPosition(sf::Vector2f(400.0f, 150.0f));

			if (surface[1].getSprite().getPosition().x > -220) {
				surface[1].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			}
			else surface[1].getSprite().setPosition(sf::Vector2f(600.0f, 150.0f));

		}

		game.DrawAllOnWindow();
	}


}

void Mario::JumpForward(sf::RenderWindow* window, float* XValueGround, int* KeyDetector, Surfaces* surface, Game& game) {

	while (this->Shape.getPosition().y > 150.0f) {

		this->Shape.move(sf::Vector2f(0.0f, -5.0f));

		if (KeyDetector[0] < 200)
		{
			if (KeyDetector[0] % 2 == 0)
				MoveFront();

			if (XValueGround[0] >= (500.0f + 130.0f)) {

				XValueGround[0] = 130.0f;

			}
			else {

				XValueGround[0] += 500.0f / 110.0f;

			}
			if (XValueGround[1] >= (630.0f + 130.0f)) {

				XValueGround[1] = 130.0f;

			}
			else {
				XValueGround[1] += 500.0f / 100.0f;
			}

			surface[0].MoveIt(XValueGround[0], 300);
			surface[1].MoveIt(XValueGround[1], 300);



		}
		else {

			if (KeyDetector[0] % 2 == 0)MoveFront();

			surface[0].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));
			surface[1].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));

			//surface[1].sprite.setPosition(sf::Vector2f(600.0f, 150.0f));

			if (surface[0].getSprite().getPosition().x > -180)
				surface[0].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			else surface[0].getSprite().setPosition(sf::Vector2f(400.0f, 150.0f));

			if (surface[1].getSprite().getPosition().x > -220) {
				surface[1].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			}
			else surface[1].getSprite().setPosition(sf::Vector2f(600.0f, 150.0f));


		}

		game.DrawAllOnWindow();
	}


	while (this->Shape.getPosition().y < window->getSize().y - 200.0f) {

		this->Shape.move(sf::Vector2f(0.0f, 3.0f));
		MoveFront();

		if (KeyDetector[0] < 200)
		{
			if (KeyDetector[0] % 2 == 0)
				MoveFront();

			if (XValueGround[0] >= (500.0f + 130.0f)) {

				XValueGround[0] = 130.0f;

			}
			else {

				XValueGround[0] += 500.0f / 110.0f;

			}
			if (XValueGround[1] >= (630.0f + 130.0f)) {

				XValueGround[1] = 130.0f;

			}
			else {
				XValueGround[1] += 500.0f / 100.0f;
			}

			surface[0].MoveIt(XValueGround[0], 300);
			surface[1].MoveIt(XValueGround[1], 300);



		}
		else {

			if (KeyDetector[0] % 2 == 0)MoveFront();

			surface[0].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));
			surface[1].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));

			//surface[1].sprite.setPosition(sf::Vector2f(600.0f, 150.0f));

			if (surface[0].getSprite().getPosition().x > -180)
				surface[0].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			else surface[0].getSprite().setPosition(sf::Vector2f(400.0f, 150.0f));

			if (surface[1].getSprite().getPosition().x > -220) {
				surface[1].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			}
			else surface[1].getSprite().setPosition(sf::Vector2f(600.0f, 150.0f));

		}

		game.DrawAllOnWindow();
	}


}

void ArmedMario:: JumpForward(sf::RenderWindow* window, float* XValueGround, int* KeyDetector, Surfaces* surface, Game& game) {

	xValue = 100;
	this->EnableItem(2);

	this->Shape.setTextureRect(sf::IntRect(xValue, 730, 110, 860 - 730));

	while (this->Shape.getPosition().y > 100.0f) {

		this->Shape.move(sf::Vector2f(0.0f, -2.0f));

		if (KeyDetector[0] < 200)
		{
			if ((int)(Shape.getPosition().y) % 50 == 0)
			{
				if (xValue < 440)
					xValue += 110;
				else xValue = 100;

				this->Shape.setTextureRect(sf::IntRect(xValue, 730, 110, 860-730));

			}

			if (XValueGround[0] >= (500.0f + 130.0f)) {

				XValueGround[0] = 130.0f;

			}
			else {

				XValueGround[0] += 500.0f / 110.0f;

			}
			if (XValueGround[1] >= (630.0f + 130.0f)) {

				XValueGround[1] = 130.0f;

			}
			else {
				XValueGround[1] += 500.0f / 100.0f;
			}

			surface[0].MoveIt(XValueGround[0], 300);
			surface[1].MoveIt(XValueGround[1], 300);

			
		}
		else {

			if ((int)(Shape.getPosition().y) % 50 == 0)
			{
				if (xValue < 440)
					xValue += 110;
				else xValue = 100;

				this->Shape.setTextureRect(sf::IntRect(xValue, 730, 110, 860 - 730));

			}

			surface[0].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));
			surface[1].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));

			//surface[1].sprite.setPosition(sf::Vector2f(600.0f, 150.0f));

			if (surface[0].getSprite().getPosition().x > -180)
				surface[0].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			else surface[0].getSprite().setPosition(sf::Vector2f(400.0f, 150.0f));

			if (surface[1].getSprite().getPosition().x > -220) {
				surface[1].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			}
			else surface[1].getSprite().setPosition(sf::Vector2f(600.0f, 150.0f));


		}

		game.DrawAllOnWindow();

	}

	while (this->Shape.getPosition().y < window->getSize().y - 200.0f) {

		this->Shape.move(sf::Vector2f(0.0f, 3.0f));
		MoveFront();

		if (KeyDetector[0] < 200)
		{
			if (KeyDetector[0] % 2 == 0)
				MoveFront();

			if (XValueGround[0] >= (500.0f + 130.0f)) {

				XValueGround[0] = 130.0f;

			}
			else {

				XValueGround[0] += 500.0f / 110.0f;

			}
			if (XValueGround[1] >= (630.0f + 130.0f)) {

				XValueGround[1] = 130.0f;

			}
			else {
				XValueGround[1] += 500.0f / 100.0f;
			}

			surface[0].MoveIt(XValueGround[0], 300);
			surface[1].MoveIt(XValueGround[1], 300);



		}
		else {

			if (KeyDetector[0] % 2 == 0)MoveFront();

			surface[0].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));
			surface[1].getSprite().setTextureRect(sf::IntRect(130, 300, 200, 180));

			//surface[1].sprite.setPosition(sf::Vector2f(600.0f, 150.0f));

			if (surface[0].getSprite().getPosition().x > -180)
				surface[0].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			else surface[0].getSprite().setPosition(sf::Vector2f(400.0f, 150.0f));

			if (surface[1].getSprite().getPosition().x > -220) {
				surface[1].getSprite().move(sf::Vector2f(-10.0f, 0.0f));
			}
			else surface[1].getSprite().setPosition(sf::Vector2f(600.0f, 150.0f));

		}

		game.DrawAllOnWindow();
	}


}


void MakeItLogin();
void MakeItSignup();
void LetItPlay(const User&);

void Engine::simulate() {

	Game obj;

	system("cls");
	cout << "\n\n\t\t----------------Greetings in the VERTEX portal---------------------\n\n";

	int n;
	cout << "Please select the number against the desired operation PRECISELY\n\n 1 -> Login (If have a user account)\n 2 -> Sign up (If you donst have account)\n 3 ->Play Demo\n 4 -> Exit portal !\n\nEnter your choice (1,2,3,4) : ";
	cin >> n;


	switch (n) {

	case 1:
		MakeItLogin();
	break;

	case 2:
		MakeItSignup();
	break;

	case 3:

		obj.playIT();

		while(obj.IsWindowOpen()){

			obj.Update();
			obj.Render();

		}

	break;


	case 4: exit(0);  break;

	default:
		
		cout << "Kindly be precised ! \n";
		system("pause");

	}

}



void MakeItLogin() {

	int n = 0;
	User temp;
	char temparr[2][30];

	system("cls");


	cout << "\n -->> Welcome to the login panel\n\n Enter your login Identity : ";

	fflush(stdin);
	fflush(stdin);
	fgets(blank, 30, stdin);
	fgets(temparr[0], 30, stdin);
	temp.setLoginID(temparr[0]);
	fflush(stdin);

	while(!checkUser(temp,n)){
	
		cout << "\t\t****The user name does not found !****\n\nPlease provide the user name / Login ID again\n Press any Key to continue or enter E to exit !\n";

		char ch;
		fflush(stdin);
		cin >> ch;

		if ( ch == 'E')exit(0);

		fflush(stdin);
		fflush(stdin);
		fgets(blank, 30, stdin);

		cout << "Enter a unique user name : ";

		fgets(temparr[0], 30, stdin);
		temp.setLoginID(temparr[0]);
		fflush(stdin);
	
	}

	cout << " Enter Your password : ";
	
	fflush(stdin);
	fgets(temparr[1], 30, stdin);
	fflush(stdin);
	temp.setPass(temparr[1]);

	int count = 3;
	
	while (!Engine::Login(temp, n) && count>0) {

		cout << "\n\t**** Incorrect password ! ****\n\nPress any key to continue, or press 'E' to exit\n";

		if (getc(stdin) == 'E')
			exit(0);

		cout << "Enter the password again ("<<count<<"): ";

		fflush(stdin);
		fgets(blank, 30, stdin);
		fgets(temparr[1], 30, stdin);
		fflush(stdin);
		temp.setPass(temparr[1]);

		count--;

	}

	if (count <= 0) { 

		cout << "\n\nYou failed to login successfully !\n";
		return;

	}
	else cout << "\n\n\t\t *** Login successful ! ***\n\n\t";

	system("pause");
	return LetItPlay(temp);

	//Now play the game
 
}



void MakeItSignup() {

	int num= 0;

	system("cls");

	User newUser;

	char temps[3][30];

	cout << "\n\n\t\t *** Welcome to the Signup portal !\n\n -> Please provide us information with which you want to signup\n -> keep remember this information to login anytime on vertex\n\n - Name : ";

	fflush(stdin);
    fgets(blank, 30, stdin);
    fgets(temps[0], 30, stdin);
	cout << " - Login ID : ";
    fgets(temps[1], 30, stdin);
	newUser.setLoginID(temps[1]);
	fflush(stdin);

	while (checkUser(newUser,num)) {

		cout << "The user already exist kindly enter a different login ID\nPress any key to continue or press ESC to exit ";
		if (getc(stdin) == 27)exit(0);

		fflush(stdin);
		fgets(temps[1], 30, stdin);
		newUser.setLoginID(temps[1]);
		fflush(stdin);

	}

	cout << " - Password : ";
	fflush(stdin);
    fgets(temps[2], 30, stdin);
	fflush(stdin);
	
	newUser = User((char*)temps[0],(char*) temps[2],(char*) temps[1]);

	if (Engine::SignUp(newUser)) {
		cout << "\n\n\t\t *** Signup successful **\n\n";
		system("pause");
		return LetItPlay(newUser);
	}
	else cout << "An error occured while signing up !\n\n";


}


void UpdateAccount(const User& obj) {

	User temp=obj;
    char temparr[30];

	system("cls");
	cout << "\n --)) What do you want to update \n\n 1 = Name\n 2 = LoginID\n 3 = Password\n\nEnter your choice : ";

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1 : 
		fgets(blank,30, stdin);
		cout << "Enter the new name : ";
		fgets(temparr,30, stdin);
		temp.setName((char*)temparr);
	break;

	case 2:

		fgets(blank, 30, stdin);
		cout << "Enter the new Login ID : ";
		fgets(temparr, 30, stdin);
		temp.setLoginID((char*)temparr);
	break;

	case 3 :

		fgets(blank, 30, stdin);
		cout << "Enter the new Password : ";
		fgets(temparr, 30, stdin);
		temp.setPass((char*)temparr);

	break;

	default:cout << "Not a valid Entry !\n";
		system("pause");
		break;
	}

	if (Engine::UpdateUser(obj, temp))cout << "\n\n\t\t ****** User Updated Successfully ****** \n\n\n -->> Kindly reload the account to observe the changes ! \n";
	else cout << "\n -- An error occured ! \n";
	system("pause");
}


void LetItPlay(const User& obj) {

	while (1) {

		Game game;
		system("cls");
		cout << "\n\n\t\t ****** Greetings to the panel of vertex ! " << obj.getName() << endl << endl;
		cout << " -->> Please select precisely ! :\n 1- Play Game\n 2- Update Account\n 3- Delete Account\n 4- exit\n\n\nEnter your choice : ";

		int choice;
		cin >> choice;
		switch (choice) {

		case 1:

			game.playIT();

			while (game.IsWindowOpen()) {

				game.Update();
				game.Render();

			}

			break;

		case 2:
			UpdateAccount(obj);
		break;

		case 3:

			if (Engine::deleteUser(obj)) {

				system("cls");
				cout << "\n\n\t\t *** Thanks for your valuable time ***\n\nVertex admires your time , and hope you soon come back ! ";
				system("pause");

				return;

			}
		
		break;

		
		case 4:
			exit(0);
		break;

		default:
			cout << "\n\n Kindly be precised ! ";
			system("pause");
		
		}
	
	}

}


class Admin {
public:
	Admin(){}
	static void simulate();

 };

void ShowAllUsers() {

	fstream file("UserData.bin", ios::binary | ios::in);

	User temp;
	int n = 1;

	while ( file.read((char*)&temp , sizeof(User))) {

		cout << "\n -> User Number : " << n << endl;

		temp.displayValues();

		n++;

	}

	if (n == 1)cout << "\n\nNo User found !\n";

	file.close();

}

void DeleteUser() {

	system("cls");

	char temp[30];

	fflush(stdin);
	fgets(blank, 30, stdin);
	cout << "\nEnter the login Id Of the user you want to delete : ";
	fgets(temp, 30, stdin);
	int n = 0;
    
	User tempUser;

	tempUser.setLoginID(temp);

	if (checkUser(tempUser, n)) {

		fstream file("UserData.bin", ios::binary | ios::in);

		file.seekg((n - 1) * sizeof(User));
		file.read((char*)&tempUser, sizeof(User));
		file.close();



		if (Engine::deleteUser(tempUser))

			cout << "\n\n\t\t ** User Deleted successfully ! **\n";
		else cout << "\n\n\t\tAn Error Occured ! \n";

	}
	else cout << "\nThe User does not exist ! ";
	

		system("pause");

}


void Admin::simulate() {

	cout << "\n\nEnter the password : ";

	string temp;

	cin.clear();
	cin >> temp;

	if (!temp.compare("Admin123") == 0) {

		cout << "\nPassword not found !\n";
		return;

	}
	else cout << "\nAdmin portal successfully opened ! ";

	system("pause");

	cin.clear();
	

	while (1) {

	system("cls");

		cout << "\n\nWhat do you want to perform \n\n1 - See All users\n 2 - Delete A User\n3 - Exit\n\nEnter  your choice : ";

		int choice;
		cin >> choice;

		switch (choice)
		{

		case 1: ShowAllUsers(); break;
		case 2: DeleteUser(); break;
		case 3: exit(0); break;

		default: cout << "\nInvalid Entry ! \n";
			break;

		}

		system("pause");

	}

}

int main() {

	cout << "Are you an admin or User ?\n\n 1- Admin\n 2- User\n\nEnter your choice : ";

	int choice;
	cin >> choice;

	switch (choice) {

	case 1: Admin::simulate(); break;
	case 2: Engine::simulate(); break;

	}

	return 0;

}
