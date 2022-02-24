#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node*creatlist()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
};
struct Node*creatNode(int data)
{
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};
void printList(struct Node*headNode)
{
	struct Node*Pmove = headNode->next;
	while (Pmove)
	{
		printf("%d\t", Pmove->data);
		Pmove = Pmove->next;
	}
	printf("\n");

}
void insert_Node_By_HeadNode(struct Node*headNode, int data)
{
	struct Node*newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void delete_Node_By_Appoin(struct Node* headNode, int posData)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode==NULL)
		printf("无法删除链表为空\n");
	else
	{
		while (posNode->data!= posData)
		{
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if (posNode==NULL)
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
	insert_Node_By_HeadNode(list, 1);
	insert_Node_By_HeadNode(list, 2);
	insert_Node_By_HeadNode(list, 3);
	printList(list);
	delete_Node_By_Appoin(list, 2);
	printList(list);
	system("pause");
	return 0;

}
