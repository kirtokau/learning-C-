#include<iostream> 
using namespace std;
#include<string> 
//�������� 
class Building
{
	friend void goodGay(Building *building);//goodGayȫ�ֺ���Building�ĺ����ѣ����Է���Building��˽�г�Ա
public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
public:
	string m_SittingRoom;//����
private:
	string m_BedRoom;//���� 

};
//ȫ�ֺ���
void goodGay(Building *building)
{
	cout << "�û��ѵ�ȫ�ֺ������ڷ���:" << building->m_SittingRoom << endl;
	cout << "�û��ѵ�ȫ�ֺ������ڷ���:" << building->m_BedRoom << endl;
}
void test01()
{
	Building building;
	goodGay(&building);
}
int main()
{
	test01();
}
