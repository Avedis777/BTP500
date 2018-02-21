unsigned int fibonacciRecursive (unsigned int n){
	int sum = 0;
	if (n == 0)
		return n;
	else if (n == 1)
		return n;
	else {
		sum += fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
		return sum;
	}
}