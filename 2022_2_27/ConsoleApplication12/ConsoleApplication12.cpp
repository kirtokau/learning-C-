#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Student
{
	char name[20];//姓名
	int age;//年龄
	int stuNum;//学号
	int score;//成绩
}Student;
//节点（车厢）
typedef struct _Node
{
	Student stu;//学生
	struct _Node* pNext;//指向下一节点的指针
}Node;
//头结点
Node *g_pHead = NULL;
void InputStudent();
//查找学生
Node* FindStudent();
//修改学生信息
void ModifyStudent();
//删除学生信息
void DeleteStudent();
int main()
{
	while (1)
	{
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:InputStudent(); break;
		case 2:DeleteStudent(); break;
		case 3: {
			Node* p = FindStudent();
			if (p != NULL)
			{
				printf("学号：%d\t姓名:%s\t年龄:%d\t成绩:%d\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
			}
			else
				printf("没有找到该学员.\n");
			system("pause");
			system("cls");
			break;
		}
		case 4:ModifyStudent(); break;
		}
	}
}
void InputStudent()
{
	//创建一个节点
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	//头插法、尾插法
	//头插法
	if (g_pHead == NULL)
	{
		g_pHead = pNewNode;
	}
	else
	{
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}
	printf("请输入学生姓名：\n");
	scanf("%s", pNewNode->stu.name);//从键盘格式化接收一个字符串，整数等
	printf("请输入学生的年龄：\n");
	scanf("%d", &pNewNode->stu.age);//&取地址运算符
	printf("请输入学生的学号：\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("请输入学生的成绩:\n");
	scanf("%d", &pNewNode->stu.score);
	printf("学生信息录入成功\n");
	system("pause");
	system("cls");//清屛
}
void DeleteStudent()
{
	int nStuNum;
	printf("请输入要删除的学生信息的学号:\n");
	scanf("%d", &nStuNum);
	Node* p1, *p2;
	if (g_pHead->stu.stuNum == nStuNum)
	{
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		printf("删除成功");
		return;
	}

	//不是头结点
	Node* p = g_pHead;
	while (p->pNext != NULL)
	{
		if (p->pNext->stu.stuNum == nStuNum)
		{
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;
		if (p->pNext == NULL)
		{
			break;
		}
	}
	if (p->pNext == NULL)
	{
		printf("没有找到该学员\n");
		system("pause");
		system("cls");
	}
}
Node* FindStudent()
{
	int nStuNum;
	char szName[20];
	printf("请输入要查找学生的学号:\n");
	scanf("%d", &nStuNum);
	printf("请输入要查找学生的姓名:\n");
	scanf("%s", szName);
	Node* p = g_pHead;
	while (p != NULL)
	{
		//strcmp字符串比较函数
		if (p->stu.stuNum == nStuNum || 0 == strcmp(p->stu.name, szName))
		{
			return p;
		}
		p = p->pNext;
	}
	//没有找到返回
	return NULL;
}
void ModifyStudent()
{
	int nStuNum;
	printf("请输入需要修改的学生信息的学号:\n");
	scanf("%d", &nStuNum);
	Node* p = g_pHead;
	while (p != NULL)
	{
		//strcmp字符串比较函数
		if (p->stu.stuNum == nStuNum)
		{
			printf("请输入要修改的学生姓名 年龄 成绩:\n");
			scanf("%s %d %d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("修改成功\n");
			break;
		}
		if (p == NULL)
		{
			printf("没有找到该学生信息\n");
		}
		p = p->pNext;
		system("pause");
		system("cls");
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
