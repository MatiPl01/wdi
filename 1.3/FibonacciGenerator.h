/**
 * Fibonacci numbers generator class
 */

template <typename Type> 
class FibonacciGenerator 
{
private:
	Type f0;
	Type f1;

public:
	FibonacciGenerator()
	{
		f0 = 1;
		f1 = 1;
	}

	FibonacciGenerator(Type a, Type b)
	{
		f0 = a;
		f1 = b;
	}

	Type next()
	{
		Type tmp = f0 + f1;
		f0 = f1;
		f1 = tmp;
		return tmp;
	}
};