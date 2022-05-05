#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodetype
{
	int info;
	struct nodetype *next;
}node;
void createEmptyList(node **head);
void traverseInOrder(node *head);
void traverseInReverseOrder(node *head);
void insertAtBeginning(node **head,int item);
void insertAtEnd(node **head, int item);
node *search(node *head,int item);
node *searchInSortedList(node *head, int item);
void insertAfterElement(node *head, int item, int after);
void deleteFromBeginning(node **head);
void deleteFromEnd(node **head);
void deleteAfterElement(node *head, int after);
void Delete(node **head);

void main()
{
	node *head;
	int choice,element,after;
	createEmptyList(&head);
	while(1)
	{
		printf("\nLINKED LIST:\n");
		printf("\n1- Insert at beginning\n2- Traverse in order\n3.Traverse in reverse order\n4.Insert at end\n5. Search an element in unsorted list\n6. Search an element in sorted list\n7.Insert after element\n8.Delete from beginning\n9.Delete from end\n10.Delete after element\n11.Delete entire linked list\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Elements\n");
				scanf("%d",&element);
				insertAtBeginning(&head,element);
				break;
			case 2:
				   if(head==NULL)
					 printf("\mThe list is empty\n");
				   else
					 traverseInOrder(head);
					 printf("\nPress any key to continue\n");
					 getch();
					 break;
			case 3:
				   if(head==NULL)
					 printf("\mThe list is empty\n");
				   else
					 traverseInReverseOrder(head);
					 printf("\nPress any key to continue\n");
					 getch();
					 break;
			case 4:
				   printf("Enter element\n");
				   scanf("%d",&element);
				   insertAtEnd(&head,element);
				   break;
			case 5:
				   printf("Enter an element to be searched\n");
				   scanf("%d",&element);
				   printf("%d",searchInSortedList(head,element));
				   break;
			case 6:
				   printf("Enter an element to be searched\n");
				   scanf("%d",&element);
				   printf("%d",search(head,element));
				   break;
			case 7:
				   printf("\nEnter element after which to store:");
				   scanf("%d",&after);
				   printf("Enter element\n");
				   scanf("%d",&element);
				   insertAfterElement(head, element, after);
				   break;
			case 8:
				   deleteFromBeginning(&head);
				   printf("\nSTARTING ELEMENT DELETED\n");
				   break;
			case 9:
				   deleteFromEnd(&head);
				   printf("\nLAST ELEMENT DELETED\n");
				   break;
			case 10:
				   printf("\nEnter before element to delete:");
				   scanf("%d",&after);
				   printf("Enter element\n");
				   scanf("%d",&element);
				   deleteAfterElement(head,after);
				   break;
			case 11:
					Delete(&head);
					break;
			default:
				   exit(0);
		 }
	}
}
void createEmptyList(node **head)
{
	*head= NULL;
}
void insertAtBeginning(node **head,int item)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	if(*head == NULL)
	{
		ptr->next=NULL;
	}
	else
		ptr->next=*head;
		*head=ptr;
}

void traverseInOrder(node *head)
{
	while(head!=NULL)
	{
		printf("\n%d",head->info);
		head = head->next;
	}
}
void traverseInReverseOrder(node *head)
{
	if(head!=NULL)
	{
		traverseInReverseOrder(head->next);
	}
	printf("%d",head->info);
}
void insertAtEnd(node **head, int item)
{

	node *ptr, *loc;
	ptr = (node *) malloc (sizeof(node));
	ptr->info = item;
	ptr->next = NULL;
	if(*head == NULL)
	{
		*head = ptr;
	}
	else
	{
		loc = *head;
		while (loc->next !=NULL)
		{
			loc = loc->next;
		}
		loc->next = ptr;

	}
}
node *search(node *head,int item)
{
	while((head!=NULL)&&(head->info!=item))
	head=head->next;
	return head;
}
node *searchInSortedList(node *head, int item)
{
	while(head != NULL)
	{
		if(head->info == item)
			return head;
		else if(item <head->info)
			return NULL;
		else
			head = head->next;

	}
	return NULL;
}
void insertAfterElement(node *head, int item, int after)
{
	node *ptr, *loc;
	loc = searchInSortedList(head,after);
	if (loc == (node *) NULL)
	{
		return;
	}
	ptr = (node *) malloc (sizeof (node));
	ptr ->info = item;
	ptr->next = loc->next;
	ptr->next = ptr;
}
void deleteFromBeginning(node **head)
{
	node *ptr;
	if(*head == NULL)
	{
		return;
	}
	else
	{
	 ptr = *head;
	 *head = (*head) -> next;
	 free(ptr);
	}
}
void deleteFromEnd(node **head)
{
	node *ptr, *loc;
	if(*head == NULL)
	{
		return;
	}
	else if((*head)->next == (node*) NULL)
	{
		ptr = *head;
		*head = NULL;
		free(ptr);
	}
	else
	{
	 loc = *head;
	 ptr = (*head)->next;
	 while(ptr->next != NULL)
	 {
		loc = ptr;
		ptr=ptr->next;
	}
	loc->next=NULL;
	free(ptr);
	}
}
void deleteAfterElement(node *head, int after)
{
	node *ptr, *loc;
	loc = searchInSortedList(head,after);
	if(loc == (node*)NULL)
		return;
	ptr = loc->next;
	loc ->next = ptr->next;
	free(ptr);
}
void Delete(node **head)
{
	node *ptr;
	while(*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}
