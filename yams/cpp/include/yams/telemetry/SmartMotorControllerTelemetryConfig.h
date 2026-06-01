#pragma once

#include <optional>
#include <string>
#include <unordered_set>
#include <utility>

namespace yams::telemetry {

class SmartMotorControllerTelemetryConfig {
 public:
  enum class BooleanTelemetryField {
    kMechanismUpperLimit,
    kMechanismLowerLimit,
    kTemperatureLimit,
    kVelocityControl,
    kMotorInversion,
    kEncoderInversion
  };

  enum class DoubleTelemetryField {
    kSetpointPosition,
    kSetpointVelocity,
    kOutputVoltage,
    kStatorCurrent,
    kSupplyCurrent,
    kMotorTemperature,
    kMechanismPosition,
    kMechanismVelocity
  };

  SmartMotorControllerTelemetryConfig& EnableBooleanField(BooleanTelemetryField field) {
    enabledBooleanFields_.insert(field);
    return *this;
  }

  SmartMotorControllerTelemetryConfig& DisableBooleanField(BooleanTelemetryField field) {
    enabledBooleanFields_.erase(field);
    return *this;
  }

  SmartMotorControllerTelemetryConfig& EnableDoubleField(DoubleTelemetryField field) {
    enabledDoubleFields_.insert(field);
    return *this;
  }

  SmartMotorControllerTelemetryConfig& DisableDoubleField(DoubleTelemetryField field) {
    enabledDoubleFields_.erase(field);
    return *this;
  }

  SmartMotorControllerTelemetryConfig& WithNetworkTables(bool enabled) {
    networkTablesEnabled_ = enabled;
    return *this;
  }

  SmartMotorControllerTelemetryConfig& WithDataLog(std::string name) {
    dataLogName_ = std::move(name);
    return *this;
  }

  SmartMotorControllerTelemetryConfig& WithoutDataLog() {
    dataLogName_ = std::nullopt;
    return *this;
  }

  [[nodiscard]] bool IsEnabled(BooleanTelemetryField field) const {
    return enabledBooleanFields_.find(field) != enabledBooleanFields_.end();
  }

  [[nodiscard]] bool IsEnabled(DoubleTelemetryField field) const {
    return enabledDoubleFields_.find(field) != enabledDoubleFields_.end();
  }

  [[nodiscard]] bool GetNetworkTablesEnabled() const { return networkTablesEnabled_; }
  [[nodiscard]] const std::optional<std::string>& GetDataLogName() const { return dataLogName_; }
  [[nodiscard]] const std::unordered_set<BooleanTelemetryField>& GetEnabledBooleanFields() const {
    return enabledBooleanFields_;
  }
  [[nodiscard]] const std::unordered_set<DoubleTelemetryField>& GetEnabledDoubleFields() const {
    return enabledDoubleFields_;
  }

 private:
  bool networkTablesEnabled_ = true;
  std::optional<std::string> dataLogName_ = std::nullopt;
  std::unordered_set<BooleanTelemetryField> enabledBooleanFields_;
  std::unordered_set<DoubleTelemetryField> enabledDoubleFields_;
};

}  // namespace yams::telemetry
