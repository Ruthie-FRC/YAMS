#pragma once

namespace yams::motorcontrollers {

class SmartMotorControllerConfig {
 public:
  enum class ControlMode {
    kOpenLoop,
    kClosedLoop
  };

  enum class MotorMode {
    kCoast,
    kBrake
  };

  constexpr SmartMotorControllerConfig() = default;

  constexpr SmartMotorControllerConfig& WithControlMode(ControlMode mode) {
    controlMode_ = mode;
    return *this;
  }

  constexpr SmartMotorControllerConfig& WithMotorMode(MotorMode mode) {
    motorMode_ = mode;
    return *this;
  }

  [[nodiscard]] constexpr ControlMode GetControlMode() const { return controlMode_; }
  [[nodiscard]] constexpr MotorMode GetMotorMode() const { return motorMode_; }

 private:
  ControlMode controlMode_ = ControlMode::kOpenLoop;
  MotorMode motorMode_ = MotorMode::kCoast;
};

}  // namespace yams::motorcontrollers
