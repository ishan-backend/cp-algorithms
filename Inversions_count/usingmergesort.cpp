            #include <bits/stdc++.h>
            using namespace std;
            #define LL long long
            
            LL merge(int a[], int l, int mid, int r, int temp[])
            {
               LL ans=0;
               int i,j,k;
               
               j=mid+1;
               /*This loops does the inversion counting*/
               for(k=l ; k<=mid ; ++k)
               {
                  while(j<=r)
                  {
                     if(a[k]>a[j])
                        j++;
                     else
                        break;
                  }
                  ans += j-(mid+1);
               }
               
               /*Standard Merge() from mergesort*/
               i = l;
               k = l;
               j = mid+1;
               
               while(i<=mid && j<=r)
               {
                  if(a[i]<a[j])
                     temp[k++] = a[i++];
                  else
                     temp[k++] = a[j++];
               }
               
               while(i<=mid)
                  temp[k++] = a[i++];
               while(j<=r)
                  temp[k++] = a[j++];
               for(k=l ; k<=r ; ++k)
                  a[k] = temp[k];
               
               return ans;   
            }
            LL mergeSort(int a[], int l, int r, int temp[])
            {
               /*Standard MergeSort(), with an added
               return value. Return the sum of inversions
               in left part, right part and then the 
               inversions that occur while merging them*/
               
               if(l==r)
                  return 0;
               int mid = (l+r)/2;
               LL lc,rc,mc;
               lc = mergeSort(a,l,mid,temp);
               rc = mergeSort(a,mid+1,r,temp);
               mc = merge(a,l,mid,r,temp);
               
               return lc+mc+rc;
            }
            
            int main() 
            {
               std::ios::sync_with_stdio(false);
               
               int t,n;
               cin>>t;
               while(t--)
               {
                  cin>>n;
                  int arr[n],temp[n];
                  for(int i=0;i<n;++i)
                     cin>>arr[i];
                  LL ans = mergeSort(arr,0,n-1,temp);
                  cout<<ans<<"\n";
               }
               return 0;
            }  
