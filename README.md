# PicoStream-60

PicoStream-60 is a desk wind tunnel use for analyzing drag force on different objects, such as Hotwheels cars, scaled airplane models, or even custom geometries made by someone! It's powered by the Raspberry Pi Pico rp2040 microcontroller. I designed this because as someone who is deeply passionate about aerospace engineering, I though this would be a good project that I could even learn from, and even use in the future.

## Features:
* **Powerful Brushless Fan**  PicoStream-60 features a powerful 60mm delta fan intended for server cooling, and can spin up to 12,000 rpm.
* **Adjustable Fan Speed:** Via an ec11 digital encoder, the fan can be adjusted for different kinds of enviornments, and items being tested, and features around 33 indivual speed settings.
* **Scientifically Accurate Design:** I engineered PicoStream-60 to follow real world principles when designing a wind tunnel, including a honeycomb mesh panel to reduce air turbulence, and an inlet which reduces in area size to streamline airflow.
* **Analysis Feature** This wind tunnel has the ability to record and display live time drag force in grams on an external serial monitor (given, that you will need your own external display) for further drag force analysis

---

## CAD Model
I designed the overall wind tunnel structure on Fusion360, and have decided to 3d print the parts using standard PLA at 20% infill. The assembly also has nice rounded curves to make it more presentable

<img width="2560" height="2048" alt="Main_Housing_2026-Jul-23_05-11-49AM-000_CustomizedView10790424624" src="https://github.com/user-attachments/assets/2e1e0b12-62df-44dc-bedd-b6fbe951a376" />

---

### Schematic Design
*The circuit schematic mapping the switch, digital encoder, and Load Cell to the microcontroller.*

<img width="1566" height="1079" alt="Screenshot 2026-07-23 190917" src="https://github.com/user-attachments/assets/da42c8a1-9abe-4be0-9678-fe655b69781c" />

---

## How to Assemble
1. Join the mesh and mesh mount together with the m3 screws
2. Attatch the Fan to the Fan mount using the m4 screws, and hot glue the Pico microcontroller, Switch and Rotary encoder to the Fan Mount aswell
3. Glue the load cell into the hole in the carriage halfway, with the end with the wires sticking out (See CAD model to locate mounting hole)
4. Hot glue the rest of the parts together, and make sure to line each gap with duct tape to keep the wind tunnel assembly extra air tight
5. Wire up! (See schematic for reference)
6. Now move onto "How to Flash"!
---

## How to Flash
1. Press and hold the physical **BOOT** button on the Pico controller board.
2. Connect the USB cable while holding the button, then release it.
3. A virtual drive will mount to your operating system.
4. Drag and drop the `sketch_jul22a.ino.uf2` binary file directly onto the root of the drive.
5. The device will automatically flash, reboot, and initialize as an operational device.

---

## AI Attribution Note
**Please Note that AI was utilized for some basic project planning and debugging of the firmware in Arduino IDE**
