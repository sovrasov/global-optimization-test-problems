#pragma once

template <class fptype>
class IGOProblem
{
public:
  ~IGOProblem() {}

  virtual fptype Calculate(const fptype* y) = 0;
  virtual int GetOptimumPoint(fptype* y) const = 0;
  virtual fptype GetOptimumValue() const = 0 ;
  virtual int GetDimension() const = 0;
};
