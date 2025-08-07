
#include "dl_model.hpp"
#include <string.h>

const char* TAG = "PREPROCESSOR";



const char* gram_names[] = {
    "Gram Negative",      // index 0
    "Gram Positive",      // index 1
};

const char* bacteria_names[] = {
    "E.coli",         // index 0
    "Kp",             // index 1
    "Pa",   // index 2
    "Sa-",   // index 3
    "Sa"        // index 4
};

const char* concentration_names[] = {
    "102",         // index 0
    "103",             // index 1
    "104",   // index 2
    "105",   // index 3
    "106",       // index 4
    "107"        // index 5
};

// std::map<std::string, TensorBase *> read_csv_file_into_tensor(){


//     std::map<std::string, TensorBase *> graph_test_inputs;
//     std::string input_name = "input";  // Single input named "input"

//     int height = 70;
//     int width = 16;
//     int total_size = height * width;

//     float *random_data = new float[total_size];
//     for (int i = 0; i < total_size; i++) {
//         random_data[i] = static_cast<float>(std::rand()) / RAND_MAX;  // Random data between [0, 1)
//     }
//     std::vector<int> shape = {height, width};

//     // Create TensorBase with shape and random data
//     TensorBase *input_tensor = new TensorBase(shape, random_data);

//     // Add tensor to graph_test_inputs map
//     graph_test_inputs[input_name] = input_tensor;

//     return graph_test_inputs;
// }



/* Class: enose_data */
const std::vector<std::string> enose_data::channel = {
    "step", "ch1", "ch2", "ch3", "ch4", "ch5", "ch6", "ch7", "ch8",
    "ch9", "ch10", "ch11", "ch12", "ch13", "ch14", "ch15", "ch16"
    // , "temp", "humidity", "pressure"
};

bool enose_data::read_csv_file(FILE* f)
{
    if (f == NULL) {
        std::cerr << "File pointer is NULL" << std::endl;
        return false;
    }

    char line[512];

    // 讀取第一行，獲取所有欄位名稱
    if (fgets(line, sizeof(line), f) == NULL) {
        std::cerr << "Failed to read the header line" << std::endl;
        return false;
    }

    std::vector<std::string> header;
    char* token = strtok(line, ",");
    while (token != NULL) {
        header.push_back(std::string(token));
        token = strtok(NULL, ",");
    }

    // 建立欄位名稱到索引的映射表
    std::map<std::string, int> header_index;
    for (int i = 0; i < header.size(); ++i) {
        header_index[header[i]] = i;
    }

    // 檢查所需欄位是否存在於檔案中
    std::vector<int> selected_indices;
    for (const auto& col : channel) {
        if (header_index.find(col) != header_index.end()) {
            selected_indices.push_back(header_index[col]);
        } else {
            std::cerr << "Column " << col << " not found in the file" << std::endl;
            return false;
        }
    }

    // 逐行讀取檔案，篩選並存儲所需欄位
    while (fgets(line, sizeof(line), f)) {
        std::vector<std::string> row_data;
        int col_index = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            if (std::find(selected_indices.begin(), selected_indices.end(), col_index) != selected_indices.end()) {
                row_data.push_back(std::string(token));  // 只存入選中的欄位
            }
            token = strtok(NULL, ",");
            col_index++;
        }
        data.push_back(row_data);
        data_len++;
    }

    std::cout << "Finished reading and filtering CSV file" << std::endl;
    return true;
}



std::vector<int> enose_data::get_STEP_indices(const std::vector<std::string>& stages) const{
    std::vector<int> indices;
    
    // 找到 "step" 欄位的索引
    int step_index = -1;
    for (int i = 0; i < channel.size(); ++i) {
        if (channel[i] == "step") {
            step_index = i;
            break;
        }
    }

    if (step_index == -1) {
        std::cerr << "Error: 'step' column not found in channel" << std::endl;
        return indices;
    }

    // 遍歷 data，篩選出 "step" 欄位為 "Prep" 的行
    for (int i = 0; i < data.size(); ++i) {
        if (std::find(stages.begin(),stages.end(),data[i][step_index]) != stages.end()) {
            indices.push_back(i);  // 記錄行索引
        }
    }

    return indices;
}


std::vector<double> enose_data::calculate_mean_for_channels(const std::vector<int>& indices) const{
    std::vector<int> sum(16, 0.0);  // 累加每個通道的總和
    int count = indices.size();        // 記錄總行數

    // 找到 "ch1" 和 "ch16" 的索引範圍
    int ch_start_index = -1;
    int ch_end_index = -1;
    for (int i = 0; i < channel.size(); ++i) {
        if (channel[i] == "ch1") ch_start_index = i;
        if (channel[i] == "ch16") ch_end_index = i;
    }

    if (ch_start_index == -1 || ch_end_index == -1) {
        std::cerr << "Error: 'ch1' to 'ch16' columns not found in channel" << std::endl;
        return {};
    }

    for (const auto& row_index : indices) {
        for (int i = ch_start_index; i <= ch_end_index; ++i) {
            sum[i - ch_start_index] += std::stoi(data[row_index][i]);  // 將字串轉換為浮點數並累加
        }
    }
    std::vector<double> mean(16, 0.0);
    for (int i = 0; i < 16; ++i) {
        mean[i] = static_cast<double>(sum[i]) / static_cast<double>(count);
    }

    return mean;
}

