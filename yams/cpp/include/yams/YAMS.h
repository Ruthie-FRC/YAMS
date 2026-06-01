#pragma once

#include <string_view>

#include "yams/mechanisms/SmartMechanism.h"
#include "yams/motorcontrollers/SmartMotorController.h"
#include "yams/motorcontrollers/SmartMotorControllerConfig.h"
#include "yams/telemetry/SmartMotorControllerTelemetry.h"
#include "yams/telemetry/SmartMotorControllerTelemetryConfig.h"

namespace yams {

inline constexpr std::string_view kName = "Yet Another Mechanism System";

}
