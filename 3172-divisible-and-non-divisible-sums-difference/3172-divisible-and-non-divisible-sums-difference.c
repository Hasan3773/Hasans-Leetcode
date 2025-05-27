int differenceOfSums(int n, int m) {
    // num1 = geometric sum of n where % m != 0
    // num2 = gemometric sum of n where % m == 0
    // return num1 - num2   

    int num_array[n+1];
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i <= n; i++){
        num_array[i] = i + 1;
        printf("%d\n", num_array[i]);
    }

    for (int i = 0; i < n; i++){
        if ((num_array[i] % m) != 0){
            num1 += num_array[i];
            printf("%d %d %s\n", num1, num_array[i], "not divisble by m");
        }
        else if((num_array[i] % m) == 0){
            num2 += num_array[i];
            printf("%d %d %s\n", num2, num_array[i], "divisible by m");
        }
        else
            printf("%s\n", "bruh");

    }
    return num1 - num2;

}