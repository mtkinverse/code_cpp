#include<iostream>
#include<string>
using namespace std;

class Product{
 protected:
 int productID,quan;
 float price;
 string name,category,supplier;
 public:
 Product(){}   
 Product(int productID,int quan,float price,string name,string category,string supplier){
    this->productID=productID;
    this->quan=quan;
    this->price=price;
    this->name=name;
    this->category=category;
    this->supplier=supplier;
 }
 void addStock(int val){quan+=val;}   
};

class Category:protected Product{
    protected:
int categoryID;
string categoryName;
public:
   Category(){}
   Category(int categoryID,string categoryName,int productID,int quan,float price,string name,string category,string supplier):Product(productID,quan,price,name,category,supplier){
    this->categoryID=categoryID;
    this->categoryName=categoryName;
   }
   void addProduct(){Product::addStock(1);}

   Product getProduct(){
    //Since it is not composition or aggregation we don't have products or list of product
   Product temp(productID,quan,price,name,category,supplier);
   return temp;
    }

};

class Supplier:public Category{
    int suppID;
    string suppName;
    public:
    Supplier(int suppID,string suppName,int categoryID,string categoryName,int productID,int quan,float price,string name,string category,string supplier):Category(categoryID,categoryName,productID,quan,price,name,category,supplier){
        this->suppID=suppID;
        this->suppName=suppName;
    }
    Supplier(){}
    void addProduct(){
        Category::addProduct();
    }
    Product getProduct(){return Category::getProduct();}
};

int main(){
    Product* products;
    int productQuan=0;
    Category* categories;
    int categQuan=0;
    Supplier* suppliers;
    int suppQuan=0;

    while(1){
 int productID,quan;
 float price;
 string name,category,supplier;
 int categoryID;
string categoryName;
int suppID;
    string suppName;


        cout<<"Please select according to your desire\n1- to add products\n2- To add categories\n 3- To add new suppliers\n4- Increase the number of product \n5- Increase number of product in a category\n6- Increase Number if product for a supplier\n7- Exit\n\nEnter your choice : ";
        int choiceA;
        cin>>choiceA;
        switch(choiceA){
            case 1: 
            Product* temp1;
            temp1=new Product[productQuan];
            for(int i=0;i<productQuan;i++)temp1[i]=products[i];
            products=new Product[++productQuan];
            for(int i=0;i<productQuan-1;i++)products[i]=temp1[i];
            cout<<"Give the information of the product\nID : ";
            cin>>productID;
            cout<<"Name : ";
            cin.clear();
            getline(cin,name);
            cin.clear();
            cout<<"Category : ";
            cin.clear();
            getline(cin,category);
            cin.clear();
            cout<<"Supplier : ";
            cin.clear();
            getline(cin,supplier);
            cin.clear();
            cout<<"Quantity : ";
            cin>>quan;
            cout<<"Price : ";
            cin>>price;
            products[productQuan-1]=Product ( productID,quan,price,name,category,supplier);
            delete[] temp1;

            break;
            
            case 2:
            Category* temp2;
            temp2 = new Category[categQuan];
            for(int i=0;i<categQuan;i++)temp2[i]=categories[i];
            categories=new Category[++categQuan];
            for(int i=0;i<categQuan-1;i++)categories[i]=temp2[i];
            cout<<"Enter the information of the category\nCategory ID : ";
            cin>>categoryID;
            cout<<"Category Name : ";
            cin.clear();
            getline(cin,categoryName);
            cin.clear();
            cout<<"Give the information of the product\nID : ";
            cin>>productID;
            cout<<"Name : ";
            cin.clear();
            getline(cin,name);
            cin.clear();
            cout<<"Category : ";
            cin.clear();
            getline(cin,category);
            cin.clear();
            cout<<"Supplier : ";
            cin.clear();
            getline(cin,supplier);
            cin.clear();
            cout<<"Quantity : ";
            cin>>quan;
            cout<<"Price : ";
            cin>>price;
            categories[categQuan-1]=Category( categoryID, categoryName, productID, quan, price, name, category, supplier);
            delete[] temp2;
            
            
            break;
            case 3: 
            Supplier* temp3;
            temp3=new Supplier[suppQuan];
            for(int i=0;i<suppQuan;i++)temp3[i]=suppliers[i];
            suppliers=new Supplier[++suppQuan];
            for(int i=0;i<suppQuan-1;i++){
                suppliers[i]=temp3[i];
            }
            cout<<"Enter the information about the supplier\nID : ";
            cin>>suppID;
            cout<<"Name : ";
            cin.clear();
            getline(cin,suppName);
            cin.clear();
            cout<<"Enter the information of the category\nCategory ID : ";
            cin>>categoryID;
            cout<<"Category Name : ";
            cin.clear();
            getline(cin,categoryName);
            cin.clear();
            cout<<"Give the information of the product\nID : ";
            cin>>productID;
            cout<<"Name : ";
            cin.clear();
            getline(cin,name);
            cin.clear();
            cout<<"Category : ";
            cin.clear();
            getline(cin,category);
            cin.clear();
            cout<<"Supplier : ";
            cin.clear();
            getline(cin,supplier);
            cin.clear();
            cout<<"Quantity : ";
            cin>>quan;
            cout<<"Price : ";
            cin>>price;
            suppliers[suppQuan-1]=Supplier( suppID, suppName, categoryID, categoryName, productID, quan, price, name, category, supplier);
            delete[] temp3;
            break;

            case  4: 
            cout<<"Enter the number of product you want to increase : ";
            cin>>choiceA;
            if(choiceA<productQuan)
            products[choiceA].addStock(1);
            else cout<<"Error !\n";
            break;
            case 5: 
            cout<<"Enter the number of category,whose product you want to increase :";
            cin>>choiceA;
            if(choiceA<categQuan)
            categories[choiceA].addProduct();
            else cout<<"Error !\n";
            break;
            case 6:
            
            cout<<"Enter the number of supplier whom product you want to increase :";
            cin>>choiceA;
            if(choiceA<suppQuan)
            suppliers[choiceA].addProduct();
            else cout<<"Error !\n";
            break;
            case 7:
             exit(0);
            break;
            default: cout<<"Invalid Entry!\n";
            
        }
    }
    return 0;
}