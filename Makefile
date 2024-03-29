.PHONY: clean

TARGET=cpp-from-go2

$(TARGET): libstring_collector.a
	go build .

libstring_collector.a: string_collector.o bridge.o
	ar r $@ $^

%.o: %.cpp
	g++ -O2 -o $@ -c $^

clean:
	rm -f *.o *.so *.a $(TARGET)