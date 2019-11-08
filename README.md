# JMU CS 261 Honors Option: Optimization Project

## Set up

1. Clone the repository
2. Run `git submodule init && git submodule update` to add the testing framework

### For memset:

1. If you want to test any of the versions of memset, edit `memset_test.c`
to call the specific version of memset that you wish to test. Then,
run `make test` and `./memset` to run the tests.

2. If you want to run performance tests, edit `main.c` and call the version
of memset that you want to test. Then, run `make memset_perf(0|1|2|3)` based
on which gcc optimization level you'd like to use. Then use the provided `pt`
script. For example, `./pt -p ./memset_perf0 -r 100 -s cycles` will run 
`memset_perf0` 100 times with 18 different input sizes, printing the minimum
number of cycles for each input size.

### For the JMU Cluster

* Put `srun` before your normal `pt` commands to avoid running things on the
login node.
