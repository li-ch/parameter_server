#pragma once
#include "app/risk_minimization.h"
#include "parameter/kv_vector.h"

#include "loss/loss_factory.h"
#include "penalty/penalty_factory.h"
#include "learner/learner_factory.h"

// #include "loss/scalar_loss.h"
// #include "penalty/p_norm_penalty.h"

namespace PS {
namespace LM {

// linear classification/regerssion

class LinearMethod : public RiskMinimization {

 public:
  virtual void init();

 protected:
  void startSystem();

  LossPtr<double> loss_;
  PenaltyPtr<double> penalty_;
  shared_ptr<AggGradLearner<double>> learner_;

  // training data, available at the workers
  MatrixPtr<double> y_, X_;

  // data information, only available at the scheduler
  std::vector<MatrixInfo> global_training_info_, global_validation_info_;
  size_t global_training_example_size_ = 0;

  Range<Key> global_feature_range_;

};

} // namespace LM

} // namespace PS
