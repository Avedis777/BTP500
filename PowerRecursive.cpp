double powerRecursive (double base, unsigned int n){
	int sum;
	if (n == 0)
		sum = 1;
	else
		sum = base * powerRecursive(base, n - 1);
	return sum;
}