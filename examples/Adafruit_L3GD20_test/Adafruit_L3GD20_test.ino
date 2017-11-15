// 这是一个Adafruit L3GD20三轴陀螺仪传感器的一个例子
// 传感器用I2C或者SPI来通讯

#include <Adafruit_L3GD20.h>

// 采用SPI通讯，定义SPI管脚
#define GYRO_CS 4  // CS管脚
#define GYRO_DO 5  // SA0管脚
#define GYRO_DI 6  // SDA管脚
#define GYRO_CLK 7 // SCL管脚

Adafruit_L3GD20 gyro(GYRO_CS, GYRO_DO, GYRO_DI, GYRO_CLK);

void setup()
{
    Serial.begin(115200);
    // 阐释初始化，如果没有初始化则串口输出相应信息
    if (!gyro.begin(gyro.L3DS20_RANGE_250DPS))
        //if (!gyro.begin(gyro.L3DS20_RANGE_500DPS))
        //if (!gyro.begin(gyro.L3DS20_RANGE_2000DPS))
    {
        Serial.println("Oops ... unable to initialize the L3GD20. Check your wiring!");
        while (1);
    }
}

void loop()
{
    gyro.read(); // 陀螺仪读取数值
    Serial.print("X: "); Serial.print((int)gyro.data.x);   Serial.print(" ");   // 输出传感器的数值
    Serial.print("Y: "); Serial.print((int)gyro.data.y);   Serial.print(" ");
    Serial.print("Z: "); Serial.println((int)gyro.data.z); Serial.print(" ");
    delay(100);
}
