#include <iostream>
using namespace std;
class Date;//��Date�����ǰ��������
class Time{//����Time��
	public:
   		Time(int,int,int);
   		friend void display(const Date &,const Time &);//����Time�е�display����Ϊ��Ԫ��Ա����
  	private:
   		int hour;
   		int minute;
   		int sec;
 };
 
Time::Time(int h,int m,int s){ //��Time�Ĺ��캯��
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
 
Date::Date(int m,int d,int y){ //��Date�Ĺ��캯��
	month=m;
  	day=d;
  	year=y;
 }
 
void display(const Date &d,const Time &t){//display������������꣬�£��պ�ʱ���֣���
  	cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
  	cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
 }
 
   
int main(){
 	Time t1(10,13,56);
 	Date d1(12,25,2004);
 	display(d1,t1);
 	return 0;
}