#include "yams/motorcontrollers/SmartMotorController.h"

#include <utility>

namespace yams::motorcontrollers {

SmartMotorController::SmartMotorController(SmartMotorControllerConfig config) : config_(std::move(config)) {}

const SmartMotorControllerConfig& SmartMotorController::GetConfig() const { return config_; }

void SmartMotorController::SetConfig(SmartMotorControllerConfig config) { config_ = std::move(config); }

}  // namespace yams::motorcontrollers
