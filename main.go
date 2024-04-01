package main

// #cgo LDFLAGS: -L./build/ -lstring_collector_static
// #include "bridge.hpp"
import "C"
import (
	"fmt"
	"unsafe"
)

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

func (sc GoStringCollector) Get() string {
	cs := C.StringCollector_Get(sc.ptr)
	defer C.FreeString(cs)
	return C.GoString(cs)
}

func run() {
	sc := New()
	defer sc.Free()

	sc.Add("Hello")
	sc.Print()

	sc.Add("World")
	sc.Print()

	sc.Add("!")
	var s string
	s = sc.Get()
	fmt.Printf("Got: %s\n", s)
}

func main() {
	run()
}
