package main

// #cgo LDFLAGS: -L. -lbridge
// #include "bridge.h"
import "C"
import "unsafe"

type StringCollector struct {
	ptr unsafe.Pointer
}

func NewStringCollector() StringCollector {
	return StringCollector{
		ptr: C.NewStringCollector(),
	}
}

func (sc StringCollector) DeleteStringCollector() {
	C.DeleteStringCollector(sc.ptr)
}

func (sc StringCollector) AddString(s string) {
	cs := C.CString(s)
	C.StringCollector_Add(sc.ptr, cs)
	C.FreeString(cs)
}

func (sc StringCollector) StringCollector_Print() {
	C.StringCollector_Print(sc.ptr)
}

func run() {
	sc := NewStringCollector()
	defer sc.DeleteStringCollector()

	sc.AddString("Hello")
	sc.StringCollector_Print()

	sc.AddString("World")
	sc.StringCollector_Print()

}

func main() {
	iterations := 1000000
	for i := 0; i < iterations; i++ {
		run()
	}
}
