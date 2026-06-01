#pragma once

#include <memory>

#include "yams/motorcontrollers/SmartMotorControllerConfig.h"

namespace yams::motorcontrollers {

class SmartMotorController {
 public:
  explicit SmartMotorController(SmartMotorControllerConfig config);
  virtual ~SmartMotorController() = default;

  SmartMotorController(const SmartMotorController&) = delete;
  SmartMotorController& operator=(const SmartMotorController&) = delete;
  SmartMotorController(SmartMotorController&&) = delete;
  SmartMotorController& operator=(SmartMotorController&&) = delete;

  [[nodiscard]] const SmartMotorControllerConfig& GetConfig() const;

  virtual void SetVoltage(double volts) = 0;
  virtual void StopMotor() = 0;
  [[nodiscard]] virtual double GetMotorVoltage() const = 0;
  [[nodiscard]] virtual double GetMotorPosition() const = 0;
  [[nodiscard]] virtual double GetMotorVelocity() const = 0;

 protected:
  SmartMotorControllerConfig config_;
};

}  // namespace yams::motorcontrollers
