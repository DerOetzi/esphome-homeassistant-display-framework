# ESPHome Home Assistant Display Framework

A small, flexible framework for building compact, informative display layouts on ESPHome-based devices using data from Home Assistant. The project provides reusable rendering components, layout primitives, and helpers that make it simple to present the state of Home Assistant entities (sensors, binary sensors, etc.) on common small displays attached to ESP32 and ESP8266 microcontrollers.

This framework focuses on the display layer: providing composable building blocks and patterns for drawing icons, labels, values and simple controls directly on devices so layouts remain local, fast, and privacy-friendly. It is intentionally lightweight and easy to adapt — designed to be copied into ESPHome YAML projects or included as a collection of helpers to reduce repetition and accelerate development of room panels, status tiles, and small dashboards.

## Key features
- Reusable rendering blocks for common entity types and UI elements
- Layout helpers for rows, columns, alignment and spacing
- Formatting utilities for units, rounding and compact value display
- Icon selection helpers and state-to-visual mapping
- Examples targeting widely-used display drivers supported by ESPHome
- Designed for offline/local rendering on ESP devices using Home Assistant API data

## Supported hardware
- Targeted at ESP32 and ESP8266 based boards
- Works with common small displays supported by ESPHome (I2C/SPI OLEDs and TFTs)
- Current primary focus: the "Cheap Yellow Display" — a low-cost yellow display module that the author commonly installs throughout the house

## Extensibility and customization
- Helpers are composable and low-level so you can mix and match primitives to build bespoke layouts
- Intended to be extended via small lambdas and C++ snippets supported by ESPHome when needed

## Contributing
- Contributions, bug reports, and layout ideas are welcome. Please open issues or submit pull requests with focused changes and a demonstration layout when possible.

## Acknowledgements
- Built to complement ESPHome and Home Assistant — thanks to both projects and their communities for enabling local, privacy-conscious home automation.