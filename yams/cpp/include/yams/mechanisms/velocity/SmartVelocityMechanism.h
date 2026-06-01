#pragma once

#include "yams/mechanisms/SmartMechanism.h"

namespace yams::mechanisms::velocity {

class SmartVelocityMechanism : public SmartMechanism {
 public:
  explicit SmartVelocityMechanism(motorcontrollers::SmartMotorController& motorController)
      : SmartMechanism(motorController) {}

  virtual ~SmartVelocityMechanism() = default;

  [[nodiscard]] virtual bool Max() const = 0;
  [[nodiscard]] virtual bool Min() const = 0;
  virtual void RunSysId(double maximumVoltage, double stepVoltsPerSecond, double durationSeconds) = 0;
};

}  // namespace yams::mechanisms::velocity
