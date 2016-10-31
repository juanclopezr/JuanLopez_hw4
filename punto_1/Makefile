placas.pdf : grafica.py *.dat
	python grafica.py

*.dat : placas.x
	./placas.x

placas.x : placas.c
	gcc placas.c -o placas.x -lm

clean:
	rm *.dat placas.pdf placas.x
