VC=verilator
VFLAGS=-Wall --cc
VV=4.100
CFLAGS=--std=c++17 -Wall -Wpedantic

FILE=MODULENAME

tb_$(FILE): obj_dir tb_$(FILE).cpp TestBench.hpp
	g++ -I obj_dir \
		-I /usr/local/Cellar/verilator/$(VV)/share/verilator/include \
		/usr/local/Cellar/verilator/$(VV)/share/verilator/include/verilated.cpp \
		$(CFLAGS) \
		tb_$(FILE).cpp obj_dir/V$(FILE)__ALL.a \
		-o tb_$(FILE)


obj_dir: $(SOURCES)
	$(VC) $(VFLAGS) $(FILE).v
	make -j -C obj_dir/ -f V$(FILE).mk

run-sim: tb_$(FILE)
	./tb_$(FILE)

clean:
	rm -rf obj_dir
	rm tb_MODULENAME
