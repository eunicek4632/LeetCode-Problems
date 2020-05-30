//Time: O(m + n)
//Space: O(1)

int factorial(int x){
    int fact = 1;
    for(int i = 2; i <= x; i++){
        fact *= i;
    }
    return fact;
}

int uniquePaths(int m, int n){
//The solution can be expressed in a formula
//((m - 1) + (n - 1)) C (n - 1) or ((m - 1) + (n - 1)) C (m - 1)
//Explanation
//The total lenght of paths is (m + 1) + (n - 1) grid lines
//(m - 1) is horizontal distance and (n - 1) is the vertical distance
//from the total length, we have to choose (m - 1) units to be horizontal
    return factorial(m + n - 2) / (factorial(m - 1) * factorial(n - 1));
}
