#ifndef GPIO_CDD_H
#define GPIO_CDD_H

/*********************************************************************/
/* ZALACZONE PLIKI                                                   */
/*********************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/*********************************************************************/
/* PROTOTYPY FUNKCJI                                                 */
/*********************************************************************/
void IntToString(int number, char string[]);
int potega(int liczba, char stopien);
char gpio_uexport(char gpio_pin);
char gpio_export(char gpio_pin);
char gpio_direction(char direct, char gpio_pin);
char gpio_value(char value, char gpio_pin);
char unexport_all();


#endif