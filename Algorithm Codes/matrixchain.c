
#include<stdio.h> 
#include<limits.h>
int part[20][20];
int MatrixChainOrder(int p[], int n) 
{ 
	int m[n][n]; 

	int i, j, k, L, q; 
	for (i=1; i<n; i++) 
		m[i][i] = 0; 

	for (L=2; L<n; L++) 
	{ 
		for (i=1; i<n-L+1; i++) 
		{ 
			j = i+L-1; 
			m[i][j] = INT_MAX; 
			for (k=i; k<=j-1; k++) 
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
				if (q < m[i][j]){
					m[i][j] = q;
					part[i][j]=k;
				} 
			} 
		} 
	} 

	return m[1][n-1]; 
}
void print_order(int i,int j){
	if(i==j)
		printf(" M%d ",i);
	else{
		printf("(");
		print_order(i,part[i][j]);
		printf(" * ");
		print_order(part[i][j]+1,j);
		printf(")");
	}
}

int main() 
{ 
	int arr[10]; 
	int size; 
	printf("\nEnter the number of matrices in chain:");
	scanf("%d",&size);
	printf("\nEnter the dimensions of the matrices:");
	for(int i=0;i<=size;i++)
		scanf("%d",&arr[i]);
	printf("Minimum number of multiplications is %d\n ",MatrixChainOrder(arr, size+1)); 
	printf("\nThe multiplication order is:\n");
        print_order(1,size);
	return 0; 
} 

