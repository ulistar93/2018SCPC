CFLAGS = 
#CFLAGS = -std=c++11
.PHONY: all clean
all : f v0 v1 v2 v3 gen
f:
	g++ $(CFLAGS) -o p1.out p1.cpp
v0:
	g++ $(CFLAGS) -o p1_v0.out p1_v0.cpp
v1:
	g++ $(CFLAGS) -o p1_v1.out p1_v1.cpp
v2:
	g++ $(CFLAGS) -o p1_v2.out p1_v2.cpp
v3:
	g++ $(CFLAGS) -o p1_v3.out p1_v3.cpp
gen :
	g++ $(CFLAGS) sample_gen.cpp

clean:
	rm p1_v0.out p1_v1.out p1_v2.out p1_v3.out a.out p1.out
