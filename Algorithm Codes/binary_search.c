#include<conio.h>
#include<stdio.h>
int Binary_Search(int A[],int beg,int last,int ele){
	if(last>=beg){
	int mid=(beg+last)/2;
   if(A[mid]==ele)
   	return mid+1;
   else if(A[mid]<ele)
   	return Binary_Search(A,mid+1,last,ele);
   else
   	return Binary_Search(A,beg,mid-1,ele);
   }
   return 0;
}
int main(){
	int A[10],size,pos,ele;
   printf("\nEnter the size of the array:");
   scanf("%d",&size);
   printf("\nEnter the elements of array(in ascending order):");
   for(int i=0;i<size;i++)
   	scanf("%d",&A[i]);
   printf("\nEnter the element to be searched:");
   scanf("%d",&ele);
   pos=Binary_Search(A,0,size-1,ele);
   if(pos)
   	printf("\nElement found at position %d",pos);
   else
   	printf("\nElement not found");
   getch();
   return 0;
}
