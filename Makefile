
bin/pong : src/main.cpp include/*.hpp
	 c++ src/main.cpp -o bin/pong -I include -lcurses

run:bin/pong
	./bin/pong