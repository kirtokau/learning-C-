#include<iostream>
using namespace std;
//��̬����2
class AbstractDrinking
{
  public:
  	//��ˮ
	  virtual void Boil()=0;
	//����
	virtual void Brew()=0;
	//���뱭��
	virtual void PourInCup()=0;
	//���븨��
	virtual void PutSomething()=0;
	//������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
		
	 } 
	 
};
//��������
class Coffee:public AbstractDrinking
{
	public:
	 	//��ˮ
	  virtual void Boil()
	  {
	  	cout<<"��ũ��ɽȪ"<<endl; 
	  }
	//����
	virtual void Brew()
	{
		cout<<"���ݿ���"<<endl; 
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout<<"���뱭��"<<endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout<<"�����Ǻ�ţ��"<<endl;
		}	
		
 };
 //������Ҷ 
class Tea:public AbstractDrinking  
{
 public:

	 	//��ˮ
	  virtual void Boil()
	  {
	  	cout<<"���Ȫˮ"<<endl; 
	  }
	//����
	virtual void Brew()
	{
		cout<<"���ݲ�Ҷ"<<endl; 
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout<<"���뱭��"<<endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout<<"�������"<<endl;
		}	
		
};
void dowork(AbstractDrinking *abs)//AbstractDrinking *abs=new Coffee 
{
	abs->makeDrink();
	delete abs;//�ͷ� 
}
test01()
{
	//��������
	dowork(new Coffee);
	
	cout<<"----------------------"<<endl;
	//������Ҷ
	dowork(new Tea);
	 

 } 
 int main()
 {
 	test01();
 }


 

