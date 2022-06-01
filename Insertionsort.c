#include<stdio.h>
#include<conio.h>
void insertionSort(int arr[],int n);
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
  insertionSort(arr,n);
  printf("Sorted Array is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d",arr[i]);
  }
  getch();
void insertionSort(int arr[],int n)
{
 int i,j,temp;
 for(i=0;i<n-1;i++)
 {
  for(j=i;j>0&&arr[j-1]>arr[j];j--)
  {
   temp=arr[j];
   arr[j]=arr[j-1];
   arr[j-1]=temp;
  }
 }
}
