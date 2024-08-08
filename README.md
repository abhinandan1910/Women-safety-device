# Women Safety Device using Microcontroller

This project is designed to create a portable women safety device using a microcontroller. The device integrates a GPS module, GSM module, Bluetooth, buzzer, accelerometer, and light sensor to detect emergencies and send alerts with the user's location.

## Table of Contents
- [Introduction](#introduction)
- [Components Used](#components-used)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Contributing](#contributing)
- [License](#license)

## Introduction
The Women Safety Device is a compact, portable device that can be carried around easily. In the event of an emergency, the device can detect falls, low light conditions, or manual triggers and send an alert via SMS containing the GPS location of the user. The device also activates a buzzer to attract nearby attention.

## Components Used
- **Arduino Microcontroller**: The brain of the device.
- **GPS Module**: To get the current location coordinates.
- **GSM Module**: To send SMS alerts.
- **Bluetooth Module**: For wireless communication (optional).
- **Buzzer**: For sounding an alarm.
- **Accelerometer (MPU6050)**: To detect falls or unusual movements.
- **Light Sensor**: To detect low light conditions.
- **Battery**: To power the device.

## Circuit Diagram
A detailed circuit diagram is provided in the `schematic/` folder. This will guide you in assembling the components correctly.

![Circuit Diagram](images/circuit_diagram.png)

## Installation

### Prerequisites
- Arduino IDE
- Required Libraries:
  - [TinyGPSPlus](https://github.com/mikalhart/TinyGPSPlus)
  - [Adafruit MPU6050](https://github.com/adafruit/Adafruit_MPU6050)

### Steps
1. **Clone the Repository**:
    ```bash
    git clone https://github.com/yourusername/women-safety-device.git
    cd women-safety-device
    ```

2. **Install Libraries**:
    - Download and install the required libraries from the links above or through the Arduino Library Manager.

3. **Upload Code**:
    - Connect your Arduino to your computer.
    - Open `women_safety_device.ino` in the Arduino IDE.
    - Select the appropriate board and port from the Tools menu.
    - Upload the sketch to the Arduino.

## Usage
1. **Power On the Device**:
    - Ensure the device is powered by the battery and all components are connected as per the circuit diagram.

2. **Testing the Device**:
    - Simulate a fall by shaking the device or placing it in low light to trigger alerts.

3. **Receiving Alerts**:
    - The GSM module will send an SMS with the GPS coordinates to a predefined phone number in case of an emergency.

## How It Works
- **Fall Detection**: The accelerometer monitors the movement of the device. If it detects a fall or abrupt movement exceeding the threshold, it triggers an alert.
- **Light Sensor**: The light sensor monitors the ambient light. If the light level drops below the set threshold, an alert is triggered.
- **GPS Location**: The GPS module obtains the current location, which is then sent via SMS using the GSM module when an alert is triggered.
- **Buzzer**: The buzzer sounds an alarm to attract attention during emergencies.

## Contributing
Contributions are welcome! If you have suggestions or improvements, please fork the repository and submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
