#include<iostream>
using namespace std;
class MenuItem{
private:
    string name;
    int price;
    int many;
public:
    MenuItem();
    MenuItem(string,int,int);
    string getName()const;
    int getPrice()const;
    int getMany()const;
    int setMany(int);
};
class Order{
private:
    MenuItem Menu[10];
    static int count;
public:
    Order();
    void plusMenu();
    void printMenu();
    void order();
};
int main(){
    int n{0};
    Order order;
    cout<<"Welcome to the Restaurant Order Management System!\n";
    while(n!=4){
        cout<<"--------------------------------------------\n1. Add a new menu item\n2. View menu\n3. Place an order\n4. Exit\n--------------------------------------------\nEnter your choice: ";
        cin>>n;
        if(n==1){
            order.plusMenu();
        }else if(n==2){
            order.printMenu();
        }else if(n==3){
            order.order();
        }else{
            cout<<"\nExiting the program. Goodbye!";
        }
    }
    return 0;
}
MenuItem::MenuItem(){}
MenuItem::MenuItem(string name,int price,int many){
    this->name=name;
    this->price=price;
    this->many=many;
    cout<<"Menu item added successfully!\n";
}
string MenuItem::getName()const{return name;}
int MenuItem::getPrice()const{return price;}
int MenuItem::getMany()const{return many;}
int MenuItem::setMany(int num){
    many-=num;
}
int Order::count=0;
Order::Order(){}
void Order::plusMenu(){
    string s;
    int p,m;
    cout<<"Enter menu item name: ";
    cin>>s;
    cout<<"Enter price: ";
    cin>>p;
    cout<<"Enter stock quantity: ";
    cin>>m;
    Menu[count]=MenuItem(s,p,m);
    count++;
}
void Order::printMenu(){
    cout<<"\nListing all menu items:\n--------------------------------------------\n";
    for(int i=0;i<count;i++) {
        cout <<i+1<<". Name: "<<Menu[i].getName()<<", Price: "<<Menu[i].getPrice()<<", Stock: "<<Menu[i].getMany()<<endl;
    }
}
void Order::order(){
    string s;
    int number;
    cout<<"\nEnter menu item name: ";
    cin>>s;
    MenuItem* ptr=Menu;
    cout<<"Enter quantity: ";
    cin>>number;
    for(int i=0;i<count;i++,ptr++){
        if(ptr->getName()==s){//포인터 클래스로 배열 순회. 근데, 이제 하나씩 메뉴 이름이랑 비교해 나가는데,
            //같은 이름의 메뉴를 발견하면
            if(number<=ptr->getMany()){ //갯수 비교를 통해 주문이 가능한 지 그 여부를 판단.
                ptr->setMany(number);
                cout<<"Order placed successfully!\nRemaining stock for "<<ptr->getName()<<": "<<ptr->getMany()<<endl;
            }else{
                cout<<"Order failed! Not enough stock available.\n";
            }
            break;//break가 꼭 필요한 이유는? 괜히 뒤까지 순회하면서 쓸데없는 출력을 낳기 때문^^
        }else if(i==count-1&&ptr->getName()!=s){//순회하면서 마지막 순간에 이름이 같지 않으면
            cout<<"Order failed! Menu item not found.\n";
        }
    }
}