std::vector<std::vector<int>> enose_data::get_baseline_removal_data(const std::vector<int>& indices, const int len) const{
    std::vector<int> chx;
    std::vector<std::vector<int>> result;

    for (int i = 0; i < channel.size(); ++i) {
        if (channel[i] != "step") {
            chx.push_back(i);
        }
    }

    for (int i = 0; i < data.size() && i < len ; ++i) {
        std::vector<int> row;
        int row_index = indices[i];

        for (int col_index : chx) {
            row.push_back(std::stod(data[row_index][col_index]));  // 將字串轉換為浮點數並加入結果
        }
        result.push_back(row);
    }

    return result;
}







/* Functions */
void print_V_Vector_data(const std::vector<std::vector<std::string>>& data, int rows){
    for (int i = 0; i < rows && i < data.size(); ++i) {
        for (const auto& val : data[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void print_V_Vector_data(const std::vector<std::vector<int>>& data, int rows){
    for (int i = 0; i < rows && i < data.size(); ++i) {
        for (const auto& val : data[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void print_V_Vector_data(const std::vector<std::vector<float>>& data, int rows){
    for (int i = 0; i < rows && i < data.size(); ++i) {
        for (const auto& val : data[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}


std::vector<std::vector<double>> subtract_mean_from_measure(
    const std::vector<std::vector<int>>& measure_data,
    const std::vector<double>& mean_values) {

    std::vector<std::vector<double>> result;

    // 檢查 mean_values 的大小是否與 measure_data 的每一行一致
    if (measure_data.empty() || measure_data[0].size() != mean_values.size()) {
        std::cerr << "Error: Size mismatch between measure data and mean values" << std::endl;
        return result;
    }

    // 遍歷 measure_data，每一行與 mean_values 相減
    for (const auto& row : measure_data) {
        std::vector<double> diff;

        for (size_t i = 0; i < row.size(); ++i) {
            diff.push_back(row[i] - mean_values[i]);  // 相減
        }
        result.push_back(diff);
    }

    return result;
}


float* convert_to_float_array(const std::vector<std::vector<float>>& data) {
    int total_size = 0;
    for (const auto& row : data) {
        total_size += row.size();
    }

    // 2. 分配 float 陣列
    float* float_array = new float[total_size];

    // 3. 將 good_data 的元素拷貝到 float 陣列中
    int index = 0;
    for (const auto& row : data) {
        for (const auto& val : row) {
            float_array[index++] = static_cast<float>(val);  // 轉換為 float 並存入陣列
        }
    }

    return float_array;
}


float* normalize_and_convert_to_float_array(const std::vector<std::vector<double>>& data) {

    if (data.empty() || data[0].empty()) {
        return nullptr;
    }

    int num_rows = data.size();        // 資料的行數
    int num_cols = data[0].size(); 

    // 分配 float 陣列
    float* float_array = new float[num_rows*num_cols];

    std::vector<double> min_vals(num_cols, std::numeric_limits<double>::max());
    std::vector<double> max_vals(num_cols, std::numeric_limits<double>::lowest());

    for (const auto& row : data){
        for (int j = 0; j < num_cols; ++j) {
            min_vals[j] = std::min(min_vals[j], row[j]);
            max_vals[j] = std::max(max_vals[j], row[j]);
        }
    } 

    int index = 0;
    for (const auto& row : data) {
        for (int j = 0; j < num_cols; ++j) {
            // 若除以零，則設為 0
            if (max_vals[j] == min_vals[j]) {
                float_array[index++] = 0.0f;
            } else {
                float_array[index++] = static_cast<float>((row[j] - min_vals[j]) / (max_vals[j] - min_vals[j]));
            }
        }
    }
    
    return float_array;
}



// Function to generate random input tensor with shape (3, 32, 32)
std::map<std::string, TensorBase *> generate_inputs(float* data) {


    std::map<std::string, TensorBase *> graph_inputs;
    std::string input_name = "input";  // Single input named "input"

    // Define tensor shape (3, 32, 32)
    // int channels = 1;
    int height = 70;
    int width = 16;


    // Create shape as std::vector<int>
    std::vector<int> shape = {height, width};

    // Create TensorBase with shape and random data
    // TensorBase *input_tensor = new TensorBase(shape, data,);

    TensorBase *input_tensor = new TensorBase(
        shape,
        data,           
        0,                    
        dl::DATA_TYPE_FLOAT,    
        true,                   
        MALLOC_CAP_8BIT         
    );

    // Add tensor to graph_test_inputs map
    graph_inputs[input_name] = input_tensor;

    return graph_inputs;
}


const char* classify_species(const char *filename) {
    if (strstr(filename, "Sa-") != NULL) {
        return "Sa-";
    } else if (strstr(filename, "Sa") != NULL) {
        return "Sa";
    } else if (strstr(filename, "E.coli") != NULL) {
        return "E.coli";
    } else if (strstr(filename, "Pa") != NULL) {
        return "Pa";
    } else if (strstr(filename, "Kp") != NULL) {
        return "Kp";
    } else {
        return "Unknown";  
    }
}

const char* classify_concentration(const char *filename) {

    if (strstr(filename, "102") != NULL) {
        return "102";
    } else if (strstr(filename, "103") != NULL) {
        return "103";
    } else if (strstr(filename, "104") != NULL) {
        return "104";
    } else if (strstr(filename, "105") != NULL) {
        return "105";
    } else if (strstr(filename, "106") != NULL) {
        return "106";
    } else if (strstr(filename, "107") != NULL) {
        return "107";
    } else {
        return "Unknown";
    }
}

