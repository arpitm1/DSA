#include<stdio.h>
#include<conio.h>
void selectionSort(int arr[],int n);
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
  selectionSort(arr,n);
  printf("Sorted Array is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d",arr[i]);
  }
  getch();
}
void selectionSort(int arr[],int n)
{
 int i,j,min_inx,temp;
 for(i=0;i<n-1;i++)
 {
  min_inx=i;
  for(j=i+1;j<n;j++)
   if(arr[j]<arr[min_inx])
   min_inx=j;

   temp=arr[min_inx];
   arr[min_inx]=arr[i];
   arr[i]=temp;
 }
}
