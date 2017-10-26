/**
 * Fibonacci numbers generator class
 */

class FibonacciGenerator 
{
private:
	int f0;
	int f1;

public:
	FibonacciGenerator();
	FibonacciGenerator(int a, int b);
	
	int next();
};