#pragma once

#include <vector>
#include <memory>
#include <stdexcept>
#include <limits>

#include "problem_interface.hpp"

template <class fptype>
class GOTestProblemWrapper
{
private:
  std::shared_ptr<IGOProblem<fptype>> mSourceProblem;
  mutable std::vector<int> mCalculationsCounters;
  std::vector<fptype> mOptimumPoint;
  std::vector<fptype> mLeftBound;
  std::vector<fptype> mRightBound;
  mutable bool mStopCollectStats;
  fptype mEps;
public:
  GOTestProblemWrapper(std::shared_ptr<IGOProblem<fptype>> problem, fptype eps = -1.) :
    mSourceProblem(problem), mStopCollectStats(false), mEps(eps)
  {
    mCalculationsCounters = std::vector<int>(mSourceProblem->GetConstraintsNumber() + 1);
    std::fill(mCalculationsCounters.begin(), mCalculationsCounters.end(), 0);
    mOptimumPoint.resize(mSourceProblem->GetDimension());
    mSourceProblem->GetOptimumPoint(mOptimumPoint.data());
    mLeftBound.resize(mSourceProblem->GetDimension());
    mRightBound.resize(mSourceProblem->GetDimension());
    mSourceProblem->GetBounds(mLeftBound.data(), mRightBound.data());
  }

  void SetEps(fptype eps)
  {
    mEps = eps;
  }

  fptype Calculate(const std::vector<fptype>& y, int fNumber) const
  {
    if (y.size() != static_cast<size_t>(mSourceProblem->GetDimension()))
      throw std::runtime_error("Wrong input dimension");
    fptype value = mSourceProblem->Calculate(y.data(), fNumber);
    if (!mStopCollectStats)
      mCalculationsCounters[fNumber]++;
    if (mEps > 0)
    {
      double dist = std::numeric_limits<double>::lowest();
      for (size_t i = 0; i < mOptimumPoint.size(); i++)
        dist = fmax(dist, fabs(mOptimumPoint[i] - y[i]));
      if (dist < mEps)
        mStopCollectStats = true;
    }
    return value;
  }

  int GetConstraintsNumber() const
  {
    return mSourceProblem->GetConstraintsNumber();
  }

  int GetDimension() const
  {
    return mSourceProblem->GetDimension();
  }

  std::pair<std::vector<fptype>, std::vector<fptype>> GetBounds() const
  {
    return std::make_pair(mLeftBound, mRightBound);
  }

  std::vector<fptype> GetOptimumPoint() const
  {
    return mOptimumPoint;
  }

  fptype GetOptimumValue() const
  {
    return mSourceProblem->GetOptimumValue();
  }

  std::vector<int> GetCalculationsStatistics() const
  {
    return mCalculationsCounters;
  }
};
