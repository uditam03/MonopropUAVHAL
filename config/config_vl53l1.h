#ifndef CONFIG_VL53L1_H
#define CONFIG_VL53L1_H

// VL53L1 Configuration
#define VL53L1_I2C_ADDRESS 0x29    // Default I2C address for VL53L1
#define VL53L1_TIMEOUT 500        // Timeout for distance reading (in ms)
#define VL53L1_THRESHOLD 100      // Threshold distance for readings in mm
#define VL53L1_HIGH_SPEED 0       // High-speed mode (0 for off, 1 for on)

#endif // CONFIG_VL53L1_H
