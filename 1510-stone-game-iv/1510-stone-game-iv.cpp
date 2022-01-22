class Solution {
public:
    bool issq(int n)
    {
        if(ceil(sqrt(n))==floor(sqrt(n)))
            return true;
        
        return false;
    }
    bool winnerSquareGame(int n) {
        
        vector<int> sq;
        for(int i=1;i<=n;i++)
        {
                if(issq(i))
                sq.push_back(i);
        }
        
        bool arr[n+1];
        
        for(int i=1;i<=n;i++)
        {
            if(issq(i))
                arr[i]=true;
            else
            {
                int f=0;
                for(int j=0;j<sq.size();j++)
                {
                    if(sq[j]<=i)
                    {
                        int rem=i-sq[j];
                        if(arr[rem]==false){
                            arr[i]=true;
                            f=1;
                            break;
                        }
                    }
                    else
                        break;
                }
                if(f==0)
                    arr[i]=false;
            }
        }
        
        return arr[n];
        
    }
};