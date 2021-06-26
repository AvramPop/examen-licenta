#include <iostream>
using namespace std;
class Vehicle{
 public:
 double speed;
 public:
 Vehicle(double ms){speed=ms;}
 Vehicle(const Vehicle& v) {cout << "copy constructor"; speed = v.speed;}
  Vehicle(){speed=0;}
 virtual void go(){cout<<"Vehicle going ..."<<endl;}
 void accelerate(){cout<<"Vehicle accelerating..."<<endl;}
};
class Scooter:public Vehicle{
 public:
 Scooter(double s){ speed=s;}
 void go(){cout<<"Scooter going ..."<<endl;}
 void accelerate(int s) {cout<<"Accelerating with "<<s<<"..."<<endl;}
};
int main(){
 Scooter* s = new Scooter(1);
 Vehicle& v = *s;
 s->speed = 3;
 cout << s->speed << endl;
 cout << v.speed << endl;
 v.go();
 v.accelerate();
 return 0;
}

// this will yield a compile time exception since Vehicle has no default constructor