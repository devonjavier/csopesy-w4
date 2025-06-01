#include <string>
#include <ctime>
#include <vector>
#include <unordered_map>

// CPU ITSELF
float cpu_util;                             // CPU Utilization Percentage SHOULD BE BASED AND COMPUTED ON PROCESSES
int cores_used;                             // no. of cores used
int cores_total;                            // total no. of cores

// a process changes states
class Process {
    // # 1 
    int pid;                                    // Process ID
    std::string p_name;                         // Process name
    std::time_t p_time;                         // Process Time (Time Created)
    int p_counter;                              // Program Counter (Current Instruction)
    std::vector<std::string> p_instructions;    // instruction history

    int p_cores_used;                             // no. of cores used
    int p_cores_total;                            // total no. of cores

    Process(std::string name, int id, int cores) 
        : p_name(name), pid(id), p_cores_used(cores), p_cores_total(cores), p_counter(0) {
        p_time = std::time(nullptr);
    }

    // #1 
    int execute_instruction(std::string instruction) const {
        // used to take new input and then add it to the instruction vector
        // determine what to do with insturction 
        
        // int ret_instruction = -1;
        // switch (instruction){
        //     case "":
        //      ret_instruction = 0;
        //      break;
        //     case "":
        //      ret_instruction = 1;
        //      break;
        //     case "":
        //      ret_instruction = 2;
        //      break;
        //     case "":
        //      ret_instruction = 3;
        //      break; 
        //     default:}

        // p_instructions.push_back(instruction);
        // p_counter++;

        // return ret_instruction;
    }


    // #2
    std::string get_current_instruction() const {
    //     used to get the instruction at a specific index
    //     if (index < 0 || index >= p_instructions.size()) {
    //         return "N/A";
    //     }
    //     return p_instructions[p_counter];
    }
};


class ProcessManager{
    private:
    // #3 this stores multiple processes
    std::unordered_map<int, Process> processMap;

    public:

    // #3 & 4 adds processes to the unordered map
    void add_process(const Process& process) {
        // processes.insert({process.pid, process});  
    }

    // #4 
    Process* getProcessByPid(int pid) {
        // auto it = processMap.find(pid);
        // if (it != processMap.end()) {
        //     return &it->second;
        // }
        // return nullptr; // Not found
    }
};