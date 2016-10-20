wave.pdf : wave.dat wave.py
	python wave.py wave.dat

wave.dat : wave.x
	./wave.x > wave.dat

wave.x : wave.c
	gcc wave.c -o wave.x -lm
