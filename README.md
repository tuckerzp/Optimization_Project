# JMU CS 261 Honors Option: Optimization Project

## Set up

1. Clone the repository
2. Run `./setup.sh` to set up the testing framework.

### Testing Performance:

Enter one of the `memset`, `poly`, or `psum` folders. Run `make test` to run the
testing framework. The pattern for the make targets for performance tests is
*program*_perf*optimization level*. For example, `memset_perf2` will run the memset program and the performance test program with optimization flag `-O2` **Remember to edit the driver file before running performance tests.** Simply uncomment the function that needs to be called.

### For the JMU Cluster

* Put `srun` before your normal commands to avoid running things on the login node.
