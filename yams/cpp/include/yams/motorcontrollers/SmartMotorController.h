#pragma once

#include "yams/motorcontrollers/SmartMotorControllerConfig.h"

namespace yams::motorcontrollers {

class SmartMotorController {
 public:
  enum class ClosedLoopControllerSlot {
    kSlot0,
    kSlot1,
    kSlot2,
    kSlot3
  };

  explicit SmartMotorController(SmartMotorControllerConfig config);
  virtual ~SmartMotorController() = default;

  SmartMotorController(const SmartMotorController&) = delete;
  SmartMotorController& operator=(const SmartMotorController&) = delete;
  SmartMotorController(SmartMotorController&&) = delete;
  SmartMotorController& operator=(SmartMotorController&&) = delete;

  [[nodiscard]] const SmartMotorControllerConfig& GetConfig() const;
  void SetConfig(SmartMotorControllerConfig config);

  virtual bool ApplyConfig(const SmartMotorControllerConfig& config) = 0;

  virtual void StopMotor() = 0;
  virtual void SetDutyCycle(double dutyCycle) = 0;
  [[nodiscard]] virtual double GetDutyCycle() const = 0;
  virtual void SetVoltage(double volts) = 0;
  [[nodiscard]] virtual double GetMotorVoltage() const = 0;
  virtual void SetPosition(double mechanismPosition) = 0;
  virtual void SetVelocity(double mechanismVelocity) = 0;
  [[nodiscard]] virtual double GetMotorPosition() const = 0;
  [[nodiscard]] virtual double GetMotorVelocity() const = 0;
  [[nodiscard]] virtual double GetMechanismPosition() const = 0;
  [[nodiscard]] virtual double GetMechanismVelocity() const = 0;

  virtual void SetMotorInverted(bool inverted) = 0;
  virtual void SetEncoderInverted(bool inverted) = 0;

  virtual void SetClosedLoopSlot(ClosedLoopControllerSlot slot) = 0;
  [[nodiscard]] virtual ClosedLoopControllerSlot GetClosedLoopControllerSlot() const = 0;

  virtual void UpdateTelemetry() = 0;

 protected:
  SmartMotorControllerConfig config_;
};

}  // namespace yams::motorcontrollers
