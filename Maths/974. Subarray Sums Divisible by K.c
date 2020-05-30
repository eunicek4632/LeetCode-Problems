//Time: O(n)
//Space: O(K)

int subarraysDivByK(int* A, int ASize, int K){
    int count = 0;
    //to hold the frequency of all possible remainders when divided by K
    int arr[K];
    int sum = 0;
    int temp;

    for(int i = 0; i < K; i++){
        arr[i] = 0;
    }

    for(int i = 0; i < ASize; i++){
        sum += A[i];
        temp = sum % K;
        //if the remainder is smaller than 0, we convert it to a positive number
        if(temp < 0){
            temp += K;
        }
        arr[temp]++;
    }
    /*
    if the sum of entries from index 0 to i has the same remainder as the sum of entries
    from 0 to j when divided by K, the sum of entries from i to j is divisible by K
    eg. array = [1, 4, 5, 7, 9], K = 4, take i = 0 and j = 3, the sum from i to j is 16
    which is divisible by 4.

    ** You can try to prive this with modular arithmetic
    */

    for(int i = 0; i < K; i++){
        if(arr[i] >= 2){
            //choose any two ends of the same remainder sequence
            //simplify nC2 and get the formula below
            count += (arr[i] * (arr[i] - 1)) / 2;
        }
    }
    //arr[0] means the element itself is divisible by K so we add it to the count
return count + arr[0];
//those can be divisible by K can form a sequence on their own
}
