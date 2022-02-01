#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
float celciusTempReading;

int networkAlertStub(float celcius) {
    float retTempReading;
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius>200)
    {
        retTempReading = 500;
    }
    else
    {
        retTempReading = 200;
    }
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return retTempReading;
}

void alertInCelcius(float farenheit) {
    /* Convertion of farenheit to celcius */
    float celcius = (farenheit - 32) * 5 / 9;
    celciusTempReading = celcius;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    float farenheitReading;
    farenheitReading = 400.5;
    alertInCelcius(farenheitReading);
    assert(alertFailureCount == 1);
    assert((400.5) == celciusTempReading);
    
    farenheitReading = 303.6;
    alertInCelcius(farenheitReading);
    assert(alertFailureCount == 1);
    assert((303.6) == celciusTempReading);
    
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
