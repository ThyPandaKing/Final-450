# Dynamic Programming

## Coin Change

Order does not matter, we use knapsack type logic

```C++
Cost(arr,m,n) = Cost(arr,m-1,n) + Cost(arr,m,n-S[m])

// not taking mth element and taking it

```

For bottom-up we start for each array value as we only need to take them once, finally we add that value to all higher values

```C++
for(int i=0;i<m;i++){
  for(int j=S[i];j<=n;j++){
    dp[j]+=dp[j-S[i]];
  }
}
```

## Knapsack

We decide either to take a weight or ignore it, if we take it then we must find answer from last index and for `j-wt[i]` else simply from last index `j`

```C++
Cost(wt,val,m,n) = max( Cost(wt,val,m-1,W) , Cost(wt,val,m-1,W-S[m]) + val[m] )

// not taking mth element and taking it

```

## Binomial Coefficient 

Simply use the formula

```C++
nCr = n-1Cr-1 + n-1Cr
```

now implement it using dp on 1d variable


## Matrix Chain Multiplication

```cpp
for (int len = 2; len <= n; len++) {
  for (int i = 1; i < n - len + 1; i++) {
      int j = i + len - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], 
          dp[i][k]+dp[k + 1][j]+arr[i - 1]*arr[k]*arr[j]);
      }
  }
}
```