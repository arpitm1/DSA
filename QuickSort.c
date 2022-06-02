#include<stdio.h>
#include<conio.h>
void quickSort(int arr[],int low,int high);
void swap(int *a,int *b);
int partition(int arr[],int low,int high);
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
   quickSort(arr,0,n-1);
  printf("Sorted Array is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d",arr[i]);
  }
  getch();
}
void quickSort(int arr[],int low,int high)
{
 if(low<high)
 {
  int pi=partition(arr,low,high);
  quickSort(arr,low,pi-1);
  quickSort(arr,pi+1,high);
 }
}
void swap(int *a, int *b)
{
 int t=*a;
 *a=*b;
 *b=t;
}
int partition(int arr[],int low,int high)
{
 int pivot=arr[high];
 int i=(low-1),j;

 for(j=low;j<=high-1;j++)
 {
  if(arr[j]<pivot)
  {
   i++;
   swap(&arr[i],&arr[j]);
  }
 }
 swap(&arr[i+1],arr[high]);
 return(i+1);
}
