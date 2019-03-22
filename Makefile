PR=2

CXXFLAGS= -Wall -g --std=c++11

SRCS=$(wildcard *.cc) 

OBJS=$(patsubst %.cc, %.o, $(SRCS))

TARF=$(shell basename "$$(pwd)")

all : p$(PR)

p$(PR) : $(OBJS)
	@echo '[7m[1m'Linking...'[0m'
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

run: p$(PR)
	@echo '[7m[1m'Executing...'[0m'
	./p$(PR)

runv: p$(PR)
	@echo '[7m[1m'Executing with valgrind...'[0m'
	@valgrind --leak-check=full ./p$(PR)

vstats: p$(PR)
	@echo '[7m[1m'Valgrind stats...'[0m'
	@valgrind --leak-check=full ./p$(PR) 2>&1 | grep "lost\|reachable" ; true

debug: p$(PR)
	@echo '[7m[1m'Debugging...'[0m'
	@gdb --tui p$(PR)

tgz: clean
	@echo '[7m[1mCreating file: $(TARF).tgz ...[0m'
	@cd ..;tar cfz $(TARF).tgz $(TARF); \
	 mv $(TARF).tgz $(TARF);cd $(TARF)

clean:
	@echo '[7m[1m'Limpiando...'[0m'
	@rm -r -f *~ p$(PR) *.o *.tgz

.PHONY: clean tgz run debug all
