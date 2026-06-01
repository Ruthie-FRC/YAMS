#include "yams/motorcontrollers/SmartMotorController.h"

namespace yams::motorcontrollers {

SmartMotorController::SmartMotorController(SmartMotorControllerConfig config) : config_(config) {}

const SmartMotorControllerConfig& SmartMotorController::GetConfig() const { return config_; }

}  // namespace yams::motorcontrollers
