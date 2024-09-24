<h1>Line Following Robot with ESP8266, 3 IR Sensors, and L293D Motor Driver</h1>

<p>This repository contains the code and schematic for building a line-following robot using the ESP8266, 3 IR sensors, and the L293D motor driver. The robot is capable of following a line, making sharp turns (up to 60 degrees), performing U-turns, and resuming path tracking even after a line break.</p>

<h2>Features</h2>
<ul>
  <li><b>Line following:</b> Uses three IR sensors to detect the black line on a white surface.</li>
  <li><b>Sharp turns and U-turns:</b> Capable of handling sharp turns and U-turns.</li>
  <li><b>Line break recovery:</b> Can detect and resume the path after a break in the line.</li>
</ul>

<h2>Components</h2>
<ul>
  <li><b>ESP8266 (NodeMCU):</b> The microcontroller that reads inputs from the sensors and controls the robot.</li>
  <li><b>L293D Motor Driver:</b> Controls two DC motors based on signals from the ESP8266.</li>
  <li><b>3 IR Sensors:</b> Used to detect the black line by sensing surface reflection.</li>
  <li><b>2 DC Motors:</b> Power the wheels of the robot to follow the line.</li>
</ul>

<h2>Circuit Diagram</h2>
<img src="./circuit%20diagram.png" alt="Circuit Diagram" />

<h3>Explanation of the Diagram</h3>
<ul>
  <li><b>ESP8266 (NodeMCU):</b>
    <ul>
      <li>Pins D1, D2, and D3 are connected to the signal pins of the three IR sensors to receive data.</li>
      <li>Pins D5, D6, D7, and D8 are connected to the L293D motor driver to control the direction of the motors.</li>
    </ul>
  </li>
  <li><b>IR Sensors:</b>
    <ul>
      <li>Positioned at the front of the robot to detect the line.</li>
      <li>Signal pins are connected to the ESP8266 (D1, D2, and D3). They output a HIGH or LOW signal depending on whether they detect the black line or the white surface.</li>
    </ul>
  </li>
  <li><b>L293D Motor Driver:</b>
    <ul>
      <li>Drives two DC motors that power the robot's wheels.</li>
      <li>The inputs (IN1, IN2, IN3, IN4) are connected to ESP8266 (D5, D6, D7, D8) to control motor direction.</li>
      <li>Powered by a 9V battery.</li>
    </ul>
  </li>
  <li><b>DC Motors:</b>
    <ul>
      <li>Two DC motors are connected to the L293D motor driver, controlling the robot's movement.</li>
    </ul>
  </li>
  <li><b>Power Supply:</b>
    <ul>
      <li>The ESP8266 is powered by a 5V supply.</li>
      <li>Motors are powered by a 9V battery connected to the motor driver.</li>
    </ul>
  </li>
</ul>

<h2>How It Works</h2>
<p>The IR sensors detect the black line on the ground. The ESP8266 reads the sensor values and adjusts the motor speeds using the L293D motor driver, ensuring the robot follows the line. It adjusts direction based on which sensor detects the line.</p>

<h2>Setup Instructions</h2>
<ol>
  <li><b>Clone the repository:</b>
    <pre><code>git clone https://github.com/yourusername/line-following-robot-esp8266.git</code></pre>
  </li>
  <li><b>Upload the code to your ESP8266 using the Arduino IDE.</b></li>
  <li><b>Assemble the circuit as per the diagram above.</b></li>
  <li><b>Power the robot, and it will begin to follow the line.</b></li>
</ol>

<h2>Future Enhancements</h2>
<ul>
  <li>Add wireless control using WiFi or Bluetooth.</li>
  <li>Implement PID control for smoother line following.</li>
</ul>

<h2>License</h2>
<p>This project is licensed under the MIT License. See the <code>LICENSE</code> file for details.</p>
