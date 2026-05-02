🖥️ MiniWare Operating System

MiniWare OS is a Command-Line Based Operating System Simulation written in C for B.Tech OS Project.
It demonstrates core OS concepts like Process Management, File System, and Shell Commands in a simple and interactive way.

✨ Features

🔹 Boot Animation (Kernel Startup Simulation)

🔹 Background Process Simulation (init, kworker, shell, networkd)

🔹 Process Viewer (ps)

🔹 In-Memory File System

🔹 Create, Read & List Files

🔹 Date & Time Command

🔹 Colored Terminal Output

🔹 Interactive Shell Interface

🔹 Reboot & Shutdown Simulation


🛠️ Tech Stack
    *Language: C
    *Libraries: stdio.h, stdlib.h, string.h, time.h
    *System API: windows.h
    

💻 Supported Commands

Command	          Description
help	            Show available commands
clear	            Clear screen
ps	              Show running processes
date	            Show current date & time
createfile <name>	Create file
listfiles       	List all files
cat <name>	      View file content
reboot	          Restart OS
exit	            Shutdown system

🧠 System Design
   MiniWare OS simulates:

  *Process Table → Stores PID, Name, Status
  *Memory File System → Stores files in RAM
  *Command Interpreter (Shell) → Executes user commands
  *Boot Loader Simulation → Displays OS startup.

  ▶️ How to Run
Compile
bash
gcc miniware.c -o miniware

Run
bash
miniware
⚠️ Works on Windows only (uses windows.h)

🎯 Learning Outcomes

*Operating System Basics
*Process Management
*File System Working
*CLI (Command Line Interface)
*Shell Command Parsing
*Memory Storage Simulation

🚀 Future Improvements

*File Delete & Edit Command
*Process Kill (kill <pid>)
*CPU Scheduling (FCFS / Round Robin)
*Virtual Memory Simulation
*User Login System
*Linux Version (No windows.h)
*GUI Version

👨‍💻 Author

Krishna Kanhaiya Jha
B.Tech CSE — Operating System Project
