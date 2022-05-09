#include<bits/stdc++.h>
using namespace std;

bool isPartitionPossible(int i, int arr[], int curr_sum, int tar, int N) {
        if(i >= N || curr_sum > tar) return false;
        if(curr_sum == tar) return true;
        
        if(isPartitionPossible(i+1,arr,curr_sum+arr[i],tar,N)) return true;
        if(isPartitionPossible(i+1,arr,curr_sum,tar,N)) return true;
        return false;
    }
    
int equalPartition(int N, int arr[]) {
        int sum = 0;
        for(int i=0; i<N; i++) sum +=  arr[i];
        
        if(sum & 1) return 0;
        sum >>= 1;
        return isPartitionPossible(0,arr,0,sum,N);
}



