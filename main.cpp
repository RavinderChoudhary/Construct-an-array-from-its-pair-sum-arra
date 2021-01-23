#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> sumPair = {15, 13, 11, 10, 12, 10, 9, 8, 7, 5};
	int m = sumPair.size();
	int n = 5;
	vector<int> arr(n,0);
	
	int sum = 0;
	for(auto i : sumPair)
	   sum += i;
	sum /= (n-1);
	
	int j = 0;
	int join = n-1;
	for(int i=0;i<m-1;){
	    int tmp = join;
	    int s = 0;
	    while(tmp > 0){
	        s += sumPair[i];
	        i++;
	        tmp--;
	    }
	    
	    arr[j] = (s - sum)/(join-1); 
	    sum -= arr[j];
	    j++;
	    join--;
	}
	
	arr[n-1] = sumPair[m-2] - arr[n-3];
	arr[n-2] = sumPair[m-1] - arr[n-1];
	for(auto i : arr)
	  cout<<i<<" ";
	return 0;
}

/*
#include <bits/stdc++.h> 
using namespace std; 

// Fills element in arr[] from its pair sum array pair[]. 
// n is size of arr[] 
void constructArr(int arr[], int pair[], int n) 
{ 
	arr[0] = (pair[0]+pair[1]-pair[n-1]) / 2; 
	for (int i=1; i<n; i++) 
		arr[i] = pair[i-1]-arr[0]; 
} 

// Driver program to test above function 
int main() 
{ 
	int pair[] = {15, 13, 11, 10, 12, 10, 9, 8, 7, 5}; 
	int n = 5; 
	int arr[n]; 
	constructArr(arr, pair, n); 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	return 0; 
} 
*/
