# Testing and Debugging

I tested the robot step by step instead of connecting everything and
expecting it to work directly.

## Motor Testing

First I tested the four DC motors with the L298N motor driver.

At the beginning some of the motors were moving in the wrong direction,
so I had to change the motor connections and also change the motor
control in the program.

I also had an issue where the robot was turning instead of moving
straight. This was mainly because the motors on the two sides were not
moving in the same direction.

## Ultrasonic Sensor

I tested the HC-SR04 separately using the Arduino Serial Monitor.

When I kept a wall in front of the sensor, I was getting distance
readings around 15 to 20 cm. But when the object was too far away,
sometimes the Serial Monitor showed "No echo".

I adjusted the code so that the robot would not immediately move
forward when the sensor did not get a proper reading.

## Servo

The ultrasonic sensor was fixed on an SG90 servo.

I tested the servo separately first and then connected it with the
ultrasonic sensor. When an obstacle was detected, the servo would move
the sensor to check the left and right sides.

## Speed Problem

The first version was moving too fast.

Because of this, the robot sometimes reached the obstacle before the
sensor could properly react. I reduced the movement time and made the
robot move forward in small steps instead of continuously.

This made the obstacle detection much more reliable.

## Final Testing

After changing the motor directions, sensor code, servo movement and
speed, I tested the robot several times with obstacles in front of it.

The final version was able to detect an obstacle, scan the sides and
move towards the clearer side.

There were a few mechanical issues during the build, especially with
the wheels and motor mounting, but the final demonstration worked.
