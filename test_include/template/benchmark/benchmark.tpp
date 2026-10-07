#ifndef BENCHMARK_TPP
#define BENCHMARK_TPP

// force compiler to consider p is used
template <typename T>
inline void do_not_optimize(const T* p)
{
    __asm__ __volatile__("" : : "r"(p) : "memory");
}
// force compiler to consider memory could've been change
inline void clobber()
{
    __asm__ __volatile__("" : : : "memory");
}
// make the container's buffer observable so the copy isn't optimized away
template <class C>
inline void touch(const C& c)
{
    typename C::const_iterator it = c.begin();
    if (it != c.end())
        do_not_optimize(&(*it));
    clobber();
}
template <class C>
inline void touch_all(const C& c)
{
    for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
        do_not_optimize(&(*it));
    clobber();
}

template <bool Enabled, template <typename> class Bench, typename C>
struct run_if_bench
{
    static void run(const std::string& name) { Bench<C>::run(name); }
};

template <template <typename> class Bench, typename C>
struct run_if_bench<false, Bench, C>
{
    static void run(const std::string& name) {(void) name;}
};

#define RUN_BENCH_IF(trait, bench, C, name) \
    run_if_bench<container_traits<C>::trait, bench, C>::run(name)

#endif
