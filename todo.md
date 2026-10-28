# TODO

## Container
- map
- multimap
- set
- queue
- priority queue

## Tests
### deque
- specific test deque
- verify generic test for deque if all is covered
### list
- do operations_func test
- splice test with different list and same list
### others
- use inputiterator for some test (iterator that are consume when value retrieved)

## Benchmark
### Generic
- capacity functions
- iterator functions
- operations functions
### Specific
- deque
- list
- stack
- queue

## Critical Optimization
- deque::operator=
- deque::erase(it first, it last)