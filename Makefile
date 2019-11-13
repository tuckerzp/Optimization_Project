# build memset and tests
test: memset.c memset_test.c
	gcc -O0 --std=c99 -g memset.c memset_test.c -o memset

# Make memset as well as the driver
memset_perf0: memset.c m_main.c
	gcc --std=c99 -O0 memset.c m_main.c -o memset_perf

memset_perf1: memset.c m_main.c
	gcc --std=c99 -O1 memset.c m_main.c -o memset_perf

memset_perf2: memset.c m_main.c
	gcc --std=c99 -O2 memset.c m_main.c -o memset_perf

memset_perf3: memset.c m_main.c
	gcc --std=c99 -O3 memset.c m_main.c -o memset_perf

# Make horners as well as the driver
horners_perf0: horners.c h_main.c
	gcc --std=c99 -O0 horners.c h_main.c -o horners_perf

horners_perf1: horners.c h_main.c
	gcc --std=c99 -O1 horners.c h_main.c -o horners_perf

horners_perf2: horners.c h_main.c
	gcc --std=c99 -O2 horners.c h_main.c -o horners_perf

horners_perf3: horners.c h_main.c
	gcc --std=c99 -O3 horners.c h_main.c -o horners_perf

# Remove executables
clean:
	$(RM) memset memset_perf
