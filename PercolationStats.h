#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

/* *****************************************************************************
 *  Name: Ravi Bhadauria
 *  Date: 10/21/2018
 *  Description: Percolation statistics driver for Algorithms course
 **************************************************************************** */


class PercolationStats
{

private:
	std::vector<double> m_ratio;

public:
	PercolationStats(int n, int trials); // perform trials independent experiments on an n-by-n grid

	double mean(); // sample mean of percolation threshold

	double stddev(); // sample standard deviation of percolation threshold

	double confidenceLo(); // low  endpoint of 95% confidence interval

	double confidenceHi(); // high endpoint of 95% confidence interval
};
