#include <iostream.h>
class Box{
	private:
		int a;
		int volume;
		int area;
	public:
	   	~Box(){}//�������� 
	   	Box(int r){a = r;volume = 0;area = 0;}//���� 
	   	int& seta(){return a;}
	   	void seta(int r){a = r;}
	   	void seta(int* r){a = *r;}//���� 
	   	void seta(int& r){a = r;}
	   	void getvolume(){volume = a*a*a;}
	   	void getarea(){area = 6*a*a;}
	   	void disp(){
	   		cout<<"�����"<<volume<<",�����: "<<area<<endl; 
	   	}
};

int main(){
	int r = 0; 
	Box obj1(r);
	obj1.seta() = 5;//��ֵ��ֵ 
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