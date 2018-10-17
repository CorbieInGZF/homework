#include <iostream.h>
class Box{
	private:
		int a;
		int volume;
		int area;
	public:
	   	~Box(){}//析构函数 
	   	Box(int r){a = r;volume = 0;area = 0;}//构造 
	   	int& seta(){return a;}
	   	void seta(int r){a = r;}
	   	void seta(int* r){a = *r;}//重载 
	   	void seta(int& r){a = r;}
	   	void getvolume(){volume = a*a*a;}
	   	void getarea(){area = 6*a*a;}
	   	void disp(){
	   		cout<<"体积："<<volume<<",表面积: "<<area<<endl; 
	   	}
};

int main(){
	int r = 0; 
	Box obj1(r);
	obj1.seta() = 5;//左值赋值 
	obj1.getvolume();
	obj1.getarea();
	cout<<"obj1 =>";
	obj1.disp();
	
	obj1.seta(10);
	obj1.getvolume();
	obj1.getarea();
	cout<<"obj1 =>";
	obj1.disp();
	
	return 0;
}