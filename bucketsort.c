#include<stdio.h>
#include<conio.h>
void bucketSort(int arr[],int n);
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
  bucketSort(arr,n);
  printf("Sorted Array is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d",arr[i]);
  }
  getch();
  }
void bucketSort(int arr[],int n)
{
 int i,j;
 int count[4];
 for(i=0;i<n;i++)
  count[i]=0;
 for(i=0;i<n;i++)
 (count[arr[i]])++;
 for(i=0,j=0;i<n;i++)
  for(;count[i]>0;(count[i])--)
    arr[j++]=i;
}
