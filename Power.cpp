double power (double base, unsigned int n){
	double sum = 1;
	while(n-- > 0)
		sum *= base;
	return sum;
}
