
TESTARGS := 	loop0 loop0p1 loop0p14 loop0p2 \
		sda1 sda12 sda3 nvme0n1 nvme1n1 \
		nvme1n1p1 nvme1n1p13 nvme1n1p4 \
		win95 win98 winme winxp win2000 win8 win10 winnt \
		'' a 1
CFLAGS := -O2 -pipe -Wall
CXXFLAGS := -O2 -pipe -Wall -std=c++17
BIN := alphanumsort_c alphanumsort_cpp

all:: $(BIN)

test:: $(BIN)
	./alphanumsort_c $(TESTARGS)
	./alphanumsort_cpp $(TESTARGS)

clean::
	$(RM) $(BIN)
