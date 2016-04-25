all: 
	g++ -o test main.cpp SoundexTest.cpp -std=gnu++11 -lpthread -lgmock

clean:
	rm -f test *.o *.out *.exe
