files = test.c sortCollection.c

test: $(files)
	gcc -o $@ $^

testdebugger: $(files)
	gcc -g $^ -o $@
