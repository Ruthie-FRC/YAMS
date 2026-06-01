#pragma once

#include "yams/motorcontrollers/SmartMotorController.h"

namespace yams::mechanisms {

class SmartMechanism {
 public:
  explicit SmartMechanism(motorcontrollers::SmartMotorController& motorController)
      : motorController_(motorController) {}

  virtual ~SmartMechanism() = default;

  void SetDutyCycleSetpoint(double dutyCycle) { motorController_.SetDutyCycle(dutyCycle); }
  void SetVoltageSetpoint(double volts) { motorController_.SetVoltage(volts); }
  void SetMechanismPositionSetpoint(double mechanismPosition) { motorController_.SetPosition(mechanismPosition); }
  void SetMechanismVelocitySetpoint(double mechanismVelocity) { motorController_.SetVelocity(mechanismVelocity); }

  [[nodiscard]] motorcontrollers::SmartMotorController& GetMotorController() { return motorController_; }
  [[nodiscard]] const motorcontrollers::SmartMotorController& GetMotorController() const { return motorController_; }

  virtual void UpdateTelemetry() = 0;
  virtual void SimIterate() = 0;

 protected:
  motorcontrollers::SmartMotorController& motorController_;
};

}  // namespace yams::mechanisms
