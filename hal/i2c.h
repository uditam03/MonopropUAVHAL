#ifndef I2C_H
#define I2C_H

#include <Wire.h>

// Define I2C pins
#define ICM20948_SCL_PIN 23  // SCL for ICM-20948 (Teensy Pin 23)
#define ICM20948_SDA_PIN 24  // SDA for ICM-20948 (Teensy Pin 24)
#define ICM42670P_SCL_PIN 16 // SCL for ICM-42670-P (Teensy Pin 16)
#define ICM42670P_SDA_PIN 17 // SDA for ICM-42670-P (Teensy Pin 17)
#define VL53L1_SCL_PIN 24    // SCL for VL53L1 (Teensy Pin 24)
#define VL53L1_SDA_PIN 25    // SDA for VL53L1 (Teensy Pin 25)

// Create sensor objects
ICM20948 icm20948;    // ICM-20948 sensor object
ICM42670P icm42670p;  // ICM-42670-P sensor object
VL53L1X vl53l1;       // VL53L1 sensor object

// Initialize I2C for all sensors
void initI2C() {
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);  // Initialize I2C for all sensors on Teensy
    Wire.setClock(400000);                  // Set I2C clock to 400kHz 
    
    // Initialize ICM-20948
    if (!icm20948.begin()) {
        Serial.println("Failed to initialize ICM-20948!");
        while (1);  // Halt if the sensor fails to initialize
    }
    Serial.println("ICM-20948 initialized.");
    
    // Initialize ICM-42670-P
    if (!icm42670p.begin()) {
        Serial.println("Failed to initialize ICM-42670-P!");
        while (1);
    }
    Serial.println("ICM-42670-P initialized.");
    
    // Initialize VL53L1
    if (!vl53l1.begin()) {
        Serial.println("Failed to initialize VL53L1!");
        while (1);
    }
    Serial.println("VL53L1 initialized.");
}

// Enable I2C for sensors
void enableI2C() {
    // Sensor's specific I2C interfaces
}

#endif // I2C_H