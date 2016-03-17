#include <TMB.hpp>

template <class Type>
Type objective_function<Type>::operator()() {
  PARAMETER_MATRIX(x);
  PARAMETER_MATRIX(K);

  matrix<Type> y = atomic::convol2d(x, K);
  REPORT(y);
  return y.array().exp().sum();
}
