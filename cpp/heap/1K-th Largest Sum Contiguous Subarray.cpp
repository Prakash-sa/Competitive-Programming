//https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/


// CPP program to find the k-th largest sum of subarray

#include <bits/stdc++.h>
using namespace std;

int kthLargestSum(int arr[], int n, int k){
	int sum[n + 1];
	sum[0] = 0;
	sum[1] = arr[0];
	for (int i = 2; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i - 1];

	priority_queue<int, vector<int>, greater<int> > Q;

	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			int x = sum[j] - sum[i - 1];

			if (Q.size() < k)
				Q.push(x);

			else{
				if (Q.top() < x){
					Q.pop();
					Q.push(x);
				}
			}
		}
	}

	return Q.top();
}

int main()
{
	int a[] = { 10, -10, 20, -40 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 6;

	cout << kthLargestSum(a, n, k);
	return 0;
}

