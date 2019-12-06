PT_ARGS = -p ./horners_perf -r 200 -s cycles -n -b 50000 -m 7500 -l 200000
CFLAGS = --std=c99 -g
CC = gcc

# Build test
test: horners.c horners_test.c
	$(CC) -O0 $(CFLAGS) horners.c horners_test.c -o test
	./test

# Make performance drivers
horners_perf0: horners.c h_main.c
	$(CC) -O0 $(CFLAGS) horners.c h_main.c -o horners_perf
	../pt $(PT_ARGS)

horners_perf1: horners.c h_main.c
	$(CC) -O1 $(CFLAGS) horners.c h_main.c -o horners_perf
	../pt $(PT_ARGS)

horners_perf2: horners.c h_main.c
	$(CC) -O2 $(CFLAGS) horners.c h_main.c -o horners_perf
	../pt $(PT_ARGS)

horners_perf3: horners.c h_main.c
	$(CC) -O3 $(CFLAGS) horners.c h_main.c -o horners_perf
	../pt $(PT_ARGS)

horners_perf_all:
	make test
	make horners_perf0
	make horners_perf1
	make horners_perf2
	make horners_perf3

# Remove executables
clean:
	$(RM) test horners_perf

