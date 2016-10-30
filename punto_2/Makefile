cuerda.gif : *.dat animacion.py
	python animacion.py

*.dat : cuerda.x
	./cuerda.x

cuerda.x : cuerda.c
	gcc cuerda.c -o cuerda.x -lm

clean :
	rm cuerda.x cuerda.gif
