.PHONY: clean

TARGET=cpp-from-go2

$(TARGET): clean #libstring_collector.a
	go build .

# libstring_collector.a: string_collector.o bridge.o
# 	ar r $@ $^

# src/%.o: src/%.cpp
# 	g++ -O2 -o src/$@ -c src/$^

clean:
	rm -f *.o *.so *.a $(TARGET)