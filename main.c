#include "adc.h"

int main()
{
    start_adc_thread();
    while(1)
    {
        sleep(1);
    }
}