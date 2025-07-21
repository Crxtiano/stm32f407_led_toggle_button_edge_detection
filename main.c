/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Benoit Christian Mbole Zogo
 * @brief          : LED Blinky Project – STM32F407 (Bare-metal, no HAL)
 ******************************************************************************
 * @attention
 *
 * This project demonstrates how to toggle an LED connected to PD15
 * using direct register access (bare-metal approach).
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "stm32f407xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* -------------------- Delay Constant -------------------- */
#define DELAY_COUNT    (1000000UL)           // Rough delay count

/* -------------------- Function Prototypes -------------------- */
void delay(volatile uint32_t count);

/* -------------------- Main Function -------------------- */
int main(void)
{
    // 1. Enable clock access to GPIOA and GPIOD
    RCC_AHB1ENR |= (RCC_AHB1ENR_GPIOA_EN | RCC_AHB1ENR_GPIOD_EN);

    // 2. Configure PA0 as general-purpose input
    GPIOA_MODER &= ~(3 << (PIN_TASTER * 2));  // Clear mode bits for pin A0

    // 3. Configure PD15 as general-purpose output
    GPIOD_MODER &= ~(3 << (PIN_LED * 2));  // Clear mode bits for pin 15
    GPIOD_MODER |=  (1 << (PIN_LED * 2));  // Set pin 15 to output mode (01)

    //Variable for flank detection
    bool button_old = false;
    bool button_new = false;

    // 3. Blink the LED
    while (1)
    {
        //read button state
    	button_new = (GPIOA_IDR & (1 << PIN_TASTER)) !=0;

    	//Flank detection LOW -> HIGH
    	if(button_new && !button_old)
    	{
    		GPIOD_ODR ^= (1 << PIN_LED);     // Toggle PD12
    		delay(DELAY_COUNT);           // Delay
    	}

    	//Update old state
    	button_old = button_new;

    }
}

/* -------------------- Delay Function -------------------- */
/**
 * @brief  Simple blocking delay using a loop
 * @param  count: number of iterations to delay
 */
void delay(volatile uint32_t count)
{
    while (count--)
    {
        __asm__("nop");  // No Operation – waste one CPU cycle
    }
}
