#include <Wire.h>
#include <SPI.h>
#include "config_icm20948.h"  // Include configuration for ICM-20948
#include "config_ubx.h"        // Include configuration for UBX GPS
#include "config_vl53l1.h"     // Include configuration for VL53L1
#include "config_dwm1000.h"    // Include configuration for DWM1000
#include "gpio.h"              // GPIO setup for Teensy pins
#include "i2c.h"               // I2C communication setup
#include "spi.h"               // SPI communication setup
#include "ubx.h"               // UBX GPS communication setup

// Define global variables for sensors
ICM20948 imu(ICM20948_I2C_ADDRESS);    // ICM-20948 sensor with I2C address
UBX gps;                                // UBX GPS object
VL53L1 vl53l1;                          // VL53L1 distance sensor
DWM1000 dwm1000;                        // DWM1000 transceiver

void setup() {
    Serial.begin(115200);               // Start serial communication
    Wire.begin();                       // Start I2C communication
    SPI.begin();                        // Start SPI communication

    // Initialize GPIO for specific sensors if needed
    initGPIO(); 

    // Initialize sensors based on the configurations
    imu.initialize();                   // Initialize ICM-20948 with default config
    gps.begin(UBX_GPS_BAUD_RATE);       // Initialize UBX GPS with baud rate
    vl53l1.begin();                     // Initialize VL53L1 sensor
    dwm1000.begin(DWM1000_SPI_SPEED);   // Initialize DWM1000 with SPI speed

    // Display sensor configuration on Serial Monitor
    Serial.println("Sensor Initialization Complete.");
}

// Read GPS data (example)
void readGPS() {
    if (gps.isDataAvailable()) {
        float lat = gps.getLatitude();
        float lon = gps.getLongitude();
        Serial.print("Latitude: ");
        Serial.print(lat, 6);
        Serial.print(", Longitude: ");
        Serial.println(lon, 6);
    }
}

void loop() {
    // Read and display GPS data
    readGPS();

    // Read and display ICM-20948 sensor data (Accel X, Y, Z)
    icm20948.update();
    Serial.print("ICM-20948 Accel X: ");
    Serial.print(icm20948.getAccelX());
    Serial.print(", Y: ");
    Serial.print(icm20948.getAccelY());
    Serial.print(", Z: ");
    Serial.println(icm20948.getAccelZ());

    // Read and display ICM-42670-P sensor data (Accel X, Y, Z)
    icm42670p.update();
    Serial.print("ICM-42670-P Accel X: ");
    Serial.print(icm42670p.getAccelX());
    Serial.print(", Y: ");
    Serial.print(icm42670p.getAccelY());
    Serial.print(", Z: ");
    Serial.println(icm42670p.getAccelZ());

    // Read and display VL53L1 sensor data (Distance)
    vl53l1.readRangeContinuousMillimeters();
    Serial.print("VL53L1 Distance: ");
    Serial.println(vl53l1.readRangeContinuousMillimeters());

    // Read and display DWM1000 position data
    dwm1000.update();
    Serial.print("DWM1000 Position: ");
    Serial.println(dwm1000.getPosition());

    // Delay before next iteration
    delay(500);  // Update every 500ms
}