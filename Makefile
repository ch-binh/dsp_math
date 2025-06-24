.PHONY: all test cli run clean clean-all

all: test-all cli

test-all:
	$(MAKE) -C test all

test:
	$(MAKE) -C test run

rm_data:
	$(MAKE) -C test rm_data

cli:
	$(MAKE) -C cli

clean:
	$(MAKE) -C test clean
	$(MAKE) -C cli clean
	rm -rf build/*

clean-all: clean
	rm -rf bin/*