#include <vector>
#include <random>
#include "benchmark/benchmark.h"
#include "executionpolicy.hpp"

auto vec = std::vector<long double>(1'000, 0.5);

static void BM_accumulate(benchmark::State &state)
{
    for (auto _ : state)
    {
        accumulate(vec);
    }
}
BENCHMARK(BM_accumulate);

static void BM_reduce(benchmark::State &state)
{
    for (auto _ : state)
    {
        reduce(vec);
    }
}
BENCHMARK(BM_reduce);

static void BM_parallel_unsequenced_policy(benchmark::State &state)
{
    for (auto _ : state)
    {
        reduce_parallel_unsequenced_policy(vec);
    }
}
BENCHMARK(BM_parallel_unsequenced_policy);

static void BM_parallel_policy(benchmark::State &state)
{
    for (auto _ : state)
    {
        reduce_parallel_policy(vec);
    }
}
BENCHMARK(BM_parallel_policy);

static void BM_sequenced_policy(benchmark::State &state)
{
    for (auto _ : state)
    {
        reduce_sequenced_policy(vec);
    }
}
BENCHMARK(BM_sequenced_policy);
BENCHMARK_MAIN();