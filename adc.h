#ifndef __ADC__
#define __ADC__
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>

#define SYSFS_ADC_ROUTE "/sys/bus/iio/devices/iio:device0/in_voltage"

#define ADC0_ROUTE SYSFS_ADC_ROUTE "0_raw"
#define ADC1_ROUTE SYSFS_ADC_ROUTE "1_raw"
#define ADC2_ROUTE SYSFS_ADC_ROUTE "2_raw"
#define ADC3_ROUTE SYSFS_ADC_ROUTE "3_raw"
#define ADC4_ROUTE SYSFS_ADC_ROUTE "4_raw"
#define ADC5_ROUTE SYSFS_ADC_ROUTE "5_raw"
#define ADC6_ROUTE SYSFS_ADC_ROUTE "6_raw"
#define ADC7_ROUTE SYSFS_ADC_ROUTE "7_raw"

#define ADC_RESOLUTION 4096
#define ADC_FILE_LEN 4
#define ADC_MAX_VOLTAGE 1.8

#define PRINT_ADC(ADC_VAL, fmt, ...) printf("[\x1b[32m" ADC_VAL "\x1b[0m]" fmt, ##__VA_ARGS__)

int read_adc(char *adc_path);
void print_all_adc_value();
float get_voltage(int adc_val);
void start_adc_thread();

#endif