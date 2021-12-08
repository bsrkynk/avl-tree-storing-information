all:compile link run

compile:
	g++ -I./include -c ./src/AVLTree.cpp -o ./lib/AVLTree.o
	g++ -I./include -c ./src/Stack.cpp -o ./lib/Stack.o
	g++ -I./include -c ./src/StackNode.cpp -o ./lib/StackNode.o
	g++ -I./include -c ./src/TreeNode.cpp -o ./lib/TreeNode.o
	g++ -I./include -c ./src/Kisi.cpp -o ./lib/Kisi.o
	g++ -I./include -c ./src/main.cpp -o ./lib/main.o
	
link:
	g++      ./lib/AVLTree.o ./lib/Stack.o ./lib/StackNode.o ./lib/TreeNode.o ./lib/Kisi.o ./lib/main.o -o ./bin/MyProgram.exe
run:
	./bin/MyProgram