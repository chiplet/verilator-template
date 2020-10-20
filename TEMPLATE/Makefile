VC=verilator
VFLAGS=-Wall --trace --cc
CFLAGS=--std=c++17 -Wall -Wpedantic

FILE=MODULENAME

tb_$(FILE): obj_dir tb_$(FILE).cpp TestBench.hpp
	g++ -I obj_dir \
		-I /usr/share/verilator/include/ \
		/usr/share/verilator/include/verilated.cpp \
		/usr/share/verilator/include/verilated_vcd_c.cpp \
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
