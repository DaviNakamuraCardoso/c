
EXE = sum

all: $(EXE)
	for i in 10 100 1000 10000 100000 1000000 10000000; do echo "$$i: "; ./sum $$i; done

%: %.c
	cc $^ -o $@

clean: $(EXE)
	rm -f $^
