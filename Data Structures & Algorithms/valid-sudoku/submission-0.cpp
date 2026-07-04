class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    // This problem provides the board line by line
    // First make the representation of the board through line, box and collum
    vector<unordered_map<char, int>>  rows;
    vector<unordered_map<char, int>> collums;
    vector<unordered_map<char, int>> boxes;
    for(int i = 0; i < 9; ++i){
        unordered_map<char, int> tempRow;
        rows.push_back(tempRow);
        collums.push_back(tempRow);
        boxes.push_back(tempRow);
    }       
    // Each vector now has 9 maps within it
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            rows[i][board[i][j]]++; // Iterate the occurence
            collums[j][board[i][j]]++; // Setting the values to board
            // Formula = (R/3)*3+(C/3)
            boxes[((i/3)*3)+(j/3)][board[i][j]]++;       
        }
    }
    for(int i = 0; i < 9; ++i){
        for(const auto& [key,value] : rows[i]){
            if(value > 1 && key != '.'){
                return false;
            }
        }
        for(const auto& [key,value] : collums[i]){
            if(value > 1 && key != '.'){
                return false;
            }
        }
        for(const auto& [key,value] : boxes[i]){
            if(value > 1 && key != '.'){
                return false;
            }
        }
    }
    return true;
    }
};
