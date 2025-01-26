#ifndef SPI_H
#define SPI_H

#include <SPI.h>

// Define SPI pins for DWM1000
#define DWM1000_CS_PIN 0    // Chip Select (CS) Pin for DWM1000 (Teensy Pin 0)
#define DWM1000_SCK_PIN 27  // SPI Clock (SCK) Pin for DWM1000 (Teensy Pin 27)
#define DWM1000_MISO_PIN 1  // SPI MISO Pin for DWM1000 (Teensy Pin 1)
#define DWM1000_MOSI_PIN 26 // SPI MOSI Pin for DWM1000 (Teensy Pin 26)

// Initialize SPI for DWM1000
void initSPI() {
    SPI.begin();  // Start the SPI bus
    pinMode(DWM1000_CS_PIN, OUTPUT);  // Set CS pin as output
    digitalWrite(DWM1000_CS_PIN, HIGH);  // Disable DWM1000 by default
    Serial.println("SPI Initialized for DWM1000.");
}

// Enable DWM1000 for SPI communication
void enableSPI() {
    digitalWrite(DWM1000_CS_PIN, LOW);  // Enable DWM1000
}

// Disable DWM1000 for SPI communication
void disableSPI() {
    digitalWrite(DWM1000_CS_PIN, HIGH);  // Disable DWM1000
}

#endif // SPI_H