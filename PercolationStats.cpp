#include "PercolationStats.h"
#include "Percolation.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/math/distributions.hpp>
#include <limits>

boost::random::mt19937 gen;

PercolationStats::PercolationStats(int n, int trials)
{
    if (n < 1 || trials < 1)
    {
        throw std::invalid_argument("grid and trials should be at least 1.");
    }
    else
    {
        boost::random::uniform_int_distribution<> dist(1, n + 1);

        m_ratio = std::vector<double>(trials);

        for (int t = 0; t < trials; t++)
        {
            Percolation *perObj = new Percolation(n);
            while (!perObj->percolates())
            {
                perObj->open(gen(dist), gen(dist));
            }
            m_ratio[t] = static_cast<double>(perObj->numberOfOpenSites()) / static_cast<double>(n * n);

            delete perObj;
        }
    }
}

double PercolationStats::mean()
{
  if (m_ratio.size() == 0)  return std::numeric_limits<double>::quiet_NaN();

  return (std::accumulate(m_ratio.begin(), m_ratio.end(), 0.0) /  m_ratio.size());
}

double PercolationStats::stddev()
{
  if (m_ratio.size() <= 1)  return std::numeric_limits<double>::quiet_NaN();

  double sq_sum = 0.0;

  std::for_each (std::begin(m_ratio), std::end(m_ratio), [&](const double d) {

    sq_sum += (d - mean()) * (d - mean());

  });

  return sqrt(sq_sum / (m_ratio.size()-1));
}

double PercolationStats::confidenceLo()
{
    return (mean() - 1.96 * stddev() / std::sqrt(m_ratio.size()));
}

double PercolationStats::confidenceHi()
{
    return (mean() + 1.96 * stddev() / std::sqrt(m_ratio.size()));
}

int main(int argc, char** argv)
{
    PercolationStats *PP = new PercolationStats(std::stoi(argv[1]), std::stoi(argv[2]));
    printf(L"mean                    = %f\n", PP->mean());
    printf(L"stddev                  = %f\n", PP->stddev());
    printf(L"95%% confidence interval = [%f,%f]\n", PP->confidenceLo(), PP->confidenceHi());
    delete  PercolationStats;
    return 0;
}
