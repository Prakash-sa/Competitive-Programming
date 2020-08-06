// C++ implementation to increment values in the 
// given range by a value d for multiple queries 
#include <bits/stdc++.h> 
using namespace std; 

struct query { 
	int start, end; 
}; 

void incrementByD(int arr[], struct query q_arr[],	int n, int m, int d) 
{ 
	int sum[n]; 
	memset(sum, 0, sizeof(sum)); 
	for (int i = 0; i < m; i++) { 
		sum[q_arr[i].start] += d; 
		if ((q_arr[i].end + 1) < n) 
		sum[q_arr[i].end + 1] -= d; 
	} 
	arr[0] += sum[0]; 
	for (int i = 1; i < n; i++) { 
		sum[i] += sum[i - 1]; 
		arr[i] += sum[i]; 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int arr[] = { 3, 5, 4, 8, 6, 1 }; 
	struct query q_arr[] = { { 0, 3 }, { 4, 5 }, { 1, 4 }, 
									{ 0, 1 }, { 2, 5 } }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int m = sizeof(q_arr) / sizeof(q_arr[0]); 
	int d = 2; 

	printArray(arr, n); 
    incrementByD(arr, q_arr, n, m, d); 
    printArray(arr, n); 

	return 0; 
} 
