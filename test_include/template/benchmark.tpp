#ifndef BENCHMARK_TPP
#define BENCHMARK_TPP

template <bool Enabled, template <typename> class Bench, typename C>
struct run_if_bench
{
    static void run(const std::string& name) { Bench<C>::run(name); }
};

template <template <typename> class Bench, typename C>
struct run_if_bench<false, Bench, C>
{
    static void run() { std::cout << "(skipped)" << std::endl; }
};

#define RUN_BENCH_IF(trait, bench, C, name) \
    run_if_bench<container_traits<C>::trait, bench, C>::run(name)

#endif