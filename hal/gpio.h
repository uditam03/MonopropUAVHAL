#define ICM42670P_SCL_PIN 16  // I2C SCL (Teensy Pin 16)
#define ICM42670P_SDA_PIN 17  // I2C SDA (Teensy Pin 17)

// VL53L1 (I2C)
#define VL53L1_SCL_PIN 24  // I2C SCL (Teensy Pin 24)
#define VL53L1_SDA_PIN 25  // I2C SDA (Teensy Pin 25)

// DWM1000 Transceiver (SPI)
#define DWM1000_CS_PIN 0    // Chip Select (CS) Pin for DWM1000 (Teensy Pin 0)
#define DWM1000_SCK_PIN 27  // SPI Clock (SCK) Pin for DWM1000 (Teensy Pin 27)
#define DWM1000_MISO_PIN 1  // SPI MISO Pin for DWM1000 (Teensy Pin 1)
#define DWM1000_MOSI_PIN 26 // SPI MOSI Pin for DWM1000 (Teensy Pin 26)

// Initialize GPIO Pins for the Sensors
void initGPIO() {
    pinMode(GPS_RX_PIN, INPUT);  // RX Pin for GPS (input)
    pinMode(GPS_TX_PIN, OUTPUT); // TX Pin for GPS (output)
    pinMode(ICM20948_SCL_PIN, OUTPUT);  // SCL Pin for ICM-20948
    pinMode(ICM20948_SDA_PIN, OUTPUT);  // SDA Pin for ICM-20948
    pinMode(ICM42670P_SCL_PIN, OUTPUT); // SCL Pin for ICM-42670-P
    pinMode(ICM42670P_SDA_PIN, OUTPUT); // SDA Pin for ICM-42670-P
    pinMode(VL53L1_SCL_PIN, OUTPUT);    // SCL Pin for VL53L1
    pinMode(VL53L1_SDA_PIN, OUTPUT);    // SDA Pin for VL53L1
    pinMode(DWM1000_CS_PIN, OUTPUT);    // Chip Select Pin for DWM1000
    pinMode(DWM1000_SCK_PIN, OUTPUT);   // SPI Clock Pin for DWM1000
    pinMode(DWM1000_MISO_PIN, INPUT);   // SPI MISO Pin for DWM1000 (input)
    pinMode(DWM1000_MOSI_PIN, OUTPUT);  // SPI MOSI Pin for DWM1000
    digitalWrite(DWM1000_CS_PIN, HIGH);  // Disable DWM1000 by default
    Serial.println("GPIO Pins Initialized.");
}

#endif // GPIO_H