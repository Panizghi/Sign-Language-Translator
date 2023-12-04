# Sign Language Translator - SE 101 Course Project

## Group Information:
- **Group Name:** 2b || !2b
- **Team Members:**
  - Paniz Ojaghi 
  - Zhifan Li 
  - Ahraz Yousuf

## 1. Introduction
The Sign Language Translator glove project, developed as part of the SE 101 Course, aimed to create a device that could effectively translate sign language gestures into text and speech. Motivated by the desire for a project that balanced complexity and feasibility, our group chose this idea to explore the concept of translating sign language through gestures.

## 2. Background Research
Our research drew from Arduino guides for a sign language glove translator and flex sensor functionality. Utilizing flex sensors that measure bending or deflection, we referred to a guide titled "Interfacing Flex Sensor with Arduino" from Last Minute Engineers, providing insights into flex sensor characteristics and usage with Arduino microcontrollers. Another key resource was an Arduino project on Project Hub, offering materials, schematics, and code segments for our project.

## 3. Implementation
The project involved both hardware and software components. Setting up the breadboard, connecting wires, and integrating components like flex sensors, Bluetooth module, and accelerometer were crucial. The Arduino Nano R3 microcontroller served as the central control, managing flex sensors and power distribution. The software collected data from flex sensors, processed the angles, and printed corresponding letters based on predefined parameters.

### Block Diagram (Hardware Components):

<img width="461" alt="hdw" src="https://github.com/Panizghi/Sign-Language-Translator/assets/90856064/78f70312-19f5-4a67-9ef0-6a1ce4a268b8">

### Block Diagram (Software Components):
<img width="442" alt="sfw" src="https://github.com/Panizghi/Sign-Language-Translator/assets/90856064/d37de457-f01b-487e-921f-1e667335637f">

### Final Demo:
<img src="https://user-images.githubusercontent.com/90856064/186990051-1a1261a3-8556-41ce-9bc0-dbaff776619c.jpg" style="height :350px; width =350px;">

## 4. Group Members’ Contribution
Each team member played a vital role in the project. Paniz led the group, contributed to coding, and coordinated team activities. Zhifan handled breadboard setup and wiring, contributing to software development. Ahraz provided research, materials, and assisted in debugging, while Tristan contributed materials, aided in soldering, and worked on report documentation.

## 5. Final Product Evaluation
The glove evolved from an initial state of only reading values to printing letters and phrases, demonstrating improved performance. While time constraints and a faulty flex sensor limited the range of translated letters, the system achieved the goal of translating common phrases such as "I love you."

## 6. Design Trade-offs
Design trade-offs included adjustments to resistor configurations for optimal current flow through flex sensors. Simplifying the output display by using the Arduino IDE screen instead of an LED screen was a pragmatic choice. Limitations on resources led to compromises in implementing additional features like an independent LED/OLED screen and a smaller breadboard.

## 7. Future Work
Potential enhancements involve refining flex sensor accuracy for complete letter translation, improving aesthetics for a polished appearance, implementing an internal power supply, and exploring dual-glove systems for two-handed sign language. Language settings, voice modulation, and expanded phrase translation could further enhance functionality.

## 8. References
- satyamker80. "A glove that translates sign language into text and speech." Arduino Project Hub. Retrieved from [Arduino Project Hub](https://create.arduino.cc/projecthub/173799/a-glove-that-translate-sign-language-into-text-and-speech-c91b13).
- Last Minute Engineers. "In-depth: Interfacing flex sensor with Arduino." Last Minute Engineers. Retrieved from [Last Minute Engineers](https://lastminuteengineers.com/flex-sensor-arduino-tutorial/).


