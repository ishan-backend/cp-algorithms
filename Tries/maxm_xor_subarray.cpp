#include <bits/stdc++.h>
using namespace std;

class trieNode{
      public:
        trieNode *left;
        trieNode *right;
};

void insert(int n, trieNode* head){
	trieNode* curr = head;
	for(int i=31;i>=0;i--){
		int b = (n>>i)&1;

		if(b==0){
			if(!curr->left)
				curr->left = new trieNode();
			curr = curr->left;
		}
		else{
			if(!curr->right)
				curr->right = new trieNode();
			curr = curr->right;
		}
	}
}

int maxXorarray(trieNode* head, int* arr, int n){
	int max_xor = INT_MIN;
	for(int i=0;i<n;i++){
		trieNode* curr = head;
		int value = arr[i];
		int curr_xor = 0;
		for(int j=31;j>=0;j--){
			int b = (value>>j)&1;

			if(b==0){
				if(curr->right){
					curr_xor += pow(2,j);
					curr=curr->right;
				}
				else
					curr = curr->left;
			}
			else{
				if(curr->left){
					curr_xor += pow(2,j);
					curr=curr->left;
				}
				else
					curr=curr->right;
			}
		}
		if(curr_xor > max_xor)
			max_xor = curr_xor;
	}
	return max_xor;
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    trieNode *head = new trieNode();
    insert(0, head);
    int result = INT_MIN;
    int pre_xor=0;
    for(int i=0;i<n;i++){
        pre_xor = pre_xor ^arr[i];
        insert(pre_xor, head);
        result = max(result, maxXorarray(head, arr, pre_xor));
    }
    cout<< result;
    return 0;
}
