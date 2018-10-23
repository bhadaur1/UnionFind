#include "PercolationStats.h"
#include "Percolation.h"

using edu::princeton::cs::algs4::StdRandom;
using edu::princeton::cs::algs4::StdStats;

PercolationStats::PercolationStats(int n, int trials)
{
	if (n < 1 || trials < 1)
	{
		throw std::invalid_argument("grid and trials should be at least 1.");
	}
	else
	{
		ratio = std::vector<double>(trials);
		for (int t = 0; t < trials; t++)
		{
			Percolation *perObj = new Percolation(n);
			while (!perObj->percolates())
			{
				perObj->open(StdRandom::uniform(1, n + 1), StdRandom::uniform(1, n + 1));
			}
			ratio[t] = static_cast<double>(perObj->numberOfOpenSites()) / static_cast<double>(n * n);
		}
	}
}

double PercolationStats::mean()
{
	return StdStats::mean(ratio);
}

double PercolationStats::stddev()
{
	return StdStats::stddev(ratio);
}

double PercolationStats::confidenceLo()
{
	return (mean() - 1.96 * stddev() / std::sqrt(ratio.size()));
}

double PercolationStats::confidenceHi()
{
	return (mean() + 1.96 * stddev() / std::sqrt(ratio.size()));
}

void PercolationStats::main(std::vector<std::wstring> &args)
{
	PercolationStats *PP = new PercolationStats(std::stoi(args[0]), std::stoi(args[1]));
	printf(L"mean                    = %f\n", PP->mean());
	printf(L"stddev                  = %f\n", PP->stddev());
	printf(L"95%% confidence interval = [%f,%f]\n", PP->confidenceLo(), PP->confidenceHi());
}
