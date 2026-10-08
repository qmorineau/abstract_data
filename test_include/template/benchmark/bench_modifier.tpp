#ifndef BENCH_MODIFIER_TPP
#define BENCH_MODIFIER_TPP

template <class C>
struct bench_push_front
{
	static void run(const std::string& name)
    {
        {
            TimerAccum t(name + "::push_front() empty");
            for (int i = 0; i < 100000; ++i)
            {
                typename C::value_type value = generate_value<C>(i);
                C c;
                Accum a(t.total());
                c.push_front(value);
            }
        }
        {
            typename C::value_type value = generate_value<C>(67);
            C c;
            Timer t(name + "::push_front()");
            for (int i = 0; i < 100000; ++i)
                c.push_front(value);
        }
    }
};

template <class C>
struct bench_pop_front
{
	static void run(const std::string& name)
    {
         {
            TimerAccum t(name + "::pop_back() empty");
            for (int i = 0; i < 100000; ++i)
            {
                C c = fill_n<C>(1);
                Accum a(t.total());
                c.pop_back();
            }
        }
        {
            size_t size = 100000;
            C c = fill_n<C>(size);
            Timer t(name + "::pop_back() full");
            for (size_t i = 0; i < size; ++i)
                c.pop_front();
        }
    }
};

template <class C>
struct bench_push_back
{
	static void run(const std::string& name)
    {
        {
            TimerAccum t(name + "::push_back() empty");
            for (int i = 0; i < 100000; ++i)
            {
                typename C::value_type value = generate_value<C>(i);
                C c;
                Accum a(t.total());
                c.push_back(value);
            }
        }
        {
            typename C::value_type value = generate_value<C>(67);
            C c;
            Timer t(name + "::push_back()");
            for (int i = 0; i < 100000; ++i)
                c.push_back(value);
        }
    }
};

template <class C>
struct bench_pop_back
{
	static void run(const std::string& name)
    {
        {
            TimerAccum t(name + "::pop_back() empty");
            for (int i = 0; i < 100000; ++i)
            {
                C c = fill_n<C>(1);
                Accum a(t.total());
                c.pop_back();
            }
        }
        {
            size_t size = 100000;
            C c = fill_n<C>(size);
            Timer t(name + "::pop_back() full");
            for (size_t i = 0; i < size; ++i)
                c.pop_back();
        }
    }
};

template <class C>
struct bench_insert_value
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_insert_n_value
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_insert_it
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_erase_pos
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_erase_it
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_swap
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_clear
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
void bench_modifier(const std::string& name)
{
    RUN_BENCH_IF(has_push_front, bench_push_front, C, name);
    RUN_BENCH_IF(has_pop_front, bench_pop_front, C, name);
    RUN_BENCH_IF(has_push_back, bench_push_back, C, name);
    RUN_BENCH_IF(has_pop_back, bench_pop_back, C, name);
    RUN_BENCH_IF(has_insert, bench_insert_value, C, name);
    RUN_BENCH_IF(has_insert, bench_insert_n_value, C, name);
    RUN_BENCH_IF(has_insert, bench_insert_it, C, name);
    RUN_BENCH_IF(has_erase, bench_erase_pos, C, name);
    RUN_BENCH_IF(has_erase, bench_erase_it, C, name);
    RUN_BENCH_IF(has_swap, bench_swap, C, name);
    RUN_BENCH_IF(has_clear, bench_clear, C, name);
}

#endif