# JSON-Serialization-for-w-M-Bus-related-Firmware
# Embedded JSON Serialization Library

1.Overview
This project implements an embedded-friendly JSON serialization library
for smart-meter gateway data. It converts structured meter data into a
strictly defined JSON format without using any external JSON libraries.

2.Platform & Language
- Platform: STM32 (STM32CubeIDE)
- Language: C (C99)

3.Features
- No dynamic memory allocation
- Caller-provided output buffer
- Transport-agnostic design
- Strict JSON format compliance
- Robust buffer overflow protection

4.API
```c
json_status_t serialize_to_json(
    const gateway_data_t *input,
    char *output,
    size_t output_size,
    size_t *bytes_written
);
