# STM32F407 – LED Toggle on Button Press (Bare-Metal)

This project demonstrates how to toggle an LED connected to pin **PD15** of the STM32F407G-DISC1 board when the **User Button** on **PA0** is pressed.

The implementation uses **bare-metal programming**, with direct access to the microcontroller's registers – no HAL, no CMSIS.

## 🛠 Features

- Bare-metal GPIO initialization
- Rising-edge detection on PA0
- Bitwise register operations
- Debounced LED toggle
- Optimized for STM32F407G-DISC1 board

## 🧠 What You Learn

- How to control GPIO via register access
- Input reading and debouncing without HAL
- Bitmasking and peripheral clock setup
- Using `volatile`, `bool`, and bitwise logic

## 📷 Board

- Board: **STM32F407G-DISC1**
- Button: **PA0**
- LED: **PD15**

## 🧩 Connections

| Signal     | Pin    |
|------------|--------|
| Taster     | PA0    |
| LED Output | PD15   |

## 🧪 How It Works

1. The GPIOA and GPIOD clocks are enabled via RCC.
2. PA0 is configured as input, PD15 as output.
3. In the main loop, a rising edge on PA0 toggles the LED.
4. A software delay helps debounce the button.

## 💡 Screenshot
![Toggle_led_edge_detection](https://github.com/user-attachments/assets/5f58cdf8-8be8-4833-8207-d55244324510)

## 📜 License

MIT
