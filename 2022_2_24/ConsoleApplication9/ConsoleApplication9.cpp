#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct student
{
	char name[20];
	int  num;
	int math;
};
struct Node
{
	struct student data;
	struct Node* next;
};
struct Node*creatlist()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
};
struct Node*creatNode(struct student data)
{
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};
void printList(struct Node*headNode)
{
	struct Node*Pmove = headNode->next;
	printf("name\tnum\tmath\n");
	while (Pmove)
	{
		printf("%s\t%d\t%d\n", Pmove->data.name,Pmove->data.num,Pmove->data.math);
		Pmove = Pmove->next;
	}
	printf("\n");

}
void insert_Node_By_HeadNode(struct Node*headNode, struct student data)
{
	struct Node*newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void delete_Node_By_AppoinNum(struct Node* headNode, int num)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("无法删除链表为空\n");
	else
	{
		while (posNode->data.num != num)
		{
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if (posNode == NULL)
			{
				printf("未找到相关信息，无法删除\n");
				return;
			}

		}
		posNodeFront->next = posNode->next;
		free(posNode);
	}
}
int main()
{
	struct Node*list = creatlist();
	struct student info;
	while (1)
	{
		printf("请输入学生的姓名 学号 数学成绩");
		setbuf(stdin, NULL);
		scanf("%s%d%d", info.name, &info.num, &info.math);
		insert_Node_By_HeadNode(list, info);
		printf("continue(Y/N)?\n");
		setbuf(stdin, NULL);
		int choice = getchar();
	    if (choice == 'N' || choice == 'n')
		{
			break;
		}
	}
	printList(list);
	printf("请输入要删除的学生的学号");
	scanf("%d", &info.num);
	delete_Node_By_AppoinNum(list, info.num);
	printList(list);
	system("pause");
	return 0;

}
