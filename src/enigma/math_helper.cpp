#include "math_helper.h"

namespace WrappedMath {
int subtract(int lhs, int rhs, int mod){
  if (lhs >= rhs){
    return (lhs - rhs)%mod;
  }
  return (lhs - rhs) % mod + mod;
};
int add(int lhs, int rhs, int mod){
  return (lhs + rhs) % mod;
};
}