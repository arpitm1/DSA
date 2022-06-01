#include<stdio.h>
#include<conio.h>
void bubbleSort(int arr[],int n);
void main()
{
  int i,n,arr[20];
  clrscr();
  printf("Enter the size of an array:\n");
  scanf("%d",&n);
  printf("Enter the elements of an array:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  bubbleSort(arr,n);
  printf("Sorted Array is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d",arr[i]);
  }
  getch();
}
void bubbleSort(int arr[],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
	temp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=temp;
      }
    }
  }
}
