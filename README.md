# Interactive Stair Lighting Systems

Two Arduino-based lighting projects that create animated light sequences triggered by motion detection - perfect for stairs, hallways, or pathways.

## Projects Overview

### 1. Staircase Lighting (Dual-Sensor)

- **Bottom Sensor**: Triggers ascending light sequence (bottom → top)
- **Top Sensor**: Triggers descending light sequence (top → bottom)
- **5-Step Control**: Individual LED control per stair
- **Directional Awareness**: Lights follow movement direction

### 2. Hallway Lighting (Single PIR)

- **Motion Detection**: Single PIR sensor triggers sequence
- **Bottom-to-Top Animation**: Lights illuminate upward
- **Auto Turn-Off**: Turns off in same direction after delay
- **3-Zone Control**: Three LED rows/segments

## Hardware Required

### Common Components

- Arduino (Uno/Nano/Mega)
- LEDs (5 for stairs, 3 for hallway)
- 220Ω resistors (one per LED)
- Breadboard and jumper wires
- Power supply

### Staircase Version Additional

- 2x PIR sensors OR IR break beams
- 5x LEDs

### Hallway Version Additional

- 1x PIR motion sensor
- 3x LEDs (or LED strips)

## Wiring Diagrams

### Staircase Version

```
Bottom Sensor → Pin 10
Top Sensor    → Pin 11
LEDs:
  Step 1 → Pin 2
  Step 2 → Pin 3
  Step 3 → Pin 4
  Step 4 → Pin 5
  Step 5 → Pin 6
```

### Hallway Version

```
PIR Sensor    → Pin 2
LED Rows:
  Row 1 (Bottom) → Pin 9
  Row 2 (Middle) → Pin 10
  Row 3 (Top)    → Pin 11
```

## How They Work

### Staircase Logic

```
Bottom Detected:  LED1→LED2→LED3→LED4→LED5 (ascend)
                  Stay on 5 seconds
                  LED1→LED2→LED3→LED4→LED5 (turn off)
                  Wait 2 seconds for person to exit

Top Detected:     LED5→LED4→LED3→LED2→LED1 (descend)
                  Stay on 5 seconds
                  LED5→LED4→LED3→LED2→LED1 (turn off)
                  Wait 2 seconds for person to exit
```

### Hallway Logic

```
Motion Detected: Row1→Row2→Row3 (illuminate upward)
                 Stay on 3 seconds
                 Row1→Row2→Row3 (turn off in same direction)
```

## Configuration

### Adjustable Parameters (Both Versions)

| Parameter    | Variable     | Description                     |
| ------------ | ------------ | ------------------------------- |
| Step Delay   | `stepDelay`  | Time between LEDs (ms)          |
| Stay On Time | `stayOnTime` | How long all LEDs stay lit (ms) |
| Exit Delay   | `exitDelay`  | Wait time after sequence (ms)   |

### Staircase-Specific

```cpp
int steps[] = {2, 3, 4, 5, 6};  // Change LED pins
int totalSteps = 5;              // Number of steps
```

### Hallway-Specific

```cpp
int animationDelay = 500;        // Time between rows
int rowCount = 3;                 // Number of rows
```

## Installation

1. Build circuit according to your chosen version
2. Upload corresponding code
3. Power the system
4. Test by triggering sensors
5. Adjust timing parameters as needed

## Serial Output (Hallway Version)

```
Motion Detected! Starting Animation...
Animation Complete.
```

## Customization Ideas

### Add Buzzer Feedback

```cpp
// Add at sequence start
tone(BUZZER_PIN, 1000, 100);
```

### Variable Speed Based on Motion

```cpp
// Faster walk = faster animation
stepDelay = map(motionSpeed, 0, 1023, 100, 500);
```

### Fade Effect Instead of On/Off

```cpp
for (int brightness = 0; brightness <= 255; brightness++) {
  analogWrite(ledRows[i], brightness);
  delay(5);
}
```

### Multiple Sequences

```cpp
// Add rainbow or chase effects for special occasions
if (holidayMode) {
  rainbowSequence();
}
```

## Applications

- **Staircase**: Safety lighting, ambiance
- **Hallway**: Pathway guidance, night light
- **Entryways**: Welcome lighting
- **Theaters**: Aisle lighting
- **Museums**: Guided path illumination

## Troubleshooting

| Problem                | Solution                             |
| ---------------------- | ------------------------------------ |
| No response to motion  | Check PIR sensitivity; verify wiring |
| Wrong direction        | Swap sensor assignments              |
| LEDs too dim           | Reduce resistor values               |
| Sequence too fast/slow | Adjust `stepDelay`                   |
| Both sensors trigger   | Add debounce logic                   |

## License

MIT - Free for learning and modification

```

```
