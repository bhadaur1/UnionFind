#pragma once

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
	std::vector<double> ratio;

public:
	PercolationStats(int n, int trials); // perform trials independent experiments on an n-by-n grid

	virtual double mean(); // sample mean of percolation threshold

	virtual double stddev(); // sample standard deviation of percolation threshold

	virtual double confidenceLo(); // low  endpoint of 95% confidence interval

	virtual double confidenceHi(); // high endpoint of 95% confidence interval

	static void main(std::vector<std::wstring> &args);
};
