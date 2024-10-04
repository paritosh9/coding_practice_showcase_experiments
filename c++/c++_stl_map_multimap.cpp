#include <iostream>
#include <map>
#include <vector>

void percentage_execution_time(std::map<int, std::multimap<std::string, std::vector<int>>> &metrics_map_multimap){
    
    int total_kernel_exec_time = 0;
    int start_time = 0;
    int end_time = 0;
    float p_time = 0;
    
    for(auto i : metrics_map_multimap){
        total_kernel_exec_time = 0;
        int k_id = i.first;
        std::cout << "kernel id : " << k_id << std::endl;
        for(auto j : i.second){
            std::cout << "      subfunction name : " << j.first << std::endl; 
            if((j.first != "start time") && (j.first != "end time")) {
                for(auto k : j.second){
                    total_kernel_exec_time += k;     
                }  
            } else if(j.first == "start time"){
                start_time = j.second[0];    
            } else if(j.first == "end time"){
                end_time = j.second[0];
            } 
        }
        
        int total_time = end_time - start_time;
        std::cout << "    total exec time : " << total_kernel_exec_time << std::endl;
        std::cout << "    total  time : " << total_time << std::endl;
        p_time = (float)((100.0*total_kernel_exec_time/total_time));
        std::cout << "    percentage exec time : " << p_time << std::endl;
    }
}


int main()
{
    std::map<int, std::multimap<std::string, std::vector<int>>> metrics_map_multimap = {
        {1,{{"startup",{2}}, {"mem_trsfr",{10}}, {"compute",{10,20}}, {"mem_trsfr",{10}}, {"start time",{0}}, {"end time",{300}}}},
        {2,{{"startup",{3}}, {"mem_trsfr",{10,30}}, {"compute",{15,20}}, {"mem_trsfr",{11}}, {"start time",{0}}, {"end time",{300}}}},
        {3,{{"startup",{1}}, {"mem_trsfr",{10}}, {"compute",{12,20}}, {"mem_trsfr",{14,11}}, {"start time",{0}}, {"end time",{300}}}},
        {4,{{"startup",{2,3}}, {"mem_trsfr",{10}}, {"compute",{10,22}}, {"mem_trsfr",{10}}, {"start time",{0}}, {"end time",{300}}}}
    };
    
    percentage_execution_time(metrics_map_multimap);

    return 0;
}
