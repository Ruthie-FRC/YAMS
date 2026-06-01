#pragma once

namespace yams::mechanisms {

class SmartMechanism {
 public:
  virtual ~SmartMechanism() = default;
  virtual void UpdateTelemetry() = 0;
  virtual void SimIterate() = 0;
};

}  // namespace yams::mechanisms
