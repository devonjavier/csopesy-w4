#include <string>
#include <ctime>
#include <vector>

// a process changes states
class Process {
    // # 1 
    float cpu_util;
    std::string p_name;
    int pid;
    std::time_t p_time;
    int p_counter;
    int cores_used;
    int corse_total;
    std::vector<std::string> p_instructions;

    Process(std::string name, int id, int cores) 
        : p_name(name), pid(id), cores_used(cores), corse_total(cores), p_counter(0), cpu_util(0.0) {
        p_time = std::time(nullptr);
    }


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
    std::string get_instruction(int index) const {
    //     used to get the instruction at a specific index
    //     if (index < 0 || index >= p_instructions.size()) {
    //         return "N/A";
    //     }
    //     return p_instructions[index];
    }
};


class ProcessManager{
    private:
    std::vector<Process> processes;

    public:

    // #3
    void add_process(const Process& process) {
        // processes.push_back(process);
    };

    // #4
    Process* getProcessByPid(int pid) {
        // for (auto& process : processes) {
        //     if (process.pid == pid) {
        //         return &process;
        //     }
        // }
        // return nullptr; // Not found
    }


};