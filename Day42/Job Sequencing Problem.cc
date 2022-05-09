#include<bits/stdc++.h>
using namespace std; 

struct Job { 
    int id;	 
    int dead;  
    int profit;
};


bool sortByProfit(Job const&j1, Job const&j2){
	return j1.profit > j2.profit;
}

vector<int> JobScheduling(Job arr[], int n) { 
	int time = 1;
	int max_deadline = 0;
	int max_profit = 0, jobs_done = 0;
	
	sort(arr, arr+n, sortByProfit);
	for(int i=0; i<n; i++) max_deadline = max(max_deadline,arr[i].dead);	
	vector<int> jobs(max_deadline+1,-1);
	
	for(int i=0; i<n; i++) {
		Job job = arr[i];	
		int deadline = job.dead;
		while(deadline && jobs[deadline] != -1) deadline--;
		if(!deadline) continue;
		
		jobs[deadline] = job.id;
		max_profit += job.profit;
		jobs_done++;
	}
	
	return {jobs_done,max_profit};		
} 
    
int main() {
	int n;
	cin >> n;
	Job arr[n];
	for(int i=0; i<n; i++) {
		int id, d, p;
		cin >> id >> d >> p;
		arr[i].id = id;
		arr[i].dead = d;
		arr[i].profit = p;
	}    
	
	vector<int> res = JobScheduling(arr,n);
    cout << res[0] << " " << res[1] << endl;
    
	return 0;
}
