all:
	gcc -I include -L lib -o main src/main.c -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lglew32

