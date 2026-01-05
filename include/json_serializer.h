#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include <stddef.h>
#include "meter_data.h"

typedef enum {
    JSON_OK = 0,
    JSON_ERR_BUFFER_TOO_SMALL,
    JSON_ERR_INVALID_INPUT
} json_status_t;

json_status_t serialize_to_json(
    const gateway_data_t *input,
    char *output,
    size_t output_size,
    size_t *bytes_written
);

#endif
