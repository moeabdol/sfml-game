game: main.o game.o
	g++ main.o game.o -o game -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-window -lsfml-system -lsfml-graphics -lsfml-network -lsfml-audio

main.o: main.cpp game.cpp
	g++ -c main.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include

game.o: main.cpp game.cpp
	g++ -c game.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include

delete:
	rm -rf main.o game.o game
