#include <iostream>

void f(int v, int& r, int* p, int*& pr)
{
  std::cout << &v << ' ' << &r << ' ' << &p << ' ' << p << ' ' << &pr << ' ' << pr << std::endl;
  std::cout << v << ' ' << r << ' ' << *p << ' ' << *pr << std::endl;
  *pr = 1;
  *p = 2;
  r = 3;
  v = 4;
  pr = p = &v;
}

int main()
{
  int v {0};
  int& r {v};
  int* p {&v};
  int*& pr {p};
  std::cout << &v << ' ' << &r << ' ' << &p << ' ' << p << ' ' << &pr << ' ' << pr << std::endl;
  std::cout << v << ' ' << r << ' ' << *p << ' ' << *pr << std::endl;
  f(v, r, p, pr);
  std::cout << &v << ' ' << &r << ' ' << &p << ' ' << p << ' ' << &pr << ' ' << pr << std::endl;
  std::cout << v << ' ' << r << ' ' << *p << ' ' << *pr << std::endl;
  return 0;
}
