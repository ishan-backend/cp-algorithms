#include<bits/stdc++.h>
using namespace std;

class trieNode{
public:
	//pointers to following set(1)bit and unset(0) bit.
	trieNode* left;
	trieNode* right;
};

void insert(int n, trieNode* head) //if we want to insert n in trie
{
	trieNode* curr=head;

	for(int i=31; i>=0; i--)
	{
		//b contains ith bit of number n,(using left shift)
		//&1 helps to identify if that bit is set
		int b = (n>>i)&1;

		if(b==0)//if cuurr bit is 0
		{
			//hamesha mujhe left me move krna hai
			//agar wo branch nhi hai trie me, toh bnake fir move krna hoga
			if(!curr->left)
			{
				curr->left = new trieNode();
			}
			curr = curr->left;

		}
		else//if curr bit is 1
		{
			if(!curr->right)
			{
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}

int findMaxXorPair(trieNode* head, int* arr, int n)//query
{
	//arr stores previous elements in trie
	//n is new no which before inserting it, we'll calc the maxm xor it can form with already inserted elements
	//head pointer of our trie data structure
	int max_xor=INT_MIN;  //global xor max
	for(int i=0;i<n;i++)
	{
		//for every element, we'll check the maximum xor pair possible with this element and all previously inserted elements

		trieNode* curr=head; //har element ke liye head se start;
		int value=arr[i];

		int cur_xor=0;
		for(int j=31; j>=0; j--)
		{
			int b=(value>>j)&1; //jth bit is curr bit from ith element to be inserted in trie

			if(b==0)
			{
				if(curr->right) //1 ki taraf move
				{
					cur_xor += pow(2, j);
					curr=curr->right;
				}
				else
				{
					curr=curr->left;
				}
			}
			else //if curr bit is 1
			{
				if(curr->left) //0 ki traf move
				{
					cur_xor += pow(2, j);
					curr=curr->left;
				}
				else
				{
					curr=curr->right;
				}
			}

			
		}//endfor for bit
        if(cur_xor>max_xor)
		{
			max_xor=cur_xor;
		}


	}
    // cout<<"hello";
	return max_xor;
}

int main()
{
	int arr[6]={8,1,2,15,10,5};
	trieNode* head=new trieNode();
	for(int i=0;i<6; i++)
	{
		insert(arr[i],head);
	}
	cout<<findMaxXorPair(head,arr,6);

	return 0;
}
