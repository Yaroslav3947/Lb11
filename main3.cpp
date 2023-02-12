#include <iostream>
#include <cmath>

double cube_root(double num) {
  return pow(num, 1.0/3.0);
}

double* transform_array(double* arr, int size) {
  double* result = new double[size];
  for (int i = 0; i < size; ++i) {
    result[i] = cube_root(arr[i]);
  }
  return result;
}

int main() {
  int size = 4;
  double arr[] = {1.0, 8.0, 27.0, 64.0};
  double* result = transform_array(arr, size);
  for (int i = 0; i < size; ++i) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  delete[] result;
  return 0;
}