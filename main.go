package main

// #cgo LDFLAGS: -L. -lstring_collector
// #include "bridge.h"
import "C"
import "unsafe"

type GoStringCollector struct {
	ptr unsafe.Pointer
}

func New() GoStringCollector {
	var ret GoStringCollector
	ret.ptr = C.NewStringCollector()
	return ret
}

func (sc GoStringCollector) Free() {
	C.DeleteStringCollector(sc.ptr)
}

func (sc GoStringCollector) Add(s string) {
	cs := C.CString(s)
	C.StringCollector_Add(sc.ptr, cs)
	C.FreeString(cs)
}

func (sc GoStringCollector) Print() {
	C.StringCollector_Print(sc.ptr)
}

func run() {
	sc := New()
	defer sc.Free()

	sc.Add("Hello")
	sc.Print()

	sc.Add("World")
	sc.Print()
}

func main() {
	iterations := 1000000
	for i := 0; i < iterations; i++ {
		run()
	}
}
