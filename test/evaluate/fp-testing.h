#ifndef FORTRAN_TEST_EVALUATE_FP_TESTING_H_
#define FORTRAN_TEST_EVALUATE_FP_TESTING_H_

#include "../../lib/evaluate/common.h"
#include <fenv.h>

using Fortran::evaluate::RealFlags;
using Fortran::evaluate::Rounding;
using Fortran::evaluate::RoundingMode;

class ScopedHostFloatingPointEnvironment {
public:
  ScopedHostFloatingPointEnvironment(bool treatSubnormalOperandsAsZero = false,
      bool flushSubnormalResultsToZero = false);
  ~ScopedHostFloatingPointEnvironment();
  void ClearFlags() const;
  static RealFlags CurrentFlags();
  static void SetRounding(Rounding rounding);

private:
  fenv_t originalFenv_;
  fenv_t currentFenv_;
};

#endif  // FORTRAN_TEST_EVALUATE_FP_TESTING_H_
