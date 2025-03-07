test: mytest.cpp ${files}
	clear
	g++ mytest.cpp ${files} -o test
	./test
	rm test

memory: Memory_test.cpp ${files}
	clear
	g++ Memory_test.cpp ${files} -o memory
	./memory
	rm memory

main: main.cpp ${files}
	clear
	g++ main.cpp ${files} -o main
	./main
	rm main

files = SimulatedOS.cpp Ram.cpp Page.cpp Cpu.cpp Disk.cpp Process.cpp