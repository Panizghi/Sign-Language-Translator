## Sign-Language-Translator

### Components:
- Arduino Nano R3
- Flex sensors x 5
- 10kohm resistors x 10
- Arduino Studio (IDE)

### Description:
#### Thought Process:
The foundation of this Sign Language Translator project is built upon the utilization of flex sensors. These sensors exhibit varying resistance levels corresponding to the degree of bending. Functioning as flexible resistors with two pins, their resistance is minimum when in a relaxed or straight state and reaches its maximum when bent.

#### Implementation:
By reading the resistance values and mapping them to angles, we gained insights into the position of individual fingers. Through iterative testing, we determined the optimal angles for each finger, enabling us to associate them with specific alphabet visualizations. The system achieved an impressive accuracy rate of 97%.

#### Challenges:
One notable challenge arose from alphabets that shared the same finger angle but had different Z-axis coordinates. Instances such as distinguishing between "M" and "E" or "K" and the number "2" posed difficulties, impacting the overall accuracy.

#### Development Timeline:
The entire process, encompassing circuit building, implementation, and testing, spanned three months. The initial 15-20 seconds of operation require the hand to be in a relaxed position for the system to establish a relative baseline degree. Subsequently, as the hand's angle changes, the system detects the angle, matches it with the alphabet function with the highest compatibility, and considers a small threshold for accuracy.

<img src="https://user-images.githubusercontent.com/90856064/186990051-1a1261a3-8556-41ce-9bc0-dbaff776619c.jpg" style="height :350px; width =350px;">
