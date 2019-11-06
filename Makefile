# build memset and tests
memset: memset.c memset_test.c
	gcc -g memset.c memset_test.c -o memset

clean:
	$(RM) memset
