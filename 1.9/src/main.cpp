#include <cstdio>

int calculate_sum_of_factors(int n); 

int main(void)
{
	const int N = 1000000;

	for(int candidate = 1; candidate <= N; candidate++)
	{
		int sum_of_candidates_factors = calculate_sum_of_factors(candidate);

		if(candidate > sum_of_candidates_factors)
			if(candidate == calculate_sum_of_factors(sum_of_candidates_factors))
				printf("%d %d\n", candidate, sum_of_candidates_factors);
	}

	return 0;
}

int calculate_sum_of_factors(int n)
{
	int sum = 0;

	for(int candidate_for_factor = 1; 
		candidate_for_factor <= n/2; 
		candidate_for_factor++)
	{
		if(n % candidate_for_factor == 0)
		{
			sum += candidate_for_factor;
		}
	}

	return sum;
}