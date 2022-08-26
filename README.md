# Sign-Language-Translator
Elements :
- Arduino Nano R3
- Flex sensors x 5
- 10kohm resistors x 10
- Arduino Studio (IDE)

Thought process :
The specifications of flex sensors helped us to implement this idea to the best of our ability.
Flex sensor's resistance level changes based on the amount of bending. In other words, flex sensor is a flexible resistor, it has two pins. Its resistance is minimum when it is relaxed or straight. And resistance is found maximum when bended. Reading the resistance value and mapping them to an angle gave us the generic idea of the position of the individual finger. As the next step through several rounds of testing, we were able to find the desired angle of each finger momentously and use them to visualize the according to the alphabet. The system had an accuracy of 97%. The main factor that affected reducing the accuracy was the alphabet which had the same finger angle but different Z-axis coordinates.
For example Alphabets, M and E or K and the number two were the places we had the most challenges.
The whole process of building the circuits, implementation and testing took over a period of three months.
Within the first 15-20 seconds of the running time, the hand needs to be in a relaxed position so we have access to our relative ) degree. In the next step as the angle changes system detect the angle and match it with the alphabet function with the most compatibility and the smallest threshhold.

<img src="https://user-images.githubusercontent.com/90856064/186990051-1a1261a3-8556-41ce-9bc0-dbaff776619c.jpg" style="height :350px; width =350px;">
