unsigned int factorialRecursive (unsigned int n){
	int sum;              
    if (n == 1 || n == 0)
        sum = 1;            
    else               
        sum = n * factorial(n - 1);
    return sum;
}