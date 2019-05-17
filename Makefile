

game: main.o
	g++ main.o -o game -lraylib -lglfw -lGL -lopenal -lm -pthread -ldl -lX11 

main.o: main.cpp player.h ball.h game.h blocks.h
	g++ -c main.cpp



clear:
	rm *.o game