files = sortCollection.c test.c

test: $(files)
	gcc -o $@ $^

testdebugger: $(files)
	gcc -g $^ -o $@
