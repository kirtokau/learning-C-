#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addNewNode();
void deleteNode();
void searchNode();
void updateNode();
void info_output(struct Student student);
int findTheNode(struct Student student[], int num);
struct Student
{
	int num;
	char  name[20];
	float hMath;
}student[10];
int count = 0;
int main()
{
	while (1)
	{
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:addNewNode(); break;
		case 2:deleteNode(); break;
		case 3:searchNode(); break;
		case 4:updateNode(); break;
		}
	}
}
	
void addNewNode()
{

	printf("请输入学号\n");
	scanf("%d", &student[count].num);
	printf("请输入姓名\n");
	scanf("%s", student[count].name);
	printf("请输入高数\n");
	scanf("%f", &student[count].hMath);
	printf("%s同学的信息添加成功\n", student[count].name);
	count++;
}
void deleteNode()
{
	int num = 0;
	int target = 0;//用于接收目标节点的下标返回值
	printf("请输入你想要删除学生的学号\n");
	scanf("%d", &num);
	target = findTheNode(student, num);
	if (target < 0)
	{
		printf("对不起，查无此记录\n");
		return;
	}
	else {
		for (int i = target; i < count; i++)
		{
			student[i] = student[i + 1];
		}
		count--;
		printf("删除成功");
	}
}
int findTheNode(struct Student student[], int num)
{
	int temp = -1;
	for (int i = 0; i < count; i++)
	{
		if (student[i].num == num)
		{
			temp = i;
			break;
		}
	}
	return temp;
}
void searchNode()
{
	int num = 0;
	int target = 0;
	printf("请输入你想要查找学生的学号\n");
	scanf("%d", &num);
	target = findTheNode(student, num);
	if (target < 0)
	{
		printf("查无此人");
	}
	else
	{
		info_output(student[target]);
	}


}
void info_output(struct Student student)//传入节点
{
	//printf("****************************************************\n");
	printf("学号:%d\t姓名:%s\t高数%.2f\t\n",
		student.num, student.name, student.hMath);
	//printf("****************************************************\n");
}
void updateNode()
{
	int num = 0;
	int target = 0;
	printf("请输入你想修改学生的学号\n");
	scanf("%d", &num);
	target = findTheNode(student, num);
	if (target < 0)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("请输入学号\n");
		scanf("%d", &student[target].num);
		printf("请输入姓名\n");
		scanf("%s", student[target].name);
		printf("请输入高数\n");
		scanf("%f", &student[target].hMath);
		printf("修改成功\n");
		info_output(student[target]);
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
