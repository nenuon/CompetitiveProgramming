package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

var N int
var A, B, C int
var l = []int{}
var Len = map[string]int{}
var Cnt = map[string]int{}
var ans = math.MaxInt64

func main() {
	sc := NewScanner(os.Stdin)
	N = sc.NextInt()
	A = sc.NextInt()
	B = sc.NextInt()
	C = sc.NextInt()
	for i := 0; i < N; i++ {
		l = append(l, sc.NextInt())
	}
	rec(0)
	fmt.Println(ans)
}

func rec(i int) {
	if i == N {
		if Cnt["A"] == 0 || Cnt["B"] == 0 || Cnt["C"] == 0 {
			return
		}
		ans = min(ans, (Cnt["A"]-1)*10+(Cnt["B"]-1)*10+(Cnt["C"]-1)*10+abs(A-Len["A"])+abs(B-Len["B"])+abs(C-Len["C"]))
		return
	}
	for _, a := range []string{"A", "B", "C"} {
		Len[a] += l[i]
		Cnt[a]++
		rec(i + 1)
		Len[a] -= l[i]
		Cnt[a]--
	}
	// not use
	rec(i + 1)
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
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
