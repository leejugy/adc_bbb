#include "adc.h"

static void thread_adc_read()
{
    while(1)
    {
        print_all_adc_value();
        sleep(1);
    }
}

int read_adc(char *adc_path)
{
    int fd;
    int ret = 0;
    char adc_string[ADC_FILE_LEN] = {0, };
    
    ret = open(adc_path, O_RDONLY);
    if(ret < 0)
    {
        perror("open adc");
        return -1;
    }

    fd = ret;
    ret = read(fd, adc_string, sizeof(adc_string));
    if(ret < 0)
    {
        perror("read adc");
        return -1;
    }

    return atoi(adc_string);
}

float get_voltage(int adc_val)
{
    return (float)adc_val / (float)ADC_RESOLUTION * (float)ADC_MAX_VOLTAGE;
}

void print_all_adc_value()
{
    printf("=================[read adc]=================\n");
    PRINT_ADC("ADC0", "%fV\n", get_voltage(read_adc(ADC0_ROUTE)));
    PRINT_ADC("ADC1", "%fV\n", get_voltage(read_adc(ADC1_ROUTE)));
    PRINT_ADC("ADC2", "%fV\n", get_voltage(read_adc(ADC2_ROUTE)));
    PRINT_ADC("ADC3", "%fV\n", get_voltage(read_adc(ADC3_ROUTE)));
    PRINT_ADC("ADC4", "%fV\n", get_voltage(read_adc(ADC4_ROUTE)));
    PRINT_ADC("ADC5", "%fV\n", get_voltage(read_adc(ADC5_ROUTE)));
    PRINT_ADC("ADC6", "%fV\n", get_voltage(read_adc(ADC6_ROUTE)));
    PRINT_ADC("ADC7", "%fV\n", get_voltage(read_adc(ADC7_ROUTE)));
    printf("============================================\n");
}

void start_adc_thread()
{
    pthread_t pid;
    int ret = 0;

    ret = pthread_create(&pid, NULL, (void *)&thread_adc_read, NULL);
    if(ret < 0)
    {
        perror("thread create fail");
        return;
    }

    ret = pthread_detach(pid);
    if(ret < 0)
    {
        perror("thread detach fail");
    }
}

