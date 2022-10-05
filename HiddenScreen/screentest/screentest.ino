/**
 * @file screentest.ino
 * @author Joseph Telaak (jtelaak@sc.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Include Arduino
#include <Arduino.h>

// Libaries
#include <Servo.h>

// Pin Definitons

// Buttons
#define BUTTON_1 A2
#define BUTTON_2 A1
#define BUTTON_3 A4
#define BUTTON_4 A3

// Relays
#define RELAY_1 5
#define RELAY_2 8

// Servo
#define SERVO_1 9

// Activity LED
#define ACTIVITY_LED 10

// Global Variables
Servo servo_1;

// Setup function
void setup() {
    // Buttons
    pinMode(BUTTON_1, INPUT);
    pinMode(BUTTON_2, INPUT);
    pinMode(BUTTON_3, INPUT);
    pinMode(BUTTON_4, INPUT);

    // Relays
    pinMode(RELAY_1, OUTPUT);
    pinMode(RELAY_2, OUTPUT);
    pinMode(SERVO_1, OUTPUT);

    // Activity LED
    pinMode(ACTIVITY_LED, OUTPUT);

    // Servo
    servo_1.attach(SERVO_1);

}

// Loop function
void loop() {
    // Check buttons and run callbacks
    if (digitalRead(BUTTON_1) == HIGH) { button1Callback(); }
    if (digitalRead(BUTTON_2) == HIGH) { button2Callback(); }
    if (digitalRead(BUTTON_3) == HIGH) { button3Callback(); }
    if (digitalRead(BUTTON_4) == HIGH) { button4Callback(); }
    
}

// Button 1 Callback - Turn on relay 1
void button1Callback() {
    // Set activity LED
    digitalWrite(ACTIVITY_LED, HIGH);

    while (digialRead(BUTTON_1) == HIGH) {
        // Activate relay 1
        digitalWrite(RELAY_1, HIGH);
        
        // Wait
        delay(100);

    }

    // Reset relay 1
    digitalWrite(RELAY_1, LOW);

    // Reset activity LED
    digitalWrite(ACTIVITY_LED, LOW);

}

// Button 2 Callback - Turn on relay 2
void button2Callback() {
    // Set activity LED
    digitalWrite(ACTIVITY_LED, HIGH);

    while (digialRead(BUTTON_2) == HIGH) {
        // Activate relay 2
        digitalWrite(RELAY_2, HIGH);
        
        // Wait
        delay(100);

    }

    // Reset relay 2
    digitalWrite(RELAY_2, LOW);

    // Reset activity LED
    digitalWrite(ACTIVITY_LED, LOW);

}

// Button 3 Callback - Increment servo 1
void button3Callback() {
    // Set activity LED
    digitalWrite(ACTIVITY_LED, HIGH);

    while (digialRead(BUTTON_3) == HIGH) {
        // Increment servo 1
        servo_1.write(servo_1.read() + 1);
        
        // Wait
        delay(100);

    }

    // Reset activity LED
    digitalWrite(ACTIVITY_LED, LOW);

}

// Button 4 Callback - Decrement servo 1
void button4Callback() {
    // Set activity LED
    digitalWrite(ACTIVITY_LED, HIGH);

    while (digialRead(BUTTON_4) == HIGH) {
        // Decrement servo 1
        servo_1.write(servo_1.read() - 1);
        
        // Wait
        delay(100);

    }

    // Reset activity LED
    digitalWrite(ACTIVITY_LED, LOW);

}