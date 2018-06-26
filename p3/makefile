.PHONY: all clean
all : f v0 v1 v2 v3 v4 gen
f:
	g++ -o p3.out p3.cpp
v0:
	g++ -o p3_v0.out p3_v0.cpp
v1:
	g++ -o p3_v1.out p3_v1.cpp
v2:
	g++ -o p3_v2.out p3_v2.cpp
v3:
	g++ -o p3_v3.out p3_v3.cpp
v4:
	g++ -o p3_v4.out p3_v4.cpp
gen :
	g++ sample_gen.cpp
clean:
	rm a.out p3_v0.out p3_v1.out p3_v2.out p3_v3.out p3_v4.out p3.out
