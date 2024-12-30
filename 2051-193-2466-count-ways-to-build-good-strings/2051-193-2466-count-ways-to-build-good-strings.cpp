class Solution {
    int dp[100001];
    int MOD = 1000000007;

    int countWays(int &low,int &high,int &zero,int &one,int pos){
        if(pos>high)    return 0;
        if(dp[pos]!=-1) return dp[pos];

        int count = 0;  
        if(pos>=low)    count++;    
        count += countWays(low,high,zero,one,pos+zero);
        count += countWays(low,high,zero,one,pos+one); 

        return dp[pos] = count % MOD;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return countWays(low,high,zero,one,0);
    }
};