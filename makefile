main: main.cpp ${files}
	clear
	g++ main.cpp ${files} -o main

mem: Memory_test.cpp ${files}
	clear
	g++ Memory_test.cpp ${files} -o memory

files = SimulatedOS.cpp Ram.cpp Page.cpp Cpu.cpp Disk.cpp Process.cpp 