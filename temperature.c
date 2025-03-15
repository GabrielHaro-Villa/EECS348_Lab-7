#include "temperature.h"
#include <stdio.h>

// Convert temperature in Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Convert temperature in Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// Convert temperature in Celsius to Kelvin
float celsius_to_kelvin(float celsius){
    float kelvin = celsius + 273.15;
    return kelvin;
}

// Convert temperature in Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Convert temperature in Fahrenheit to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    float kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
    return kelvin;
}

// Convert temperature in Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    float fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
    return fahrenheit;
}

void categorize_temperature(float celsius) {
    printf("Temperature category: ");
    if (celsius <= 0) {
        printf("Freezing\nWeather advisory: Wear winter clothing, stay indoors\n");
    } else if (celsius <= 10) {
        printf("Cold\nWeather advisory: Wear a jacket.\n");
    } else if (celsius <= 25) {
        printf("Comfortable\nWeather advisory: You should feel comfortable.\n");
    } else if (celsius <= 35) {
        printf("Hot\nWeather advisory: wear summer clothing.\n");
    } else {
        printf("Extreme heat\nWeather advisory: Stay indoors, wear light clothing.\n");
    }
}