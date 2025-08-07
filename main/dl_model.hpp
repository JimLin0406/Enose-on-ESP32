#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP





#include "dl_model_base.hpp"
#include <stdio.h>
#include "esp_log.h"
#include "esp_timer.h"
#include <vector>
#include <string>





using namespace dl;

/* Class: enose_data */
class enose_data
{
private:
    int data_len;
    // std::vector<std::vector<std::string>> data;  

public:
    std::vector<std::vector<std::string>> data;  
    static const std::vector<std::string> channel;

    enose_data() : data_len(0) {}
    bool read_csv_file(FILE* f);
    std::vector<int> get_STEP_indices(const std::vector<std::string>& stages) const;
    std::vector<double> calculate_mean_for_channels(const std::vector<int>& indices) const;
    std::vector<std::vector<int>> get_baseline_removal_data(const std::vector<int>& indices, const int len) const;
};


/* Functions */
std::vector<std::vector<double>> subtract_mean_from_measure(const std::vector<std::vector<int>>& measure_data, const std::vector<double>& mean_values);
void print_V_Vector_data(const std::vector<std::vector<std::string>>& data, int rows);
void print_V_Vector_data(const std::vector<std::vector<int>>& data, int rows);
void print_V_Vector_data(const std::vector<std::vector<float>>& data, int rows);
float* convert_to_float_array(const std::vector<std::vector<float>>& data);
float* normalize_and_convert_to_float_array(const std::vector<std::vector<double>>& data);

std::map<std::string, TensorBase *> generate_inputs(float* data);
const char* classify_species(const char *filename);
const char* classify_concentration(const char *filename);

extern const char* gram_names[];
extern const char* bacteria_names[];
extern const char* concentration_names[];




#endif  // PREPROCESSOR_H