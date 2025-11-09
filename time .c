#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *localTime, indiaTime;

    // Get current time
    time(&rawtime);

    // Get local time
    localTime = localtime(&rawtime);
    printf("Local Time: %02d:%02d:%02d\n",
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    // Convert to India Standard Time (UTC+5:30)
    indiaTime = *gmtime(&rawtime); // Get UTC time
    indiaTime.tm_hour += 5;
    indiaTime.tm_min += 30;

    // Adjust for overflow
    if (indiaTime.tm_min >= 60) {
        indiaTime.tm_min -= 60;
        indiaTime.tm_hour += 1;
    }
    if (indiaTime.tm_hour >= 24) {
        indiaTime.tm_hour -= 24;
    }

    printf("India Time (IST): %02d:%02d:%02d\n",
           indiaTime.tm_hour, indiaTime.tm_min, indiaTime.tm_sec);

    return 0;
}