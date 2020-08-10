
#include <bits/stdc++.h> 

using namespace std; 

// Structure for an item which stores weight and corresponding 
// value of Item 
struct Item 
{ 
	int weight,profit,item_no; 

	/*// Constructor 
	Item(int profit, int weight) : profit(profit), weight(weight) 
	{}*/ 
}; 

// Comparison function to sort Item according to profit/weight ratio 
bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.profit / a.weight; 
	double r2 = (double)b.profit / b.weight; 
	return r1 > r2; 
} 

// Main greedy function to solve problem 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
	// sorting Item on basis of ratio 
	sort(arr, arr + n, cmp); 
 	cout<<"The rearranged list according to decreasing profit/weight ratio:(as item no. .... profit....weight....profit/weight ratio)\n";
	for (int i = 0; i < n; i++) 
	{ 
		cout <<arr[i].item_no<<" "<< arr[i].profit << " " << arr[i].weight << " : " 
			<< ((double)arr[i].profit / arr[i].weight) << endl; 
	} 

	int curWeight = 0; // Current weight in knapsack 
	double finalprofit = 0.0; // Result (value in Knapsack) 

	// Looping through all Items 
	for (int i = 0; i < n; i++) 
	{ 
		// If adding Item won't overflow, add it completely 
		if (curWeight + arr[i].weight <= W) 
		{ 
			curWeight += arr[i].weight; 
			finalprofit += arr[i].profit; 
			cout<<"\nAdding item no. "<<arr[i].item_no<<" completely to the Knapsack";
		} 

		// If we can't add current Item, add fractional part of it 
		else
		{ 
			int remain = W - curWeight; 
			finalprofit += arr[i].profit * ((double) remain / arr[i].weight);
			cout<<"\nAdding "<<((double)remain/arr[i].weight)<<" part of the item no. "<<arr[i].item_no<<" to the Knapsack"; 
			break; 
		} 
	} 

	// Returning final value 
	return finalprofit; 
} 

// driver program to test above function 
int main() 
{ 
	int W,num_items; // Weight of knapsack 
	Item arr[20]/* = {{10, 2}, {5, 3}, {15, 5},{7,7},{6,1},{18,4},{3,1}}*/;
	cout<<"\nEnter the Knapsack capacity:";
	cin>>W; 
	cout<<"\nEnter the number of items(max. 20):";
	cin>>num_items;
	for(int i=0;i<num_items;i++){
		arr[i].item_no=i+1;
		cout<<"Enter weight of item no. "<<i+1<<":";
		cin>>arr[i].weight;
		cout<<"Enter profit of item no. "<<i+1<<":";
		cin>>arr[i].profit;
		cout<<"\n";
	}

	cout << "\n\nMaximum profit we can obtain = "
		<< fractionalKnapsack(W, arr, num_items); 
	return 0; 
} 

