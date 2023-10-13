run: semaforo.cpp
	g++ semaforo.cpp -o s `pkg-config --libs --cflags gtk+-3.0 gtkmm-3.0`