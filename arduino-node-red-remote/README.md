# Arduino Node-RED Remote

This project integrates an Arduino R4 with Node-RED to control an LED matrix using a keypad and screen interface. The Arduino collects user input and sends it to Node-RED, which then communicates with the LED matrix via an API.

## Project Structure

```
arduino-node-red-remote
├── src
│   ├── arduino
│   │   └── main.ino          # Main Arduino sketch
│   ├── node-red
│   │   └── flow.json         # Node-RED flow configuration
│   ├── api
│   │   └── led-matrix.ts     # API for LED matrix communication
│   └── utils
│       └── index.ts          # Utility functions
├── package.json               # NPM package configuration
├── tsconfig.json              # TypeScript configuration
└── README.md                  # Project documentation
```

## Setup Instructions

1. **Arduino Setup**:
   - Connect the keypad and screen to the Arduino R4.
   - Upload the `main.ino` sketch to the Arduino using the Arduino IDE.

2. **Node-RED Setup**:
   - Install Node-RED on your machine.
   - Import the `flow.json` file into Node-RED to set up the necessary flows.

3. **API Setup**:
   - Ensure that the API defined in `led-matrix.ts` is properly configured to communicate with your LED matrix.

4. **Utility Functions**:
   - The utility functions in `index.ts` can be used to format data and validate user input.

## Usage

- Use the keypad to input values on the Arduino.
- The Arduino will send the input values to Node-RED.
- Node-RED will process the data and send it to the LED matrix for display.

## Contributing

Feel free to submit issues or pull requests if you have suggestions or improvements for the project.