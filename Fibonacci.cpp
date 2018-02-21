unsigned int fibonacci (unsigned int n){
	int a = 1;
	if (n == 0)
		return n;
	else if (n == 1)
		return n;
	else {
		int x = 0;
		int y = 1;
		int z;
		while (n-- > 1){
			z = x + y;
			x = y;
			y = z;
		}
		return y;
	}
}
