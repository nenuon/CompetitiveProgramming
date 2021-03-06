package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func main() {
	sc := NewScanner(os.Stdin)
	N := sc.NextInt()
	M := sc.NextInt()
	v := make([]int, M)
	for i := 0; i < M; i++ {
		v[i] = sc.NextInt()
	}
	sv := sort.IntSlice(v)
	sort.Sort(sv)
	d := make([]int, M-1)
	for i := 0; i < M-1; i++ {
		d[i] = sv[i+1] - sv[i]
	}
	sd := sort.IntSlice(d)
	sort.Sort(sd)
	ans := 0
	for i := 0; i < M-N; i++ {
		ans += sd[i]
	}
	fmt.Println(ans)
}

func lcm(x, y int) int {
	x, y = max(x, y), min(x, y)
	if y == 0 {
		return x
	}
	return lcm(y, x%y)
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// scanner
type Scanner struct {
	r   *bufio.Reader
	buf []byte
	p   int
}

func NewScanner(r io.Reader) *Scanner {
	rdr := bufio.NewReaderSize(r, 1024)
	return &Scanner{r: rdr}
}

func (s *Scanner) ReadLine() {
	s.buf = make([]byte, 0)
	for {
		line, isp, err := s.r.ReadLine()
		if err != nil {
			os.Exit(1)
		}
		s.buf = append(s.buf, line...)
		if !isp {
			break
		}
	}
}

func (s *Scanner) NextInt() int {
	i, err := strconv.Atoi(s.Next())
	if err != nil {
		os.Exit(1)
	}
	return i
}

func (s *Scanner) NextFloat64() float64 {
	i, err := strconv.ParseFloat(s.Next(), 64)
	if err != nil {
		os.Exit(1)
	}
	return i
}

func (s *Scanner) Next() string {
	s.Pre()
	start := s.p
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break
		}
	}
	next := string(s.buf[start:s.p])
	s.p++
	return next
}

func (s *Scanner) Pre() {
	if s.p >= len(s.buf) {
		s.ReadLine()
		s.p = 0
	}
}
