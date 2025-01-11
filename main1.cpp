//1번
//문제를 풀 때 발견한
//문제점 1 : 클래스 내 스태틱 함수를 사용할 때, 객체를 통해 접근하려고 함(L.counter();)
//하지만 스태틱 함수는 모든 객체가 공유하는 즉, 클래스 당 하나를 공유하고 있는 것이기 때문에, 객체로 접근하는 것이 아닌
//클래스로 접근해야한다. (Library::counter();)
#include<iostream>
using namespace std;
class Book{
private:
    string title,name;
    int price;
public:
    Book();
    Book(string,string,int);
    string getName()const;
    string getTitle()const;
    void info();
};
class Library{
private:
    Book book[10];
    static int count;
public:
    Library();
    static void counter();
    void plus(); //1번
    void bookInfo(); //2번
    void research(); //3번

};
int main(){
    int k{0};
    Library L;
    cout<<"Welcome to the Library Management System!";
    while(k!=4){
        cout<<"\n-----------------------------------------\n1. Add a new book\n2. View all books\n3. Search books by author\n4. Exit\n-----------------------------------------\nEnter your chice: ";
        cin>>k;
        if(k==1){
            Library::counter();
            L.plus();
        }else if(k==2){
            cout<<"\nListing all books in the library:\n-----------------------------------------\n";
            L.bookInfo();
        }else if(k==3){
            L.research();
        }else{
            cout<<"\nExiting the program. Goodbye!";
        }
    }
    return 0;
}
Book::Book(){}
Book::Book(string title,string name,int price){
    this->title=title;
    this->name=name;
    this->price=price;
    cout<<"\nBook added succeddfully!\n";
}
string Book::getTitle()const{return title;}
string Book::getName()const{return name;}
void Book::info(){
    cout<<". Title: "<<title<<", Author: "<<name<<", Price: "<<price<<endl;
}
int Library::count=0;
void Library::counter(){count++;}
Library::Library(){}
void Library::plus(){
    string s,n;
    int m;
    cout<<"\nEnter book title: ";
    cin>>s;
    cout<<"Enter author: ";
    cin>>n;
    cout<<"Enter price: ";
    cin>>m;
    book[count]=Book(s,n,m);
}
void Library::bookInfo(){
    for(int i=1;i<=count;i++){
        cout<<i;
        book[i].info();
    }
}
void Library::research(){
    string k;
    int index;
    int num{0};
    cout<<"\nEnter author name to search: ";
    cin>>k;
    cout<<"Books by "<<k<<":\n-----------------------------------------\n";
    for(int i=1;i<=count;i++){
        if(k==book[i].getName()){
            num++;
            cout<<num;
            book[i].info();
        }
    }
}