# Lotus-Flower

Welcome to the Arduino Lotus Flower Project repository! This project aims to provide a comprehensive guide for building and programming an Arduino-based device. The repository includes detailed schematics, 3D print files, the Arduino code, and explanations to help you understand and replicate the project.

## Table of Contents 
[Project Overview](#project-overview)

[Schematics](#schematics)

[3D Print Files](#3d-print-files)

[Arduino Code](#arduino-code)

[How to Use](#how-to-use)

[Contributing](#contributing)

[License](#license)

## Project Overview
The project involves creating an elegant color mixing lamp with multiple different presets using an Arduino Nano, an IR receiver/remote as well as an RGB LED. Note that soldering is required for this specific project build. 

## Schematics
The [schematics](schematics) folder contains circuit diagrams to guide you through the wiring process. Each connection is clearly labeled to ensure accuracy and ease of assembly.


## 3D Print Files
In the [3DPrintFiles](3DPrintFiles) folder, you'll find STL files for 3D printing custom enclosures and parts for the project. These files are designed to fit the components perfectly, providing a neat and esthetic finish to your project.

## Arduino Code
The [code](Code) folder contains the Arduino sketches necessary to run the project. Each script is well-documented with comments explaining the functionality of different sections.

## How to Use
1. Download or Clone the Repository:

```bash
   git clone https://github.com/TristanCD116/Lotus-Flower.git
```

2. Assemble the Hardware: Follow the schematics to wire your components correctly.

3. 3D Print the Enclosures: Use the provided STL files to print the necessary parts.

4. Configure: Upload the [IRRemoteSetupCode.ino](Code/IRRemoteSetupCode.ino) file to the arduino IDE and obtain your IR remote adresses.

5. Upload: Upload the [LotusFlowerCode.ino](Code/LotusFlowerCode.ino) to the arduino IDE and swap out the placeholder button adresses. 
  
6. Run and Test: Power up your device and observe its functionality.

## Contributing
Contributions are welcome! If you have any improvements or suggestions, feel free to fork the repository and create a pull request. Please follow the contributing guidelines.

## Acknowledgments
- IR remote library used in this program was created by [shirriff, z3t0 and ArminJoe](https://github.com/Arduino-IRremote)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
