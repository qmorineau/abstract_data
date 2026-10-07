#ifndef BENCH_ELEMENT_ACCESS_TPP
#define BENCH_ELEMENT_ACCESS_TPP

template <class C>
struct bench_at
{
	static void run(const std::string& name)
    {
        typedef typename C::reference reference;
        typedef typename C::const_reference const_reference;
        C c = fill_n<C>(1000);
        {
            Timer t(name + "::at() &");
            for (int i = 0; i < 500; ++i)
            {
                reference ref = c.at(0);
                ref = c.at(500);
                ref = c.at(999);
                (void) ref;
            }
        }
        {
            Timer t(name + "::at() const&");
            for (int i = 0; i < 500; ++i)
            {
                const_reference ref1 = c.at(0);
                const_reference ref2 = c.at(500);
                const_reference ref3 = c.at(999);
                (void) ref1; (void) ref2; (void) ref3;
            }
        }
    }
};

template <class C>
struct bench_operator_square_bracket
{
	static void run(const std::string& name)
    {
        typedef typename C::reference reference;
        typedef typename C::const_reference const_reference;
        C c = fill_n<C>(1000);
        {
            Timer t("& " + name + "::operator[]");
            for (int i = 0; i < 500; ++i)
            {
                reference ref = c[0];
                ref = c[500];
                ref = c[999];
                (void) ref;
            }
        }
        {
            Timer t("const&" + name + "::operator[]");
            for (int i = 0; i < 500; ++i)
            {
                const_reference ref1 = c[0];
                const_reference ref2 = c[500];
                const_reference ref3 = c[999];
                (void) ref1; (void) ref2; (void) ref3;
            }
        }
    }
};

template <class C>
struct bench_front
{
	static void run(const std::string& name)
    {
        typedef typename C::reference reference;
        typedef typename C::const_reference const_reference;
        C c = fill_n<C>(10000);
        {
            Timer t("& " + name + "::front()");
            for (int i = 0; i < 1000; ++i)
            {
                reference ref = c.front();
                (void) ref;
            }
        }
        {
            Timer t("const& " + name + "::front()");
            for (int i = 0; i < 1000; ++i)
            {
                const_reference ref = c.front();
                (void) ref;
            }
        }
    }
};

template <class C>
struct bench_back
{
	static void run(const std::string& name)
    {
        typedef typename C::reference reference;
        typedef typename C::const_reference const_reference;
        C c = fill_n<C>(10000);
        {
            Timer t("& " + name + "::back()");
            for (int i = 0; i < 1000; ++i)
            {
                reference ref = c.back();
                (void) ref;
            }
        }
        {
            Timer t("const& " + name + "::back()");
            for (int i = 0; i < 1000; ++i)
            {
                const_reference ref = c.back();
                (void) ref;
            }
        }
    }
};

template <class C>
struct bench_data
{
	static void run(const std::string& name)
    {
        typedef typename C::value_type value_type;
        C c = fill_n<C>(10000);
        {
            Timer t("T* " + name + "::data()");
            for (int i = 0; i < 1000; ++i)
            {
                value_type* data = c.data();
                (void) data;
            }
        }
        {
            Timer t("const T* " + name + "::back()");
            for (int i = 0; i < 1000; ++i)
            {
                const value_type* data = c.data();
                (void) data;
            }
        }
    }
};

template <class C>
void bench_element_access(const std::string& name)
{
    RUN_BENCH_IF(has_at, bench_at, C, name);
    RUN_BENCH_IF(has_operator_square_bracket, bench_operator_square_bracket, C, name);
    RUN_BENCH_IF(has_front, bench_front, C, name);
    RUN_BENCH_IF(has_back, bench_back, C, name);
    RUN_BENCH_IF(has_data, bench_data, C, name);
}

#endif