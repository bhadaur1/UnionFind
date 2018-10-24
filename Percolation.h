#include <string>
#include <vector>
#include <stdexcept>
#include "QuickUnion.h"

/* *****************************************************************************
 *  Name: Ravi Bhadauria
 *  Date: 10/21/2018
 *  Description: Percolation driver for Algorithms course
 **************************************************************************** */

class Percolation
{

private:
	std::vector<std::vector<int>> grid;
	int nOpen = 0;
	QuickUnionUF *objWQF;

public:
	~Percolation()
	{
		delete objWQF;
	}

	Percolation(int n); // create n-by-n grid, with all sites blocked

	void open(int row, int col); // open site (row, col) if it is not open already

	bool isOpen(int row, int col); // is site (row, col) open?

	bool isFull(int row, int col); // is site (row, col) full?

	int numberOfOpenSites(); // number of open sites

	bool percolates(); // does the system percolate?
};
