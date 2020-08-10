#include<iostream> 
#include<algorithm> 
using namespace std; 
struct Job 
{ 
	int id;// Job Id 
	int dead; // Deadline of job 
	int profit; // Profit gained if job is over before or on deadline 
}; 

// Comparing criteria for sorting the jobs 
bool comparison(Job a, Job b) 
{ 
	return (a.profit > b.profit); 
}  
void printJobScheduling(Job arr[], int n) 
{ 
	// Sort all jobs according to decreasing order of profit 
	sort(arr, arr+n, comparison); 
	int max_profit=0;
	int result[n]; // To store the Sequence of jobs 
	bool slot[n]; // To keep track of free time slots 

	// Initializing as all slots to be free
	for (int i=0; i<n; i++) 
		slot[i] = false; 
	cout<<"\nJob No.  Assigned Slot\n";
	// Iterating through all given jobs 
	for (int i=0; i<n; i++) 
	{ 
	// Finding a free slot for the job i (Starting from the last possible slot) 
	for (int j=min(n, arr[i].dead)-1; j>=0; j--) 
	{ 
		// If a Free slot is found following bloxk is executed 
		if (slot[j]==false) 
		{ 
			result[j] = i; // Adding the job to result array 
			cout << arr[i].id << "\t\t"<<j<<"-"<<j+1<<"\n";
			slot[j] = true; // Marking the slot as occupied
			max_profit+=arr[i].profit; 
			break; 
		} 
	} 
	} 
	cout<<"\nMaximum Profit:"<<max_profit;
		 
}  
int main() 
{ 
	Job arr[10]; 
	int n;
	cout<<"\nEnter the number of jobs:";
	cin>>n;
	for(int i=0;i<n;i++){
		arr[i].id=i+1;
		cout<<"\nEnter the Profit for Job "<<i+1<<":";
		cin>>arr[i].profit;
		cout<<"Enter the Deadline for Job "<<i+1<<":";
		cin>>arr[i].dead;
	}
	cout << "Following is maximum profit sequence of jobs\n"; 
	printJobScheduling(arr, n); 
	return 0; 
} 
