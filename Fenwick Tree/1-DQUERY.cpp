#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
// using ll = long long;
#define N 30010
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n;

class event{
public:
	//first: L
	//second: R
	int first, second, index;

};

bool compare(event a, event b)
{
	return a.second < b.second;
}

void update(int index, int value, int n, int* bit)
{
	for(; index<=n; index += (index & (-index)))
	{
		bit[index] += value;
	}


}

int value(int index, int* bit) //query function
{
	int count =0;
	for(; index>0; index -= (index&(-index)))
	{
		count += bit[index];
	}

	return count;

}

signed main()
{
	fio

	cin>>n;

	int* arr = new int[n+1];
	//indexing 1 to n -> easy to think
	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
	}

	int q;
	cin>>q;

	//query array->(first, second) and an idx(to make array ofsuch queries)
	
	event* query = new event[q];
	for(int i=0; i<q; i++)
	{
		cin >> query[i].first >> query[i].second;
		query[i].index = i;
	}


	//sort them on the basis of second (ending index, bcz, then we can easily make offline queries using BIT (BIT intrnally works like prefix sums))
	sort(query, query+q, compare);

	int* BIT = new int[n+1];
	int* ans = new int[q];

	int total = 0; //total distinct elements
	int k = 0; //kth query

	//element pehle aa chuka hai ya nhi
	int* last = new int[1000001];
	for(int i=0; i<=1000000; i++)
	{
		//we could have used map also, but we can do this also, as it is saying, no element has occured before
		last[i] = -1;
	}



	

	//now traversing all array
	for(int i=1; i<=n; i++)
	{
		if(last[arr[i]] != -1)
		{
			//if ith element has already occured(then last[arr[i]]!=-1), then contribute -1 to BIT (since it again came in array)
			update(last[arr[i]], -1, n, BIT);
		}

		else
		{
			//total = total no of distinct elements till ith index
			total ++;
		}

		update(i, 1, n, BIT); //ith index ke liye +1 contribution daal do, n is maxm index upto which i can go in BIT
		//upadting last occurence of arr[i]
		last[arr[i]] = i;



		while( k<q and query[k].second == i) //all queries that end with i as R, unka ans calculate kro
		{
			ans[query[k].index] = total - value(query[k].first - 1, BIT);
			k++; 
		}

	}

	//now all answers are precomputed, offline programming over


	//now go through each query and answer them
	for (int i = 0; i < q; ++i)
	{
		cout<<ans[i]<<endl;
	}




	return 0;
}
