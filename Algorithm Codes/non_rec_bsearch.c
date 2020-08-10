#include<stdio.h>
int bin_search(int arr[],int num,int low,int up){
        int mid;
        while(low<=up){
                mid=(low+up)/2;
                if(arr[mid]==num){
                        printf("\nElement found at index %d\n",mid);
                        return 0;
                }
                else if(arr[mid]<num)
                        low=mid+1;
                else
                        up=mid-1;
        }
        return 1;
}
int main(){
        int arr[10],num,size,i,flag;
        printf("\nEnter the size of the array:");
        scanf("%d",&size);
        printf("\nEnter the elements:");
        for(i=0;i<size;i++)
                scanf("%d",&arr[i]);
        printf("\nEnter the number to be searched:");
        scanf("%d",&num);
        flag=bin_search(arr,num,0,size-1);
	if(flag==1)
		printf("\nElement not found\n");
        return 0;
}

