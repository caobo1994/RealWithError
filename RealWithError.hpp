#ifndef REALWITHERROR_CAOBO1994_HPP
#define REALWITHERROR_CAOBO1994_HPP

#include <utility>

template <class REAL>
class RealWithError
{
  REAL value;
  REAL relative_error;
  RealWithError(const REAL& value_in, const REAL& relative_error_in)
  {
    value = value_in;
    relative_error = abs(relative_error_in);
  }
  RealWithError(const std::pair<REAL, REAL>& values_in)
  {
    value = values_in.first;
    relative_error = abs(relative_error_in.second);
  }
};

#endif
