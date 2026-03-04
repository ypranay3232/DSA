/*
    Finding The time and space complexity of a program 
    
    ex: int a = 5;
    int b = 20; 

    whats the space : its constant space O(1)
    
    ex: int arr[n]; --> space is O(n)


    1) counting : 
    print(n){
    // base case : 
    count<<c;
    // recursion logic
    print(n-1);
    }

    // Time : F(n), F(n-1) because of function call and recursion call, 
    T(n) = T1 + T1 + T(n-1) ==> (base case = k1 + count = k2,recursion = T(n-1))
    T(N) = K + T(n-1)

    // 2. Factorial : 
    fact(n){
    // base case : 
    return n* fact (n-1)
    }

    TC : T(N)= K1+k2+T(n-1)  ==> t(N) = k + t(N-1)



    // 3. To find the Time space : of 2 ^ n :  O(n)

    // 4. Check sorted: 
    here we check all values in an array so O(n-1) comparisons
*/