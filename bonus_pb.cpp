#include <iostream>
#include <fstream>

int Optimal_Bonus_Helper(int* B, int* p, int* ob, int j) {
  if (j==0) {
    return 0;
  }
  if (j==1) {
    ob[0] = B[0];
    return ob[0];
  }
  // j is 1-based, arrays are 0-based
  // but p has 0 as its first element, so it's kind of 1-based
  int bonus_at_j = B[j-1] + Optimal_Bonus_Helper(B, p, ob, p[j]);

  // only calculate optimal bonus of the table before if it's not already calculated, ie == 0
  if (ob[j-2] == 0) {
    ob[j-2] = Optimal_Bonus_Helper(B, p, ob, j-1);
  }
  
  // for j, select the maximum value of choosing j vs the previous table
  ob[j-1] = std::max(bonus_at_j, ob[j-2]);
  return ob[j-1];
}

int Optimal_Bonus(int* X, int* B, int n, int* ob, int L) {
  // create p array
  int p[n+1] = {0}; 
  for (int j = 0; j < n+1; j ++) {
    for (int i = j-1; i >=0; i--) {
      if (X[j-1] > 5 + X[i-1]) {
        p[j] = i;
        break;
      }
    }
  }
  return Optimal_Bonus_Helper(B, p, ob, n);
}


int main() {
  std::ofstream output;
  output.open("bonus_pb.txt", std::ios::out);
  int locations[] = {8, 10,15, 22, 26};
  int bonuses[] = {15, 5, 25, 15, 5};
  int num_locations = 5;
  int total_distance = 30;
  int output_bonuses[num_locations] = {0}; 
  int optimal_output_bonus = Optimal_Bonus(locations, bonuses, num_locations, output_bonuses, total_distance);
  // output
  // output j's from 1 to 5
  // for the purpose of output only, we will use i for indexes, 1-based
  output << "Table numbers (i)   | ";
  for (int i = 0; i < num_locations; i++) {
    output << std::to_string(i+1) + " | ";
  }
  output << std::endl;
  // output locations
  output << "Locations (x_i)     | ";
  for (int i = 0; i < num_locations; i++) {
    output << std::to_string(locations[i]) + " | ";
  }
  output << std::endl;
  // output bonuses
  output << "Bonuses (b_i)       | ";
  for (int i = 0; i < num_locations; i++) {
    output << std::to_string(bonuses[i]) + " | ";
  }
  output << std::endl;
  // output bonuses
  output << "Optimal bonus (m_i) | ";
  for (int i = 0; i < num_locations; i++) {
    output << std::to_string(output_bonuses[i]) + " | ";
  }
  output << std::endl;
  output << "Optimal bonus overall: " << std::to_string(optimal_output_bonus);
  return 0;
}



// how to output to a file
//#include <iostream>
//#include <fstream>
//int main( int argc, char* argv[] )
//{
//      std::ofstream myfile;
//      myfile.open ("example.csv");
//      myfile << "This is the first cell in the first column.\n";
//      myfile << "a,b,c,\n";
//      myfile << "c,s,v,\n";
//      myfile << "1,2,3.456\n";
//      myfile << "semi;colon";
//      myfile.close();
//      return 0;
//}