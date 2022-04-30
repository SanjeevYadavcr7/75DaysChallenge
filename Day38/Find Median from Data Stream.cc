#include "utils.h"


class MedianFinder {
priority_queue<int> maxHeap;
priority_queue<int,vector<int>, greater<>>  minHeap;
public:
		
    MedianFinder() {
	
    }
    
    void addNum(int num) {
        int m = minHeap.size();
        int n = maxHeap.size();
        
        if(m == 0) maxHeap.push(num);
        else if(m>0 && maxHeap.top() >= num) maxHeap.push(num);
        else minHeap.push(num);
        
        m = minHeap.size(), n = maxHeap.size();
        int size_diff = abs(m-n);
        if(size_diff > 1){
        	if(m>n){
        		maxHeap.push(minHeap.top());
        		minHeap.pop();
        	}
        	else{
        		minHeap.push(maxHeap.top());
        		maxHeap.pop();        	
        	}
        } 
    }
    
    double findMedian() {
		int m = minHeap.size();
        int n = maxHeap.size();        
    	double median;
		if(m == n) median = (minHeap.top() + maxHeap.top())/2.0;
    	else if(m > n) median = minHeap.top();
    	else median = maxHeap.top();
    	return median; 
    }
};

int main() {
	MedianFinder obj;
	while(true) {
		string str;
		cin >> str;
		if(str == "addNum"){
			int val;
			cin >> val;
			obj.addNum(val);
		}
		else if(str == "findMedian") cout << obj.findMedian() << endl;
		else break;
	}	

	return 0;
}
