# Wheels on the Bus

## 🚍 Project Overview
**Wheels on the Bus** is a C++ project that simulates a smart bus onboarding system. The system efficiently manages passenger onboarding based on various constraints, including:

- Passenger arrival time
- Bus arrival time at the station
- Bus capacity
- Priority boarding for elderly, disabled individuals, and pregnant women

The project utilizes multiple data structures such as **trees, linked lists, stacks and priority queues** to ensure an optimized and fair onboarding process.

## 📌 Features
- **Dynamic Passenger Management**: Tracks passenger arrival times and stores them efficiently.
- **Priority-based Boarding**: Ensures that elderly, disabled individuals, and pregnant women are boarded first.
- **Capacity Handling**: Ensures that the bus does not exceed its maximum capacity.
- **Optimized Data Processing**: Utilizes trees, linked lists, and priority queues for efficient processing.
- **Simulation Mode**: Simulates the real-time operation of a bus stop.

## 🛠 Technologies Used
- **C++** (Core language for the system logic)
- **Data Structures**: Trees, Linked Lists, Priority Queues, and more.

## 🚀 Getting Started
### Prerequisites
Ensure you have the following installed on your system:
- A C++ compiler (GCC, MSVC, Clang, etc.)
- Any C++ IDE (optional, e.g., Visual Studio Code, CLion, Code::Blocks)


## 📖 How It Works
- Passengers are stored in a **linked list** upon arrival at the station.
- A **priority queue** manages passengers based on priority (elderly, disabled, pregnant women first).
- The bus arrives at the station, and the system processes passengers accordingly.
- If the bus reaches full capacity, remaining passengers wait for the next bus.

## 📝 Future Enhancements
- Implement a GUI for better visualization.
- Add real-time user input for dynamic simulations.
- Extend the system to handle multiple bus routes.

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

