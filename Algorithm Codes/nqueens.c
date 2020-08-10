    #include<stdio.h>
    #include<math.h>
    #include<time.h>
    int a[30],count=0;
    int place(int pos) {
    	int i;
    	for (i=1;i<pos;i++) {
    		if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
    		   return 0;
    	}
    	return 1;
    }
    void print_sol(int n) {
    	int i,j;
    	count++;
    	printf("\n\nSolution no.%d:\n",count);
    	for (i=1;i<=n;i++) {
    		for (j=1;j<=n;j++) {
    			if(a[i]==j)
    			    printf("Q\t"); else
    			    printf(".\t");
    		}
    		printf("\n");
    	}
    }
    void queen(int n) {
    	int k=1;
    	a[k]=0;
    	while(k!=0) {
    		a[k]=a[k]+1;
    		while((a[k]<=n)&&!place(k))
    		   a[k]++;
    		if(a[k]<=n) {
    			if(k==n)
    			    print_sol(n); else {
    				k++;
    				a[k]=0;
    			}
    		} else
    		   k--;
    	}
    }
    void main() {
    	int i,n;
    	clock_t start,end;
    	double time_taken;
    	printf("Enter the number of Queens\n");
    	scanf("%d",&n);
    	start=clock();
    	queen(n);
    	end=clock();
    	time_taken= (double)(end-start)/CLOCKS_PER_SEC;
    	printf("\nTotal solutions=%d",count);
    	printf("\nTime required for completion=%lf seconds",time_taken);
    }
