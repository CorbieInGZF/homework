#include <iostream>
using namespace std;
class Date;//对Date类的提前引用声明
class Time{//定义Time类
	public:
   		Time(int,int,int);
   		friend void display(const Date &,const Time &);//声明Time中的display函数为友元成员函数
  	private:
   		int hour;
   		int minute;
   		int sec;
 };
 
Time::Time(int h,int m,int s){ //类Time的构造函数
	hour = h;
  	minute = m;
  	sec = s;
 }
 
class Date{
	public:
   		Date(int,int,int);
   		friend void display(const Date &,const Time &);
  	private:
   		int month;
   		int day;
   		int year;
 };
 
Date::Date(int m,int d,int y){ //类Date的构造函数
	month=m;
  	day=d;
  	year=y;
 }
 
void display(const Date &d,const Time &t){//display的作用是输出年，月，日和时，分，秒
  	cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
  	cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
 }
 
   
int main(){
 	Time t1(10,13,56);
 	Date d1(12,25,2004);
 	display(d1,t1);
 	return 0;
}