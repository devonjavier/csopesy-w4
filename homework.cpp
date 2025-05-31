#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>

struct Process {
    int gpu;
    int gi;
    int ci;
    int pid;
    std::string type;
    std::string name;
    float gpu_memory_usage;

    Process(int gpu, int gi, int ci, int pid, const std::string& type, const std::string& name, float gpu_memory_usage)
        : gpu(gpu), gi(gi), ci(ci), pid(pid), type(type), name(name), gpu_memory_usage(gpu_memory_usage) {}

    std::string intOrNA(int value) const {
        if (value < 0) {
            return "N/A";
        } else {
            return std::to_string(value);
        }
    }

    void printProcess() const {
    int gpu_width = 6;
    int gi_width = 5;
    int ci_width = 10;
    int pid_width = 6;
    int type_width = 6;
    int name_width = 42;
    int memory_usage_width = 11;

    std::string temp_name = name;
    if (name.length() > name_width) {
        temp_name = "..." + name.substr(name.length() - (name_width - 3)); // e.g. last 39 chars
    }

    std::ostringstream mem_ss;
    if (gpu_memory_usage >= 0) {
        mem_ss << std::fixed << std::setprecision(1) << gpu_memory_usage << "MiB";
    } else {
        mem_ss << "N/A";
    }

    std::cout << "|  "
              << std::setw(gpu_width) << std::left << intOrNA(gpu)
              << std::setw(gi_width) << std::left << intOrNA(gi)
              << std::setw(ci_width) << std::left << intOrNA(ci)
              << std::setw(pid_width) << std::left << pid
              << std::setw(type_width) << std::left << type
              << std::setw(name_width) << std::left << temp_name << std::right
              << std::setw(memory_usage_width) << mem_ss.str()
              << " |" << std::endl;
}
};

std::vector<Process> processes1 = {
    Process(1, -1, 4, 100, "C+G", "C:\\System\\proc1.exe", 1.2f),
    Process(2, -1, 2, 150, "C+G", "C:\\System\\proc2.exe", 2.5f),
    Process(3, -1, 1, 200, "C+G", "C:\\System\\proc3.exe", 3.1f),
    Process(4, -1, 3, 120, "C+G", "C:\\System\\proc4.exe", 4.7f),
    Process(5, -1, 2, 80,  "C+G", "C:\\System\\proc5.exe", 0.9f)
};

std::vector<Process> processes2 = {
    Process(6, 0, -1, 130, "C+G", "D:\\Apps\\RANDOM\\RANDOM\\RANDOM\\RANDOM\\proc6.exe", 5.4f),
    Process(7, 6, -1, 160, "C+G", "D:\\Apps\\RANDOM\\RANDOM\\RANDOM\\RANDOM\\RANDOM\\RANDOM\\proc7.exe", 6.2f),
    Process(8, 6, -1, 180, "C+G", "D:\\Apps\\RANDOM\\RANDOM\\RANDOM\\proc8.exe", 2.8f),
    Process(9, 7, -1, 140, "C+G", "D:\\Apps\\RANDOM\\RANDOM\\proc9.exe", 1.1f),
    Process(10, 8, -1, 90, "C+G", "D:\\Apps\\RANDOM\\RANDOM\\RANDOM\\RANDOM\\RANDOM\\proc10.exe", 3.3f)
};

std::vector<Process> processes3 = {
    Process(11, -1, -1, 210, "C+G", "E:\\Background\\proc11.exe", 4.9f),
    Process(12, -1, -1, 110, "C+G", "E:\\Background\\proc12.exe", 3.7f),
    Process(13, -1, -1, 130, "C+G", "E:\\Background\\proc13.exe", 2.2f),
    Process(14, -1, -1, 115, "C+G", "E:\\Background\\proc14.exe", 5.1f),
    Process(15, -1, -1, 170, "C+G", "E:\\Background\\proc15.exe", 6.0f)
};

std::vector<Process> processes4 = {
    Process(16, 0, 2, 100, "C+G", "F:\\Programs\\proc16.exe", 0.5f),
    Process(17, 16, 1, 95,  "C+G", "F:\\Programs\\proc17.exe", 1.6f),
    Process(18, 16, 3, 105, "C+G", "F:\\Programs\\proc18.exe", 2.4f),
    Process(19, 17, 2, 115, "C+G", "F:\\Programs\\proc19.exe", 3.0f),
    Process(20, 18, 4, 125, "C+G", "F:\\Programs\\proc20.exe", 4.4f)
};

std::vector<Process> processes5 = {
    Process(21, 0, 3, 155, "C+G", "G:\\Runtime\\proc21.exe", 1.3f),
    Process(22, 21, 2, 165, "C+G", "G:\\Runtime\\proc22.exe", 2.7f),
    Process(23, 21, 1, 175, "C+G", "G:\\Runtime\\proc23.exe", 3.8f),
    Process(24, 22, 3, 185, "C+G", "G:\\Runtime\\proc24.exe", 2.1f),
    Process(25, 23, 4, 195, "C+G", "G:\\Runtime\\proc25.exe", 0.6f)
};

int main() {
    std::time_t time = std::time(nullptr);
    std::vector<std::vector<Process>> all_processes = {
        processes1, processes2, processes3, processes4, processes5
    };

    std::cout << std::put_time(std::localtime(&time), "%a %b %d %H:%M:%S %Y") << std::endl;
    std::cout << "+-----------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "| NVIDIA-SMI 566.36                 Driver Version: 566.36         CUDA Version: 12.7     |" << std::endl;
    std::cout << "|-----------------------------------------+------------------------+----------------------+" << std::endl;
    std::cout << "| GPU  Name                  Driver-Model | Bus-Id          Disp.A | Volatile Uncorr. ECC |" << std::endl;
    std::cout << "| Fan  Temp   Perf          Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute M. |" << std::endl;
    std::cout << "|                                         |                        |               MIG M. |" << std::endl;
    std::cout << "|=========================================+========================+======================|" << std::endl;
    std::cout << "|   0  NVIDIA GeForce RTX 3050 ...  WDDM  |   00000000:01:00.0  On |                  N/A |" << std::endl;
    std::cout << "| N/A   46C    P5             12W /   40W |    1106MiB /   4096MiB |      2%      Default |" << std::endl;
    std::cout << "|                                         |                        |                  N/A |" << std::endl;
    std::cout << "+-----------------------------------------+------------------------+----------------------+" << std::endl;

    std::cout << std::endl;

    std::cout << "+-----------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "| Processes:                                                                              |" << std::endl;
    std::cout << "|  GPU   GI   CI        PID   Type   Process name                              GPU Memory |" << std::endl;
    std::cout << "|        ID   ID                                                               Usage      |" << std::endl;
    std::cout << "|=========================================================================================|" << std::endl;

    for (const auto& process_group : all_processes) {
        for (const auto& process : process_group) {
            process.printProcess();
        }
    }

    std::cout << "|=========================================================================================|" << std::endl;


        
    return 0;
}