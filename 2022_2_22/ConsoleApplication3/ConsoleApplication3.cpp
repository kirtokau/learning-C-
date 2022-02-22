// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <Windows.h>
#include <mysql.h>
#include <iostream>
#include <iomanip>

using namespace std;

void mysql_test();   //进入学生系统
void mysql_insert(); //新增学生信息
void mysql_display();//查看学生信息
void mysql_delete(); //删除学生信息
void mysql_modify(); //修改学生信息

MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;

int main()
{
	while (1)
	{
		cout << "**********1.进入学生系统**********" << endl;
		cout << "**********2.新增学生信息**********" << endl;
		cout << "**********3.查看学生信息**********" << endl;
		cout << "**********4.删除学生信息**********" << endl;
		cout << "**********5.修改学生信息**********" << endl;
		cout << "**********6.退出******************" << endl;
		int commond;
		cout << "请输入命令：";
		cin >> commond;
		switch (commond)
		{
		case 1:
		{
			system("cls"); mysql_test();    break;
		}
		case 2:
		{
			system("cls"); mysql_insert();  break;
		}
		case 3:
		{
			system("cls"); mysql_display(); break;
		}
		case 4:
		{
			system("cls"); mysql_delete();  break;
		}
		case 5:
		{
			system("cls"); mysql_modify();  break;
		}
		case 6:
		{
			mysql_close(&mysql); return 0;
		}
		default:
			cout << "请输入正确的指令\n";
		}
	}
	return 0;
}
/**********进入学生系统**********/
void mysql_test()
{
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "admin", "student", 3306, NULL, 0))
		cout << "进入失败，请稍后再试" << endl;
	else
		cout << "*******欢迎来到教务管理系统*******" << endl;
}
/**********新增学生信息**********/
void mysql_insert()
{
	char sno[40];       //学号
	char name[40];      //姓名
	char age[40];       //年龄
	char major[40];     //专业
	char sqlstr[1024];  //缓冲区
	cout << "请依次输入学生学号、姓名、年龄、专业，并用空格隔开：" << endl;
	cin >> sno >> name >> age >> major;

	int len = sprintf_s(sqlstr, "INSERT INTO ccc (sno,name,age,major)\
							  VALUES('%s','%s','%s','%s');", sno, name, age, major);
	mysql_query(&mysql, sqlstr);

	if (len < 0)
		cout << "新增数据失败\n";
	else
		cout << "新增数据成功\n";
}
/**********查看学生信息**********/
void mysql_display()
{
	mysql_query(&mysql, "select * from ccc");
	res = mysql_store_result(&mysql);
	printf("sno\t\tname\tage\tmajor\n");
	while (row = mysql_fetch_row(res))
	{
		cout << left << setw(16) << row[0];
		cout << left << setw(8) << row[1];
		cout << left << setw(8) << row[2];
		cout << left << setw(16) << row[3];
		cout << endl;
	}
	mysql_free_result(res);
}
/**********删除学生信息**********/
void mysql_delete()
{
	char str[40];
	char sqlstr[1024];

	cout << "输入要删除的学生学号：";
	cin >> str;
	int len = sprintf_s(sqlstr, "delete from ccc where sno=%s", str);
	mysql_query(&mysql, sqlstr);

	if (len < 0)
		cout << "删除数据失败\n";
	else
		cout << "删除数据成功\n";
}
/**********修改学生信息**********/
void mysql_modify()
{
	int commond;
	char str[40];
	char str1[40];
	char sqlstr[1024];

	cout << "输入要修改的学生学号：";
	cin >> str;
	cout << "要修改的内容：1（姓名），2（年龄），3（专业），4(退出）:";
	cin >> commond;
	switch (commond)
	{
	case 1:
	{
		cout << "请输入新的姓名：";
		cin >> str1;
		int len = sprintf_s(sqlstr, "update ccc set name='%s' where sno=%s", str1, str);
		mysql_query(&mysql, sqlstr);
		if (len < 0)
			cout << "修改数据失败\n";
		else
			cout << "修改数据成功\n";
		break;
	}
	case 2:
	{
		cout << "请输入新的年龄：";
		cin >> str1;
		int len = sprintf_s(sqlstr, "update ccc set age='%s' where sno=%s", str1, str);
		mysql_query(&mysql, sqlstr);
		if (len < 0)
			cout << "修改数据失败\n";
		else
			cout << "修改数据成功\n";
		break;
	}
	case 3:
	{
		cout << "请输入新的专业：";
		cin >> str1;
		int len = sprintf_s(sqlstr, "update ccc set major='%s' where sno=%s", str1, str);
		mysql_query(&mysql, sqlstr);
		if (len < 0)
			cout << "修改数据失败\n";
		else
			cout << "修改数据成功\n";
		break;
	}
	case 4:
	{
		return;
	}
	default:
		cout << "请输入正确的指令";
	}
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
