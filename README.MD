# abstract_data

A C++98 reimplementation of several STL containers, in the `ft` namespace.

The goal is to match the behavior and interface of the standard containers while respecting the project's constraints. Work in progress.

## Status

| Component        | Implementation | Tests | Performance |
|------------------|----------------|-------|-------------|
| `vector`         | done           | done  | done        |
| `list`           | done           | done  | todo        |
| `deque`          | done           | todo  | todo        |
| `map`            | -              | -     | -           |
| `set`            | -              | -     | -           |
| `multimap`       | -              | -     | -           |
| `multiset`       | -              | -     | -           |
| `stack`          | done           | done  | done        |
| `queue`          | done           | done  | todo        |
| `priority_queue` | done           | todo  | todo        |
| Iterators        | done           | done  | /           |

## Constraints

The code is written in C++98 and follows the project's rules.

Use of `std` is limited to:

- `std::allocator`
- `std::string`
- `std::numeric_limits`
- the standard iterator tags, which are redefined in the `ft` namespace as typedefs of the `std` ones

## Structure

```text
include/       container implementations
srcs/          test and benchmark sources
test_include/  headers used by the tests
```

Each component with a standard library counterpart has its own header:

```text
std::vector     ->  include/vector.hpp
std::list       ->  include/list.hpp
std::exception  ->  include/exception.hpp
...
```

## Build and run

The same test sources are compiled twice: once against `ft` containers and once against `std` ones (with `-D STD`). This produces two binaries:

- `abstract_data` (`ft` containers)
- `abstract_data_std` (`std` containers)

Both binaries are compiled with `-Wall -Wextra -Werror -pedantic -std=c++98`, plus AddressSanitizer and UBSan.

```text
make              build both binaries
make ft           build and run the ft binary
make std          build and run the std binary
make diff         run both and diff their outputs
make benchmark    run both in benchmark mode and compare timings
make test         diff, then benchmark
make clean        remove object files
make fclean       remove object files and binaries
make re           fclean, then all
```

`make diff` writes the outputs to `output.ft` and `output.std`. An empty diff means `ft` and `std` behave identically on the tests.

`make benchmark` writes timings to `output.ft.time` and `output.std.time`, then compares them with `compare.awk`.

```sh
make benchmark
```

> Note: the benchmark target is a first draft. It currently uses the debug flags (`-g`, sanitizers, no optimization), so timings are only indicative. A more thorough benchmark setup is planned.
