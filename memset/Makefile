PT_ARGS = -p ./memset_perf -r 200 -s cycles -n -b 100000 -m 50000 -l 1000000
CFLAGS = --std=c99 -g
CC = gcc

# Build test
test: memset.c memset_test.c
	$(CC) -O0 $(CFLAGS) memset.c memset_test.c -o test
	./test

# Make performance drivers
memset_perf0: memset.c m_main.c
	$(CC) -O0 $(CFLAGS) memset.c m_main.c -o memset_perf
	../pt $(PT_ARGS)

memset_perf1: memset.c m_main.c
	$(CC) -O1 $(CFLAGS) memset.c m_main.c -o memset_perf
	../pt $(PT_ARGS)

memset_perf2: memset.c m_main.c
	$(CC) -O2 $(CFLAGS) memset.c m_main.c -o memset_perf
	../pt $(PT_ARGS)

memset_perf3: memset.c m_main.c
	$(CC) -O3 $(CFLAGS) memset.c m_main.c -o memset_perf
	../pt $(PT_ARGS)

memset_perf_all:
	make test
	make memset_perf0
	make memset_perf1
	make memset_perf2
	make memset_perf3

# Remove executables
clean:
	$(RM) test memset_perf

