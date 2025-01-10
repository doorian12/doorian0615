//Theme. 클래스와 배열
//조건1: 고정배열을 이용할 것.(100이하의 입력 가정)
//조건2: printRectangles 는 전역함수. 매개변수로 배열을 받을 것.
//조건3: 모든 클래스 변수는 private, const를 적절히 사용할 것.
#include<iostream>
using namespace std;
class Rectangle{
private:
    int garo,sero;
    static int count;
public:
    Rectangle();
    Rectangle(int,int);
    static int getCount();//static 멤버함수에 const 붙일 수 없음(this 포인터가 없으므로?)
    int getG()const;
    int getS()const;
};
void printRectangles(Rectangle[]);
int main(){
    const int max=100;
    int g,s;
    Rectangle arr[max];
    cout<<"사각형을 가로와 세로를 입력하세요 (종료: 0)"<<endl;
    while(Rectangle::getCount()<max) {
        cin >> g;
        if (g == 0) {
            break;
        }
        cin >> s;
        if (s == 0) {
            break;
        }
        arr[Rectangle::getCount()-1]=Rectangle(g,s); //등호 오른쪽이 먼저 생성되기 때문에 count++가 먼저 일어남 주의**
    }
    printRectangles(arr);

    return 0;
}
int Rectangle::count=0;
Rectangle::Rectangle(){}
int Rectangle::getCount(){return count;}
Rectangle::Rectangle(int a,int b):garo(0),sero(0){//입력 이후에 쓰레기 값이 들어갈 것을 고려하여 0으로 초기화
    garo=a;
    sero=b;
    count++;}
int Rectangle::getG()const{return garo;}
int Rectangle::getS()const{return sero;}
void printRectangles(Rectangle k[]){//const는 클래스 멤버함수에 붙이는 게 좋다.
    cout<<"사각형의 총 개수: "<<Rectangle::getCount()<<endl;
    for(int i=0;i<Rectangle::getCount();i++) {
        cout << "사각형 "<<i+1<<": 가로="<<k[i].getG()<<", 세로="
             <<k[i].getS()<<", 면적="<<k[i].getG()*k[i].getS()<<", 둘레="
             <<2*(k[i].getS()+k[i].getG())<<endl;
    }
}