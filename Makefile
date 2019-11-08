# build memset and tests
test: memset.c memset_test.c
	gcc -O0 --std=c99 -g memset.c memset_test.c -o memset

# Make memset as well as the driver
memset_perf0: memset.c main.c
	gcc --std=c99 -O0 memset.c main.c -o memset_perf

memset_perf1: memset.c main.c
	gcc --std=c99 -O1 memset.c main.c -o memset_perf

memset_perf2: memset.c main.c
	gcc --std=c99 -O2 memset.c main.c -o memset_perf

memset_perf3: memset.c main.c
	gcc --std=c99 -O3 memset.c main.c -o memset_perf

# Remove executables
clean:
	$(RM) memset memset_perf
