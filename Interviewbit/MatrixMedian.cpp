int Solution::findMedian(vector<vector<int> > &A) 
{
    int rows = A.size();
    int cols = A[0].size();
    
    int minm = INT_MAX;
    int maxm = INT_MIN;
    
    for(int i=0;i<rows;i++)
    {
        
            minm = min( minm, A[i][0]);
            maxm = max( maxm, A[i][cols-1]);
        
    }
    //to be odd numbered median, on LHS, these many nos are required
    int required = (rows*cols + 1)/2;
    
    int lo = minm;
    int hi = maxm;
    
    while(lo < hi)
    {
        int mid = (lo+hi)/2; //guessing median as mid
        
        int count=0;
        //for each row
        for(int i=0;i<rows;i++)
        {
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
            
        }
        
        if(count < required)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid;
        }
        
    }
    
    return lo;
}
