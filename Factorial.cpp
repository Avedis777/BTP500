unsigned int factorial (unsigned int n){
	int sum = 1;
	while (n > 1)
		sum *= (n--);
	return (sum);
}