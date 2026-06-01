#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace yams::motorcontrollers {

class SmartMotorControllerConfig {
 public:
  enum class TelemetryVerbosity {
    kLow,
    kMid,
    kHigh
  };

  enum class ControlMode {
    kOpenLoop,
    kClosedLoop
  };

  enum class MotorMode {
    kCoast,
    kBrake
  };

  SmartMotorControllerConfig() = default;

  constexpr SmartMotorControllerConfig& WithControlMode(ControlMode mode) {
    controlMode_ = mode;
    return *this;
  }

  constexpr SmartMotorControllerConfig& WithMotorMode(MotorMode mode) {
    motorMode_ = mode;
    return *this;
  }

  constexpr SmartMotorControllerConfig& WithMotorInverted(bool inverted) {
    motorInverted_ = inverted;
    return *this;
  }

  constexpr SmartMotorControllerConfig& WithEncoderInverted(bool inverted) {
    encoderInverted_ = inverted;
    return *this;
  }

  constexpr SmartMotorControllerConfig& WithStatorCurrentLimit(double amps) {
    statorCurrentLimitAmps_ = amps;
    return *this;
  }

  constexpr SmartMotorControllerConfig& WithSupplyCurrentLimit(double amps) {
    supplyCurrentLimitAmps_ = amps;
    return *this;
  }

  constexpr SmartMotorControllerConfig& WithMechanismLimits(double lower, double upper) {
    mechanismLowerLimit_ = lower;
    mechanismUpperLimit_ = upper;
    return *this;
  }

  constexpr SmartMotorControllerConfig& WithMechanismLimitsEnabled(bool enabled) {
    mechanismLimitsEnabled_ = enabled;
    return *this;
  }

  SmartMotorControllerConfig& WithTelemetry(std::string_view name, TelemetryVerbosity verbosity) {
    telemetryName_ = std::string{name};
    telemetryVerbosity_ = verbosity;
    return *this;
  }

  [[nodiscard]] constexpr ControlMode GetControlMode() const { return controlMode_; }
  [[nodiscard]] constexpr MotorMode GetMotorMode() const { return motorMode_; }
  [[nodiscard]] constexpr bool GetMotorInverted() const { return motorInverted_; }
  [[nodiscard]] constexpr bool GetEncoderInverted() const { return encoderInverted_; }
  [[nodiscard]] const std::optional<double>& GetStatorCurrentLimitAmps() const { return statorCurrentLimitAmps_; }
  [[nodiscard]] const std::optional<double>& GetSupplyCurrentLimitAmps() const { return supplyCurrentLimitAmps_; }
  [[nodiscard]] const std::optional<double>& GetMechanismLowerLimit() const { return mechanismLowerLimit_; }
  [[nodiscard]] const std::optional<double>& GetMechanismUpperLimit() const { return mechanismUpperLimit_; }
  [[nodiscard]] constexpr bool GetMechanismLimitsEnabled() const { return mechanismLimitsEnabled_; }
  [[nodiscard]] const std::optional<std::string>& GetTelemetryName() const { return telemetryName_; }
  [[nodiscard]] const std::optional<TelemetryVerbosity>& GetTelemetryVerbosity() const { return telemetryVerbosity_; }

 private:
  ControlMode controlMode_ = ControlMode::kOpenLoop;
  MotorMode motorMode_ = MotorMode::kCoast;
  bool motorInverted_ = false;
  bool encoderInverted_ = false;
  bool mechanismLimitsEnabled_ = true;
  std::optional<double> statorCurrentLimitAmps_ = std::nullopt;
  std::optional<double> supplyCurrentLimitAmps_ = std::nullopt;
  std::optional<double> mechanismLowerLimit_ = std::nullopt;
  std::optional<double> mechanismUpperLimit_ = std::nullopt;
  std::optional<std::string> telemetryName_ = std::nullopt;
  std::optional<TelemetryVerbosity> telemetryVerbosity_ = std::nullopt;
};

}  // namespace yams::motorcontrollers
