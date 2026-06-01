#pragma once

#include "yams/mechanisms/SmartMechanism.h"

namespace yams::mechanisms::positional {

class SmartPositionalMechanism : public SmartMechanism {
 public:
  explicit SmartPositionalMechanism(motorcontrollers::SmartMotorController& motorController)
      : SmartMechanism(motorController) {}

  virtual ~SmartPositionalMechanism() = default;

  [[nodiscard]] virtual bool Max() const = 0;
  [[nodiscard]] virtual bool Min() const = 0;
  virtual void RunSysId(double maximumVoltage, double stepVoltsPerSecond, double durationSeconds) = 0;
};

}  // namespace yams::mechanisms::positional
