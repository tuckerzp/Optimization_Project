PT_ARGS = -p ./psum_perf -r 200 -s cycles -b 50000 -m 7500 -l 200000
CFLAGS = --std=c99 -g
CC = gcc

# Build test
test: psum.c psum_test.c
	$(CC) -O0 $(CFLAGS) psum.c psum_test.c -o test
	./test

# Make performance drivers
psum_perf0: psum.c p_main.c
	$(CC) -O0 $(CFLAGS) psum.c p_main.c -o psum_perf
	../pt $(PT_ARGS) -n

psum_perf1: psum.c p_main.c
	$(CC) -O1 $(CFLAGS) psum.c p_main.c -o psum_perf
	../pt $(PT_ARGS)

psum_perf2: psum.c p_main.c
	$(CC) -O2 $(CFLAGS) psum.c p_main.c -o psum_perf
	../pt $(PT_ARGS)

psum_perf3: psum.c p_main.c
	$(CC) -O3 $(CFLAGS) psum.c p_main.c -o psum_perf
	../pt $(PT_ARGS)

psum_perf_all:
	make test
	make psum_perf0
	make psum_perf1
	make psum_perf2
	make psum_perf3

# Remove executables
clean:
	$(RM) test psum_perf

