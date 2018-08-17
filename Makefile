#Hamza Ilyas
#hi3zk
#3/2/18
#Makefile

CXX = clang++ $(CXXFLAGS)
DEBUG = -Wall -g
CXXFLAGS = -Wall -O2
OFILES = AVLTree.o BinarySearchTree.o TreePathTest.o
.SUFFIXES: .o .cpp

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o a.out
	@echo "Trees are fun!"

clean:
	-rm *.o *~ a.out

AVLTree.o: AVLTree.cpp AVLTree.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
TreePathTest.o: TreePathTest.cpp BinarySearchTree.h AVLTree.h



