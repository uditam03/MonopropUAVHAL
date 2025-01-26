#ifndef CONFIG_ICM20948_H
#define CONFIG_ICM20948_H

// ICM-20948 Configuration
#define ICM20948_I2C_ADDRESS 0x68      // I2C address for ICM-20948
#define ICM20948_ACCEL_RANGE 2         // Accelerometer Range: 2g, 4g, 8g, 16g
#define ICM20948_GYRO_RANGE 250        // Gyroscope Range: 250, 500, 1000, 2000 (°/s)
#define ICM20948_BANDWIDTH 5           // Bandwidth: 0 (Low) to 7 (High)

#endif // CONFIG_ICM20948_H