// Update and Query in O(log n)
// Easy to code
// Less space
// n+1 size tree we build, in segment tree we make 4*n size tree
// in BIT[] we dont store anything at BIT[0]
// if arr[1] to arr[n] is our input array, our BIT[1] to BIT[n] contains sum


//IUse Case :: useful for storing prefixsums.
//
//prefix sum precomputation in -> O(n) using brute forces, then return in O(1).
//update, sum, upadte , sum ..., then prefix sums wont work... worst case::: O(q * n)
 
//sum , upadte boh in O(log n).
//keep the given array as 1-based
//at every idx in BIT tree:: [1, n] , each BIT[idx] stores prefix sums from [lb, idx] in arr[], lb = remove rightmost set bit, the number formed +1 , is the idx. 
 
//in a single update-> a value in array.
//whatever idx in BIT stores, the changed number as prefix sums, those idx ke BIT[] will also be updated.

//if old a[idx] = 1, new a[idx] = 6, do update(idx, +5).

//how to get the next idx from current idx? -1/ find 2's complement. 2/ and with current idx. 3/ add to original idx.


//agar query bola jaye ? 
//e.g. (1, 12) -> ka sums kin kin idx se uthaya jayega in BIT[]-> 8 + 4(12) :: (1-8) + (9-12).
//e.g. (1, 14) -> 8(8) + 4(12) + 2(14) -> (1-8) + (9-12) + (13-14).

#include<bits/stdc++.h>
using namespace std;

void update(int index, int value, int* BIT, int n)
{
	// if 1 index is changed , array size=8, then 1->2->4->8
	for(; index<=n; index += index&(-index))
	{
		BIT[index] += value;
	}
}

int query(int index, int* BIT)
{
	int sum=0;
	for(; index>0; index -= index&(-index))
	{
		sum+=BIT[index];
	}
	return sum;
}

signed main()
{
	int n;
	cin>>n;
	int* arr = new int[n+1]();	// arr of size n=1 initialised to 0
	int* BIT = new int[n+1]();

	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
		update(i, arr[i], BIT, n); //update in BIT[], after ith elemnt in array is changed to arr[i]; 
	}


	// query 
	cout<<"Sum of first 5 elements "<<query(5, BIT)<<endl;
	// if sum between 3 to 7 index in array, query(7)-query(3-1).
	cout<<"Sum of elements from 2 inde to 6 index "<<query(6, BIT) - query(1, BIT)<<endl;
	return 0;
} 
