#include "temperature.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    float input_temp, converted_temp;
    int input_scale, target_scale;

    // User Input
    printf("Enter the temperature: ");
    if (scanf("%f", &input_temp) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    // Prevent same-unit conversion
    if (input_scale == target_scale) {
        printf("Error: Cannot convert to the same unit. Exiting program.\n");
        return 1;
    }

    // Conversion Logic
    switch (input_scale) {
        case 1: // Celsius
            if (target_scale == 2)
                converted_temp = celsius_to_fahrenheit(input_temp);
            else
                converted_temp = celsius_to_kelvin(input_temp);
            break;
        case 2: // Fahrenheit
            if (target_scale == 1)
                converted_temp = fahrenheit_to_celsius(input_temp);
            else
                converted_temp = fahrenheit_to_kelvin(input_temp);
            break;
        case 3: // Kelvin
            if (input_temp < 0) {
                printf("Error: Kelvin cannot be negative.\n");
                return 1;
            }
            if (target_scale == 1)
                converted_temp = kelvin_to_celsius(input_temp);
            else
                converted_temp = kelvin_to_fahrenheit(input_temp);
            break;
    }

    // Display output with proper formatting
    printf("Converted temperature: %.2f ", converted_temp);
    if (target_scale == 1) {
        printf("C\n");
    } else if (target_scale == 2) {
        printf("F\n");
    } else {
        printf("K\n");
    }

    // Categorize and provide advisory
    float temp_in_celsius = (target_scale == 1) ? converted_temp :
                            (target_scale == 2) ? fahrenheit_to_celsius(converted_temp) :
                            kelvin_to_celsius(converted_temp);

    categorize_temperature(temp_in_celsius);

    return 0;
}
