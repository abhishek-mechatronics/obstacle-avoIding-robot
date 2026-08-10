# obstacle-avoiding-robot

Arduino based obstacle avoiding robot made using an HC-SR04 ultrasonic sensor and L298N motor driver.

This was a rebuild of my old RoboCar. I worked on the mechanical assembly, wiring, Arduino programming and testing again from the beginning.

## Video

I recorded the complete process while rebuilding and testing the robot.

[Watch the full build and testing video on YouTube](https://youtu.be/n_6aDSAIlYY?si=esBqIy2NV6HnDf5X)

There is also a short demo video of the robot successfully avoiding obstacles.

## Components

- Arduino UNO
- HC-SR04 ultrasonic sensor
- SG90 servo motor
- L298N motor driver
- DC gear motors
- Robot chassis
- 3 × 18650 batteries
- Battery holder
- Power switch

## What I did

- Reassembled the robot chassis
- Planned and completed the wiring
- Connected the motors to the L298N driver
- Connected the ultrasonic sensor and servo
- Tested the sensor readings
- Programmed the robot using Arduino IDE
- Tested the movement and obstacle detection
- Fixed problems with the sensor and robot movement
- Finally tested the obstacle avoiding system

## How it works

The ultrasonic sensor checks the distance in front of the robot. When an obstacle comes close, the robot stops and checks the available direction using the servo-mounted sensor. The Arduino then controls the motors through the L298N motor driver and moves the robot in the better direction.

## Testing and debugging

The robot did not work correctly on the first few attempts. I had problems with the ultrasonic sensor readings and the movement of the robot. I tested the wiring, changed the program and checked the sensor readings before getting the robot to work properly.

## Source code

The Arduino code is available in the `src` folder.

## Project files

The repository also contains photos of the assembly, wiring and final robot along with the testing and debugging notes.

## License

MIT License
