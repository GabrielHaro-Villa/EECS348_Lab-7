#include "temperature.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    float input_temp, converted_temp;
    int input_scale, target_scale;

    // Prompt for user input of temp
    printf("Enter the temperature: ");
    if (scanf("%f", &input_temp) != 1) { 
        printf("Invalid input. Please enter a number.\n"); // Error message if the input is not a number
        return 1;
    }

    // Prompt for user input of scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) { // Error message if the input is not a number or not within the range
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    // Prompt for user input of target scale
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) { // Error message if the input is not a number or not within the range
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    // Prevent same-unit conversion
    if (input_scale == target_scale) { // Error message if the input and target scale are the same
        printf("Error: Cannot convert to the same unit. Exiting program.\n");
        return 1;
    }

    // Conversion Logic
    switch (input_scale) {
        case 1: // Case for celsius
            if (target_scale == 2) // Converts temp to fahrenheit if the target scale is (f)
                converted_temp = celsius_to_fahrenheit(input_temp);
            else // else it converts to kelvin
                converted_temp = celsius_to_kelvin(input_temp);
            break;
        case 2: // Fahrenheit
            if (target_scale == 1) // Converts temp to celsius if the target scale is (c)
                converted_temp = fahrenheit_to_celsius(input_temp);
            else // else it converts to kelvin
                converted_temp = fahrenheit_to_kelvin(input_temp);
            break;
        case 3: // Kelvin
            if (input_temp < 0) { // Error message if the input temp is negative
                printf("Error: Kelvin cannot be negative.\n");
                return 1;
            }
            if (target_scale == 1) // Converts temp to celsius if the target scale is (c)
                converted_temp = kelvin_to_celsius(input_temp);
            else // else it converts to fahrenheit
                converted_temp = kelvin_to_fahrenheit(input_temp);
            break;
    }

    // Display output with proper formatting
    printf("Converted temperature: %.2f ", converted_temp);
    if (target_scale == 1) { // If the target scale is celcius, it prints C
        printf("C\n");
    } else if (target_scale == 2) { // If the target scale is fahrenheit, it prints F
        printf("F\n");
    } else { // Else, it prints K for kelvin
        printf("K\n");
    }

    /*
    * Categorize and provide advisory
    * if the target scale is 1, use the converted temp
    * if the target scale is 2, convert the converted temp to celsius, from fahrenheit
    * if the target scale is 3, convert the converted temp to celsius, from kelvin
    */
    float temp_in_celsius = (target_scale == 1) ? converted_temp :
                            (target_scale == 2) ? fahrenheit_to_celsius(converted_temp) :
                            kelvin_to_celsius(converted_temp);
    // Call the function to categorize the temperature
    categorize_temperature(temp_in_celsius);

    return 0;
}
