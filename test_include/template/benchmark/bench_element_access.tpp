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
		do_not_optimize(&c);
        {
            TimerAccum t(name + "::at() &");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					reference ref = c.at(0);
					do_not_optimize(&ref);
					clobber();
					ref = c.at(500);
					do_not_optimize(&ref);
					clobber();
					ref = c.at(999);
					do_not_optimize(&ref);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
        {
            TimerAccum t(name + "::at() const&");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					const_reference ref1 = c.at(0);
					do_not_optimize(&ref1);
					clobber();
					const_reference ref2 = c.at(500);
					do_not_optimize(&ref2);
					clobber();
					const_reference ref3 = c.at(999);
					do_not_optimize(&ref3);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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
		do_not_optimize(&c);
        {
            TimerAccum t("& " + name + "::operator[]");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					reference ref = c[0];
					do_not_optimize(&ref);
					clobber();
					ref = c[500];
					do_not_optimize(&ref);
					clobber();
					ref = c[999];
					do_not_optimize(&ref);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
        {
            TimerAccum t("const&" + name + "::operator[]");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					const_reference ref1 = c[0];
					do_not_optimize(&ref1);
					clobber();
					const_reference ref2 = c[500];
					do_not_optimize(&ref2);
					clobber();
					const_reference ref3 = c[999];
					do_not_optimize(&ref3);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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
		do_not_optimize(&c);
        {
            TimerAccum t("& " + name + "::front()");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					reference ref = c.front();
					do_not_optimize(&ref);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
        {
            TimerAccum t("const& " + name + "::front()");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					const_reference ref = c.front();
					do_not_optimize(&ref);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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
		do_not_optimize(&c);
        {
            TimerAccum t("& " + name + "::back()");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					reference ref = c.back();
					do_not_optimize(&ref);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
        {
            TimerAccum t("const& " + name + "::back()");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					const_reference ref = c.back();
					do_not_optimize(&ref);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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
		do_not_optimize(&c);
        {
            TimerAccum t("T* " + name + "::data()");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					value_type* data = c.data();
					do_not_optimize(data);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
        {
            TimerAccum t("const T* " + name + "::data()");
			do
			{
				size_t size = 1000;
				for (size_t i = 0; i < size; ++i)
				{
					Accum acc(*t);
					const value_type* data = c.data();
					do_not_optimize(data);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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