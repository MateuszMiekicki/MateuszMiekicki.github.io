#include <algorithm>
#include <execution>
#include <numeric>
#include <execution>

auto accumulate(const std::vector<long double> &vec)
{
    return std::accumulate(vec.cbegin(), vec.cend(), 0.0);
}

auto reduce(const std::vector<long double> &vec)
{
    return std::reduce(vec.begin(), vec.end(), 0.0);
}

auto reduce_parallel_unsequenced_policy(const std::vector<long double> &vec)
{
    return std::reduce(std::execution::par_unseq, vec.begin(), vec.end(), 0.0);
}

auto reduce_parallel_policy(const std::vector<long double> &vec)
{
    return std::reduce(std::execution::par, vec.begin(), vec.end(), 0.0);
}

auto reduce_sequenced_policy(const std::vector<long double> &vec)
{
    return std::reduce(std::execution::seq, vec.begin(), vec.end(), 0.0);
}