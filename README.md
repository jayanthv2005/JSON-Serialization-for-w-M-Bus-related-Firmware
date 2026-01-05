# JSON Serialization for w-M-Bus–related Firmware

1.Project Overview
This project implements an embedded-friendly software library that serializes
structured smart-meter data into a strictly predefined JSON format.

It represents a typical firmware data pipeline used in smart-meter and
w-M-Bus gateway systems:

Measurement Data → Internal C Structures → JSON Serialization → Backend Interface

2.Platform & Programming Language

- Platform: STM32 (STM32CubeIDE – target environment)
- Programming Language: C (C99)

3.Justification
C was chosen for its deterministic behavior, low memory overhead, and
suitability for embedded firmware.  
STM32 is widely used in smart-meter and gateway products.  
The code itself is platform-agnostic and can also be compiled and tested on a PC.

4.Features

- No dynamic memory allocation
- No external JSON libraries
- Caller-provided output buffer
- Transport-agnostic design
- Buffer overflow protection
- Strict compliance with the required JSON format
- 
5.Public API

```c
json_status_t serialize_to_json(
    const gateway_data_t *input,
    char *output,
    size_t output_size,
    size_t *bytes_written
);
