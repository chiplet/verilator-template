VC=verilator
VFLAGS=-Wall --cc


FILE=MODULENAME

tb_$(FILE): obj_dir $(TB_SOURCES)
	g++ -I obj_dir \
		-I /usr/local/Cellar/verilator/4.038/share/verilator/include/ \
		/usr/local/Cellar/verilator/4.038/share/verilator/include/verilated.cpp \
		tb_$(FILE).cpp obj_dir/V$(FILE)__ALL.a \
		-o tb_$(FILE)


obj_dir: $(SOURCES)
	$(VC) $(VFLAGS) $(FILE).v
	Make -j -C obj_dir/ -f V$(FILE).mk

run-sim: tb_$(FILE)
	./tb_$(FILE)

clean:
	rm -rf obj_dir
	rm tb_MODULENAME
