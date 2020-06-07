//Time: O(m * n)
//Space: O(m * n)

int min(int x, int y){
    return(x > y)? y:x;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int ** dp = (int **)malloc(sizeof(int *) * gridSize);
    for(int i = 0; i < gridSize; i++){
        dp[i] = (int *)malloc(sizeof(int) * *gridColSize);
    }
    
    //base case for the first horizontal row in the grid
    //all of the points can only be reached from the left
    //Therefore, we add up all the entries on the left
    int acc = 0;
    for(int i = 0; i < *gridColSize; i++){
        acc += grid[0][i];
        dp[0][i] = acc;
    }
    
    //base case for the first vertical column
    //all of the points can only be reached from the top
    //Therefore, we add up all the entries on the top
    acc = 0;
    for(int i = 0; i < *gridSize; i++){
        acc += grid[i][0];
        dp[i][0] = acc;
    }
    
    //for all other positions, we can either reach from the top or left
    //Therefore, we compare the weight from the path on the top and from the left
    //we take the smaller one and add the weight in the current position
    //save it to the dp array
    for(int i = 1; i < gridSize; i++){
        for(int j = 1; j < *gridColSize; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    //this is the minimum path sum from the top left corner to the bottom right corner
    return dp[gridSize - 1][*gridColSize - 1];
}
