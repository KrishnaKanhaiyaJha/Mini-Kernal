
// Made for B.Tech OS Project - 100% Working

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>  // For Sleep(), system("cls"), color

#define MAX_PROCESSES 10
#define MAX_FILES 10


typedef struct {
    int pid;
    char name[20];
    int status; // 1=running
} Process;

Process processes[MAX_PROCESSES];
int process_count = 0;

//  File System
typedef struct {
    char filename[20];
    char content[200];
} File;

File filesystem[MAX_FILES];
int file_count = 0;

// Colors
void red()    { printf("\033[1;31m"); }
void yellow() { printf("\033[1;33m"); }
void green()  { printf("\033[0;32m"); }
void cyan()   { printf("\033[0;36m"); }
void reset()  { printf("\033[0m"); }

//  boot animation
void boot_animation() {
    system("cls");
    printf("\n\n\n");
    cyan();
    printf("            ███╗   ███╗██╗███╗   ██╗██╗    ██╗ █████╗ ██████╗ ███████╗\n");
    printf("            ████╗ ████║██║████╗  ██║██║    ██║██╔══██╗██╔══██╗██╔════╝\n");
    printf("            ██╔████╔██║██║██╔██╗ ██║██║ █╗ ██║███████║██████╔╝█████╗  \n");
    printf("            ██║╚██╔╝██║██║██║╚██╗██║██║███╗██║██╔══██║██╔══██╗██╔══╝  \n");
    printf("            ██║ ╚═╝ ██║██║██║ ╚████║╚███╔███╔╝██║  ██║██║  ██║███████╗\n");
    printf("            ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝\n");
    reset();
    yellow();
    printf("\n                     MiniWare Operating System v1.0\n");
    printf("                     Booting kernel...\n");
    Sleep(1500);
    printf("                     Initializing memory... OK\n"); Sleep(800);
    printf("                     Mounting filesystem... OK\n"); Sleep(800);
    printf("                     Starting services... OK\n"); Sleep(1000);
    green();
    printf("\n        Welcome to MiniWare OS! Type 'help' for commands.\n\n");
    reset();
}

// Add  background processes
void init_processes() {
    strcpy(processes[0].name, "init");     processes[0].pid = 1; processes[0].status = 1;
    strcpy(processes[1].name, "kworker");  processes[1].pid = 2; processes[1].status = 1;
    strcpy(processes[2].name, "shell");    processes[2].pid = 3; processes[2].status = 1;
    strcpy(processes[3].name, "networkd"); processes[3].pid = 4; processes[3].status = 1;
    process_count = 4;
}

void cmd_help() {
    printf("\nAvailable commands:\n");
    printf("  help     - Show this help\n");
    printf("  clear    - Clear screen\n");
    printf("  ps       - Show running processes\n");
    printf("  date     - Show current date & time\n");
    printf("  createfile <name> - Create a file\n");
    printf("  listfiles - List all files\n");
    printf("  cat <name> - View file content\n");
    printf("  reboot   - Restart OS\n");
    printf("  exit     - Shutdown\n\n");
}

void cmd_ps() {
    printf("\nPID\tSTATUS\tNAME\n");
    printf("--------------------------------\n");
    for(int i = 0; i < process_count; i++) {
        printf("%d\t%s\t%s\n", processes[i].pid,
               processes[i].status ? "Running" : "Stopped",
               processes[i].name);
    }
}

void cmd_date() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("\nCurrent Date & Time: %s\n", asctime(tm));
}

void cmd_createfile(char *name) {
    if(file_count >= MAX_FILES) {
        red(); printf("Error: Disk full!\n"); reset();
        return;
    }
    strcpy(filesystem[file_count].filename, name);
    strcpy(filesystem[file_count].content, "This is a new file created in MiniWare OS!");
    file_count++;
    green(); printf("File '%s' created successfully!\n", name); reset();
}

void cmd_listfiles() {
    if(file_count == 0) {
        printf("\nNo files in system.\n");
        return;
    }
    printf("\nFiles in system:\n");
    for(int i = 0; i < file_count; i++) {
        printf("  %s\n", filesystem[i].filename);
    }
}

void cmd_cat(char *name) {
    for(int i = 0; i < file_count; i++) {
        if(strcmp(filesystem[i].filename, name) == 0) {
            printf("\nContent of %s:\n%s\n", name, filesystem[i].content);
            return;
        }
    }
    red(); printf("File not found!\n"); reset();
}

int main() {
    char cmd[100], arg[50];

    boot_animation();
    init_processes();

    while(1) {
        cyan();
        printf("root@MiniWare:~# ");
        reset();
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = 0; // remove newline

        if(strcmp(cmd, "help") == 0) cmd_help();
        else if(strcmp(cmd, "clear") == 0) system("cls");
        else if(strcmp(cmd, "ps") == 0) cmd_ps();
        else if(strcmp(cmd, "date") == 0) cmd_date();
        else if(strcmp(cmd, "listfiles") == 0) cmd_listfiles();
        else if(strcmp(cmd, "reboot") == 0) { printf("Rebooting...\n"); Sleep(1000); main(); }
        else if(strcmp(cmd, "exit") == 0) { red(); printf("\nShutting down...\n"); Sleep(1500); break; }
        else if(sscanf(cmd, "createfile %s", arg) == 1) cmd_createfile(arg);
        else if(sscanf(cmd, "cat %s", arg) == 1) cmd_cat(arg);
        else if(strlen(cmd) > 0) {
            red(); printf("Command not found: %s\nType 'help' for commands.\n", cmd); reset();
        }
    }

    return 0;
}