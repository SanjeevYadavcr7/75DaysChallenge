#include<bits/stdc++.h>
using namespace std;

/*
NOTE: This question can be tricky to understand for some people, atleast for me it was tricky! 

Explanation :- 
The aim in this question is to get total time taken by CPU to execute all tasks considering the cooldown period

for example: 
Case1: 	Tasks = [A A A A] cooldown = 2		
	    CPU Execution = [A _ _ A _ _ A _ _ A]
	    Total Time = 10
			 
Case2:  Tasks = [A A A B B]  cooldown = 2
		CPU Execution = [A B _ A B _ A]	
		Total Time = 7		 

Case3:  Tasks = [A A A B B B]  cooldown = 2
		CPU Execution = [A B _ A B _ A B]
		Total Time = 8

If we observe carefully in above examples we can see that total time depends on the task which is executing maximum no. of times because it will require maximum time to get executed. How ? .....see example below!
 
i.e. for case1: Tasks = [A A A A]  cooldown = 2
				max task freq = A-->4
				So, 
				CPU Execution = A will be executing 4 times + idle state (*due to cooldowm)
				CPU Execution = A _ _ + A _ _ + A _ _ + A 
				CPU Execution = (max_task_freq-1) * (n+1) + count(max_task_freq)
				CPU Execution = (4-1) * (2+1) + 1 = 10			

	for case2: Tasks = [A A A B B]  cooldown = 2
				NOTE: Here you'll see that any task which has less freq than max_freq _task will not contribute in total time 
				here, max task freq = A-->3
				So, 
				CPU Execution for A = A _ _ + A _ _ + A 
				CPU Execution for B = A B _ + A B _ + A
				CPU Execution (A+B) = A B _ A B _ A 
				CPU Execution = (3-1) * (2+1) + 1 = 7

	for case3: Tasks = [A A A B B B]  cooldown = 2
				NOTE: Here you'll see that any task which has less freq than max_freq _task will not contribute in total time 
				here, max task freq = A-->3 | B-->3
				So, 
				CPU Execution for A = A _ _ + A _ _ + A 
				CPU Execution for B = A B _ + A B _ + AB
				CPU Execution (A+B) = A B _ A B _ A B
				CPU Execution = (3-1) * (2+1) + 2 = 8	
*/


int leastInterval(vector<char>& tasks, int n) {
	if(n == 0) return tasks.size();
	
	int cnt = 0;
	int max_task_freq = 0;	
	vector<int> task_freq(26);
	for(char ch : tasks) task_freq[ch-'A']++;
	
	for(int i=0; i<26; i++) {
		if(task_freq[i] == 0) continue;
		if(max_task_freq < task_freq[i]) {
			max_task_freq = task_freq[i];
			cnt = 1;
		}
		else if(max_task_freq == task_freq[i]) cnt++;
	}
	
	int req_days = (n+1) * (max_task_freq-1) + cnt;
	return req_days > tasks.size() ? req_days : tasks.size();
}

int main() {	
	int n,k;
	cin >> n;
	vector<char> tasks(n);
	for(int i=0; i<n; i++) cin >> tasks[i];
	cin >> k;
	
	int interval = leastInterval(tasks,k);
	cout << interval << endl;	
	
	return 0;
}
