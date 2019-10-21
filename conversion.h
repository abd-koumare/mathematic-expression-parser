//
// Created by abou on 20/10/19.
//

#ifndef EXPRESSION_PARSER_CONVERSION_H
#define EXPRESSION_PARSER_CONVERSION_H

//temperature


double celsiusToFahrenheit(float celsius)
{
    return (celsius * 9) / 5 + 32;
}


double fahrenheitToCelsius(float fahrenheit)
{
    return ((fahrenheit - 32) * 5) / 9;
}


double celsiusToKelvin(float celsius)
{
    return celsius + 273.15;
}
double kelvinToCelsius(float kelvin)
{
    return kelvin - 273.15;
}


double fahrenheitToKelvin(float fahrenheit)
{
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

double kelvinToFahrenheit(float kelvin)
{
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}


#endif //EXPRESSION_PARSER_CONVERSION_H
