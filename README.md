# State-Driven Irrigation Controller (STM32 Firmware)

## Overview
This project implements a **state-driven irrigation controller** using STM32 microcontroller firmware.  
The focus of this project is **embedded firmware design**, not hardware assembly or IoT dashboards.

The system monitors soil moisture, makes deterministic decisions, controls a water pump, and handles failure conditions safely — all using a **non-blocking, state-machine-based architecture**.

This project is designed to demonstrate **entry-level embedded firmware engineering skills**.

---

## Design Goals
- Pure firmware focus (no Arduino / no simulators)
- Deterministic behavior using a state machine
- Non-blocking timing (no delays)
- Safe actuator control
- Explicit error handling
- Clean modular architecture

---

## System Architecture

The firmware is organized into the following modules:

- **main.c**  
  Orchestrates system flow and state transitions.

- **system_state**  
  Defines and manages system states.

- **soil_sensor**  
  Abstracts soil moisture input (software-simulated).

- **pump_control**  
  Abstracts pump GPIO control.

- **logger**  
  Provides UART-based system logging.

- **config**  
  Centralizes all tunable parameters (timing, thresholds).

---

## State Machine

The system operates using the following states:

- **INIT**  
  System startup and initialization.

- **IDLE**  
  Waiting state between measurements.

- **MEASURING**  
  Soil moisture is read and evaluated.

- **WATERING**  
  Pump is turned ON when soil is dry.

- **COOLDOWN**  
  Pump runs for a fixed duration, then stops.

- **ERROR**  
  Entered if watering does not improve soil moisture.  
  Pump is forced OFF and system halts safely.

State transitions are time-driven and fully logged via UART.

---

## Timing Behavior

- Soil moisture is checked periodically using `HAL_GetTick()`
- Watering duration is controlled without blocking delays
- The system remains responsive at all times

---

## Error Handling

The firmware explicitly detects failure scenarios:

- If soil moisture does not increase after watering
- Pump is immediately turned OFF
- System transitions to `ERROR` state
- Error condition is logged
- No further watering occurs

This demonstrates **defensive firmware design**.

---

## Testing Approach

This project uses **software-in-the-loop testing**:

- Soil moisture input is simulated in firmware
- System behavior is verified via UART logs
- No physical hardware is required to validate logic

This approach allows deterministic testing of firmware behavior.

---

### Sensor Simulation

To validate system behavior without physical hardware, soil moisture is simulated in firmware.
Moisture increases after watering events and gradually decays during idle periods, mimicking real soil behavior.
This allows closed-loop testing of control logic using UART logs.


---

## Evolution Note

This project is a **firmware-focused reimplementation** of an earlier irrigation prototype originally explored at a conceptual level.

The current version was rebuilt from scratch on STM32 to apply:
- Proper state-machine design
- Modular firmware structure
- Real embedded timing and safety concepts

---

## Tools & Platform
- STM32 (STM32F103 series)
- STM32CubeIDE
- STM32 HAL (bare-metal)
- C language (embedded)

---

## Future Improvements
- Real ADC-based soil sensor integration
- RTOS-based scheduling
- Hardware fault detection
- Power optimization

---

## Author
Developed as an embedded firmware learning and portfolio project.
