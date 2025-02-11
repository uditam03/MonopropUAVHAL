#ifndef UBX_H
#define UBX_H

#include <HardwareSerial.h> //Not added in the repository currently

#define GPS_RX_PIN 8   // RX2 Pin for GPS (Teensy Pin 8)
#define GPS_TX_PIN 7   // TX2 Pin for GPS (Teensy Pin 7)

// Set up UBX GPS using HardwareSerial
HardwareSerial& gpsSerial = Serial2;  // Use Serial2 for GPS

void initGPS() {
    gpsSerial.begin(9600);  // Start the GPS serial at 9600 baud
    Serial.println("GPS Initialized on UBX protocol.");
}

// Function to read GPS data
void readGPS() {
    while (gpsSerial.available()) {
        String gpsData = gpsSerial.readStringUntil('\n');  // Read GPS data
        Serial.print("GPS Data: ");
        Serial.println(gpsData);
    }
}

#endif // UBX_H
