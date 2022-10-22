CXX := g++
CXXFLAGS := -g -Wall --std=c++11
#VALGRIND := valgrind --tool=memcheck= --leak-check=yes
OBJS = llrec-test.o llrec.o 
OBJS_2 = stack_test.o
OBJS_3 = heap_test.o

all: llrec-test stack-test heap-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ $(OBJS)

stack-test: $(OBJS_2)
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ $(OBJS_2)

heap-test: $(OBJS_3)
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ $(OBJS_3)

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ -c llrec-test.cpp

llrec.o : llrec.cpp llrec.h
		$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ -c llrec.cpp




stack_test.o: stack_test.cpp stack.h
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ -c stack_test.cpp

heap_test.o: heap_test.cpp heap.h
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ -c heap_test.cpp

clean:
	rm -f *.o rh llrec-test *~ stack-test *~ heap-test *~

.PHONY: clean 