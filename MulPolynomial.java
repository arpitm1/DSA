#include<stdio.h>
#include<conio.h>
typedef struct nodetype
{
	int coeff;
	int power;
	struct nodetype *next;
}node;
void readPolynomial(node **);
void addPolynomial(node *,node *,node **);
void printPolynomial(node *);
void addNode(node **,int,int);
void deletePolynomial(node **);
void multiplyPolynomial(node *,node *,node **);
node *search(node *head,int item);
void main()
{
	node *poly1,*poly2,*poly3;
	int choice,element,after,before;
	poly1=poly2=poly3=NULL;
	clrscr();
	printf("Enter the first Polynomials: \n");
	readPolynomial(&poly1);
	printf("Enter the second Polynomials: \n");
	readPolynomial(&poly2);
	multiplyPolynomial(poly1,poly2,&poly3);
	//addPolynomial(poly1,poly2,&poly3);
	printf("Sum of polynomials:\n");
	//printPolynomial(poly1);
	//printPolynomial(poly2);
	printPolynomial(poly3);
	getch();
	deletePolynomial(&poly1);
	deletePolynomial(&poly2);
	deletePolynomial(&poly3);
}
void addNode(node **ptr,int coef,int powe)
{
	node *tempPtr;
	tempPtr=(node *)malloc(sizeof(node));
	tempPtr->coeff=coef;
	tempPtr->power=powe;
	if(*ptr==NULL)
	{
		tempPtr->next=NULL;
		*ptr=tempPtr;
	}
	else
	{
		tempPtr->next= *ptr;
		*ptr =tempPtr;
	}
}

void readPolynomial(node **p)
{
	int coeficient,power;
	printf("Enter the terms in ascending power\n");
	while(1)
	{
		printf("Enter the degree of x: \n");
		scanf("%d",&power);
		printf("Enter its coefficient: \n");
		scanf("%d",&coeficient);
		addNode(p,coeficient,power);
		printf("Any more term (Y/N)?: \n");
		if(getch()!='y')
			break;
	}
}
void printPolynomial(node *ptr)
{
	if(ptr!=NULL)
	printf("%dx^%d",ptr->coeff,ptr->power);
	for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next)
	{
		if(ptr->coeff>0)
			printf("+");
		if(ptr->power==0)
			printf("%d",ptr->coeff);
		else if(ptr->power==1)
			printf("%dx",ptr->coeff);
		else
			printf("%dx%d",ptr->coeff,ptr->power);
	}
}

void addPolynomial(node *ptr1,node *ptr2,node **ptr3)
{
	int powe;
	float coef;
	while((ptr1!=NULL)&&(ptr2!=NULL))
	{
		if(ptr1->power>ptr2->power)
		{
			coef=ptr1->coeff;
			powe=ptr1->power;
			ptr1=ptr1->next;
		}else if(ptr1->power<ptr2->power)
		{
			coef=ptr2->coeff;
			powe=ptr2->power;
			ptr2=ptr2->next;
		}else{
			coef=ptr1-> coeff+ptr2->coeff;
			powe=ptr1->power;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
			}
			if(coef!=0)
			{
				addNode(ptr3,coef,powe);
			}
			if(ptr1==NULL)
			{
				for(;ptr2!=NULL;ptr2=ptr2->next)
				{
					addNode(ptr3,ptr2->coeff,ptr2->power);
				}
			}else if(ptr2==NULL)
			{
				for(;ptr1!=NULL;ptr1=ptr1->next)
				{
					addNode(ptr3,ptr1->coeff,ptr1->power);
				}
			}
		}
	}
void deletePolynomial(node **ptr)
{
	node *temp;
	while(*ptr!=NULL)
	{
		temp=*ptr;
		*ptr=(*ptr)->next;
		free(temp);
	}
}
void multiplyPolynomial(node *ptr1,node *ptr2,node **ptr3)
{
	int powe,coef;
	node *temp,*loc,*tt;
	while(ptr1!=NULL)
	{
		temp=ptr2;
		while(temp!=NULL)
		{
			coef=ptr1->coeff*temp->coeff;
			powe=ptr1->power+temp->power;
			tt=*ptr3;
			loc=search(tt,powe);
			if(loc==NULL)
			addNode(ptr3,coef,powe);
			else
			loc->coeff=loc->coeff+coef;
			temp=temp->next;
		}
		ptr1=ptr1->next;
	}
}
node *search(node *head,int item)
{
	while((head!=NULL)&&(head->power!=item))
	head=head->next;
	return head;
}
