#pragma once

#include <string_view>

#include "yams/telemetry/SmartMotorControllerTelemetryConfig.h"

namespace yams::motorcontrollers {
class SmartMotorController;
}

namespace yams::telemetry {

class BooleanTelemetryPublisher {
 public:
  virtual ~BooleanTelemetryPublisher() = default;
  virtual void Publish(std::string_view key, bool value) = 0;
};

class DoubleTelemetryPublisher {
 public:
  virtual ~DoubleTelemetryPublisher() = default;
  virtual void Publish(std::string_view key, double value) = 0;
};

class SmartMotorControllerTelemetry {
 public:
  virtual ~SmartMotorControllerTelemetry() = default;

  virtual void SetupTelemetry(motorcontrollers::SmartMotorController& smartMotorController,
                              const SmartMotorControllerTelemetryConfig& config) = 0;
  virtual void Publish(const motorcontrollers::SmartMotorController& smartMotorController) = 0;
  virtual void ApplyTuningValues(motorcontrollers::SmartMotorController& smartMotorController) = 0;
  [[nodiscard]] virtual bool TuningEnabled() const = 0;
};

}  // namespace yams::telemetry
