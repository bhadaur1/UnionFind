#include "Percolation.h"

Percolation::Percolation(int n)
{
	if (n > 0)
	{
		// grid array automatically initialized to zeros
		grid = RectangularVectors::ReturnRectangularIntVector(n + 1, n + 1); // (n+1) due to not dealing with zero indices
		nOpen = 0; // no open sites to begin with
		objWQF = new QuickUnionUF((n + 1) * (n + 1));
		// Virtual site [0][0] reserved for top,  [0][1] reserved for bottom
		for (int col = 1; col < grid.size(); col++)
		{
			objWQF->Union(0, grid.size() + col);
			objWQF->Union(1, grid.size() * (grid.size() - 1) + col);
		}
	}
	else
	{
		throw std::invalid_argument("Cannot create grid with n<=0.");
	}
}

void Percolation::open(int row, int col)
{
	if (row < 1 || col < 1 || row > (grid.size() - 1) || col > (grid.size() - 1))
	{
		throw std::invalid_argument("Row or Columns cannot be less than 1, or greater than N.");
	}
	else
	{
		if (!isOpen(row, col))
		{
			int sId = grid.size() * row + col;
			int lId = sId - 1;
			int rId = sId + 1;
			int tId = sId + grid.size();
			int bId = sId - grid.size();

			grid[row][col] = 1;
			nOpen = nOpen + 1;

			if ((col < grid.size() - 1) && isOpen(row, col + 1)) // right neighbor
			{
				objWQF->Union(sId, rId);
			}

			if ((col > 1) && isOpen(row, col - 1)) // left neighbor
			{
				objWQF->Union(sId, lId);
			}

			if ((row < grid.size() - 1) && isOpen(row + 1, col)) // top neighbor
			{
				objWQF->Union(sId, tId);
			}

			if ((row > 1) && isOpen(row - 1, col)) // bot neighbor
			{
				objWQF->Union(sId, bId);
			}
		}
	}
}

bool Percolation::isOpen(int row, int col)
{
	if (row < 1 || col < 1 || row > (grid.size() - 1) || col > (grid.size() - 1))
	{
		throw std::invalid_argument("Row or Columns cannot be less than 1, or greater than N.");
	}
	else
	{
		return (grid[row][col] == 1);
	}
}

bool Percolation::isFull(int row, int col)
{
	if (row < 1 || col < 1 || row > (grid.size() - 1) || col > (grid.size() - 1))
	{
		throw std::invalid_argument("Row or Columns cannot be less than 1, or greater than N.");
	}
	else
	{
		return (isOpen(row, col) && objWQF->IsConnected(0, grid.size() * row + col));
	}
}

int Percolation::numberOfOpenSites()
{
	return nOpen;
}

bool Percolation::percolates()
{
	return (objWQF->IsConnected(0, 1));
}
