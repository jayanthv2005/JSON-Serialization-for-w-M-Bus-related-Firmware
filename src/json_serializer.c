#include <stdio.h>
#include "json_serializer.h"

#define CHECK_SNPRINTF(r, s) \
    if ((r) < 0 || (size_t)(r) >= (s)) return JSON_ERR_BUFFER_TOO_SMALL;

json_status_t serialize_to_json(
    const gateway_data_t *input,
    char *output,
    size_t output_size,
    size_t *bytes_written)
{
    if (!input || !output || !bytes_written)
        return JSON_ERR_INVALID_INPUT;

    size_t used = 0;
    int ret;

    ret = snprintf(output + used, output_size - used,
        "[{\"gatewayId\":\"%s\",\"date\":\"%s\",\"deviceType\":\"%s\","
        "\"interval_minutes\":%d,\"total_readings\":%d,"
        "\"values\":{\"device_count\":%d,\"readings\":[",
        input->gateway_id, input->date, input->device_type,
        input->interval_minutes, input->total_readings,
        input->device_count);
    CHECK_SNPRINTF(ret, output_size - used);
    used += ret;

    for (uint8_t i = 0; i < input->device_count; i++) {
        device_reading_t *d = &input->devices[i];

        ret = snprintf(output + used, output_size - used,
            "%s{\"media\":\"%s\",\"meter\":\"%s\",\"deviceId\":\"%s\","
            "\"unit\":\"%s\",\"data\":[",
            (i ? "," : ""), d->media, d->meter,
            d->device_id, d->unit);
        CHECK_SNPRINTF(ret, output_size - used);
        used += ret;

        for (uint8_t j = 0; j < d->data_count; j++) {
            meter_data_point_t *p = &d->data[j];

            ret = snprintf(output + used, output_size - used,
                "%s{\"timestamp\":\"%s\",\"meter_datetime\":\"%s\","
                "\"total_m3\":%.3f,\"status\":\"%s\"}",
                (j ? "," : ""),
                p->timestamp, p->meter_datetime,
                p->total_value, p->status);
            CHECK_SNPRINTF(ret, output_size - used);
            used += ret;
        }

        ret = snprintf(output + used, output_size - used, "]}");
        CHECK_SNPRINTF(ret, output_size - used);
        used += ret;
    }

    ret = snprintf(output + used, output_size - used, "]}}]");
    CHECK_SNPRINTF(ret, output_size - used);
    used += ret;

    *bytes_written = used;
    return JSON_OK;
}
