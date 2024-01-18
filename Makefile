all: compile link

compile:
	g++ -Isrc/include -c sort.cpp

link:
	g++ sort.o -o sort -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system