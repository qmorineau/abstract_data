#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <time.h>
#include <iostream>
#include <string>

#include "container_traits.hpp"
#include "helper.hpp"

const double NS_PER_MS = 1000000.0;

class TimerAccum
{
	public:
		TimerAccum(const std::string& label, double target_ms = 10) : _iterations(0), _label(label), _total(0), _target(target_ms * NS_PER_MS)
		{}
		~TimerAccum()
		{
			std::cout << _label << ": " << _total << " nseconds; " << _iterations << " iterations" << std::endl;
		}
		void	addIterations(size_t i) {_iterations += i;};
		bool	isEnoughTime() const {return _total > _target;};
		double& total() {return _total;}
		double& operator*() {return _total;};
	private:
		size_t			_iterations;
		std::string 	_label;
		double			_total;
		const double	_target;
};

class Accum
{
	public:
		Accum(double& total) : _total(total)
		{
			clock_gettime(CLOCK_MONOTONIC, &_start);
		}
		~Accum()
		{
			struct timespec end;
			clock_gettime(CLOCK_MONOTONIC, &end);
			_total += (end.tv_sec - _start.tv_sec) * 1e9 + (end.tv_nsec - _start.tv_nsec);
		}
	private:
		double&			_total;
		struct timespec _start;
};

#include "template/benchmark/benchmark.tpp"
#include "template/benchmark/bench_common.tpp"
#include "template/benchmark/bench_element_access.tpp"
#include "template/benchmark/bench_iterators.tpp"
#include "template/benchmark/bench_modifier.tpp"
#include "template/benchmark/bench_observers.tpp"
#include "template/benchmark/bench_operations.tpp"
#include "template/benchmark/bench_capacity.tpp"
#include "template/benchmark/bench_non_member.tpp"

template <class C>
void bench_common(const std::string& name);
template <class C>
void bench_element_access(const std::string& name);
template <class C>
void bench_iterators(const std::string& name);
template <class C>
void bench_capacity(const std::string& name);
template <class C>
void bench_observers(const std::string& name);
template <class C>
void bench_operations(const std::string& name);
template <class C>
void bench_modifier(const std::string& name);
template <class C>
void bench_non_member(const std::string& name);


#endif