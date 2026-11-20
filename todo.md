# TODO

## Container
- map
- multimap
- set
- multiset

## Tests
### deque
- specific test deque
- verify generic test for deque if all is covered
### list
- do operations_func test
- splice test with different list and same list
### priority_queue
- specific test with all fonction (no operator==, will be weird to adapt generic for this)

## Benchmark
### Generic
- capacity functions (resize, reserve)
- operations functions
### Specific
- deque
- list
- stack
- queue
- priority_queue

## Critical Optimization
- deque::operator=
- deque::erase(it first, it last)