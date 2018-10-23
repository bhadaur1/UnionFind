#pragma once

#include <string>
#include <vector>
#include <stdexcept>

/* *****************************************************************************
 *  Name: Ravi Bhadauria
 *  Date: 10/21/2018
 *  Description: Percolation driver for Algorithms course
 **************************************************************************** */

using edu::princeton::cs::algs4::WeightedQuickUnionUF;

class Percolation
{

private:
	std::vector<std::vector<int>> grid;
	int nOpen = 0;
	WeightedQuickUnionUF *objWQF;

public:
	virtual ~Percolation()
	{
		delete objWQF;
	}

	Percolation(int n); // create n-by-n grid, with all sites blocked

	virtual void open(int row, int col); // open site (row, col) if it is not open already

	virtual bool isOpen(int row, int col); // is site (row, col) open?

	virtual bool isFull(int row, int col); // is site (row, col) full?

	virtual int numberOfOpenSites(); // number of open sites

	virtual bool percolates(); // does the system percolate?

	static void main(std::vector<std::wstring> &args);
};
