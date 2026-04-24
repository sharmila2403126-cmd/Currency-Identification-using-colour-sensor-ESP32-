# Currency-Identification-using-colour-sensor-ESP32-
This project is a simple currency detection system built using an Arduino, a TCS3200/TCS230 color sensor, and a 16x2 LCD display. It is designed to identify Indian currency notes such as ₹10, ₹20, ₹50, ₹100, and ₹500 using RGB color values.

The color sensor detects the red, green, and blue intensity of the currency note placed in front of it. These RGB values are sent to the Arduino, where they are compared with predefined ranges for each denomination. Based on this comparison, the system determines the currency value.

Once identified, the detected note value is displayed on the LCD screen. If the RGB values do not match any stored range, the system displays “Unknown”.

This project helps in understanding basic concepts of Arduino programming, sensor interfacing, and decision-making using conditional logic. It is simple, low-cost, and suitable for beginners.

However, the accuracy depends on proper calibration and lighting conditions. Similar colors between notes may lead to incorrect detection. Despite these limitations, it serves as a useful educational prototype for currency recognition systems.
