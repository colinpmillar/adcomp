// Demonstrate how to pass objects back to R using the REPORT macro
#include <TMB.hpp>
template<class Type>
Type objective_function<Type>::operator() ()
{
  DATA_VECTOR        (a);
  DATA_ARRAY         (b);
  DATA_MATRIX        (c);
  DATA_SPARSE_MATRIX (d);
  PARAMETER          (p);

  // cout is supported (but not recommended)
  std::cout << a << "\n";
  std::cout << b << "\n";
  std::cout << c << "\n";
  std::cout << d << "\n";
  std::cout << p << "\n";

  // Report objects back to R:
  REPORT(a);
  REPORT(b);
  REPORT(c);
  REPORT(d);
  REPORT(p);

  //// Vector of anything:
  vector<matrix<Type> > voa(2);
  voa[0] = c;
  voa[1] = c;
  REPORT(voa);

  return 0;
}
