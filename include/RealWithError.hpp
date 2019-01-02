#ifndef REALWITHERROR_CAOBO1994_HPP
#define REALWITHERROR_CAOBO1994_HPP

#include <utility>

#define RT return *this;
#define SELF decltype(*this)&
#define SELFV decltype(*this)
#define SELFC const decltype(*this)&
#define SELFCV const decltype(*this)

template <class REAL>
class RealWithError
{
  REAL value;
  REAL relative_error;

  RealWithError(const REAL& value_in, const REAL& relative_error_in) throw()
  {
    value = value_in;
    relative_error = abs(relative_error_in);
  }
  RealWithError(const std::pair<REAL, REAL>& values_in) throw()
  {
    value = values_in.first;
    relative_error = abs(relative_error_in.second);
  }

  operator std::pair<REAL, REAL>() const throw()
  {
    return std::make_pair(value, relative_error);
  }
  operator REAL() const throw()
  {
    return value;
  }

  REAL get_abs_error() const throw()
  {
    return value * relative_error;
  }

  SELF set_abs_error(const REAL& abs_error_in)
  {
    relative_error = abs(abs_error/value);
    RT
  }

  SELF set_abs_error(const REAL& value_in, const REAL& abs_error)
  {
    value = value_in;
    set_abs_error(abs_error);
    RT
  }

  SELF set_abs_error(const std::pair<REAL, REAL>& values_in)
  {
    set_abs_error(values_in.first, values_in.second);
    RT
  }

  SELF operator+=(SELFC op2)
  {
    REAL value_new = value+op2.value;
    REAL abs_error_new = get_abs_error() + op2.get_abs_error();
    REAL relative_error_new = abs(abs_error_new/value_new);
    value = value_new;
    relative_error = relative_error_new;
    RT
  }

  SELF operator-=(SELFC op2)
  {
    REAL value_new = value-op2.value;
    REAL abs_error_new = get_abs_error() + op2.get_abs_error();
    REAL relative_error_new = abs(abs_error_new/value_new);
    value = value_new;
    relative_error = relative_error_new;
    RT
  }

  SELF operator*=(SELFC op2)
  {
    REAL value_new = value * op2.value;
    REAL abs_error_new = get_abs_error() * abs(op2.value) + op2.get_abs_error() * abs(value);
    REAL relative_error_new = abs(abs_error_new/value_new);
    value = value_new;
    relative_error = relative_error_new;
    RT
  }

  SELF operator/=(SELFC op2)
  {
    REAL value_new = value / op2.value;
    REAL abs_error_new = get_abs_error() * abs(op2.value) + op2.get_abs_error() * abs(value);
    abs_error_new /= op2.value;
    abs_error_new /= op2.value;
    REAL relative_error_new = abs(abs_error_new/value_new);
    value = value_new;
    relative_error = relative_error_new;
    RT
  }

  bool operator==(SELFC op2)
  {
    return (value == op2.value);
  }

  bool operator<(SELFC op2)
  {
    return (value < op2.value);
  }


};

#endif
