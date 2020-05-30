//Time: O(m * n)
//Space O(m * n)

int uniquePaths(int m, int n){
    //create a matrix which stores the number of unique paths to that point
    //dp[i][j] store the number of unique paths up to the point with coordinates (i, j)
    int ** dp = (int **)malloc(sizeof(int *) * m);
    for(int i = 0; i < m; i++){
        dp[i] = (int *)malloc(sizeof(int) * n);
    }

    //base cases
    
    //the points on the top horizontal row can only be reached from the left,
    //threfore, every point in the row have only one unique path
    for(int i = 0; i < n; i++){
        dp[0][i] = 1;
    }
    
    //the points on the leftmost vertical column can only be reached from the top,
    //threfore, every point in the column have only one unique path
    for(int i = 0; i < m; i++){
        dp[i][0] = 1;
    }
    
    //All other points can be reached by either from the left or top
    //therefore, the number of unique paths is the sum of the unique paths to
    //the top or the left point
    //eg. # of unique paths to (i, j) = # of unique paths to (i - 1, j) + 
    //# of unique paths to (i, j - 1)
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    
    //the finishing point
    return dp[m - 1][n - 1];
}
