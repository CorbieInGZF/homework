#include <iostream>
using namespace std;
class Student{
	public:
	   	Student(int n,float s){
	   		num = n;
	   		score = s;
	   	}
	   	void change(int n,float s){
	   		num = n;score = s;
	   	}
	   	void display(){
	   		cout<<num<<" "<<score<<endl;
	   	}
	   	void fun(Student&s){
	   		s.change(101,80.5);
	   		s.display();
	   	}
	private:
	int num;
	float score;
};

int main(){
	Student stud(101,78.5);
	stud.display();
	stud.change(101,80.5);
	stud.display();
	stud.fun(stud);
	
	return 0;
}