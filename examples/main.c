#include <stdio.h>
#include "json_serializer.h"

int main(void)
{
    gateway_data_t gw = {
        .gateway_id = "gateway_1234",
        .date = "1970-01-01",
        .device_type = "stromleser",
        .interval_minutes = 15,
        .total_readings = 1,
        .device_count = 1
    };

    device_reading_t *d = &gw.devices[0];
    snprintf(d->media, 32, "water");
    snprintf(d->meter, 32, "waterstarm");
    snprintf(d->device_id, 32, "stromleser_50898527");
    snprintf(d->unit, 8, "m3");
    d->data_count = 1;

    snprintf(d->data[0].timestamp, 20, "1970-01-01 00:00");
    snprintf(d->data[0].meter_datetime, 20, "1970-01-01 00:00");
    d->data[0].total_value = 107.752f;
    snprintf(d->data[0].status, 8, "OK");

    char json[1024];
    size_t written;

    serialize_to_json(&gw, json, sizeof(json), &written);
    printf("%s\n", json);

    return 0;
}
