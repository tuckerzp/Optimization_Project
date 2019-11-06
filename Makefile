# build memset and tests
memset: memset.c memset_test.c
	gcc -g memset.c memset_test.c -o memset

memset_perf: memset.c main.c
	gcc -g memset.c main.c -o memset_perf

memset_perf2: memset.c main.c
	gcc -g -O2 memset main.c -o memset_perf

clean:
	$(RM) memset
