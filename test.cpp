#include <ATen/detail/CPUGuardImpl.h>  //ADDED first line
#include <torch/torch.h>
#include <iostream>
#include <exception>
#include <stdexcept>


int main() {
  try {
    C10_REGISTER_GUARD_IMPL(CPU, at::detail::CPUGuardImpl); //ADDED second line
    torch::Tensor tensor = torch::ones({2, 3});
    std::cout << tensor + tensor << std::endl;
    //std::cout  << "hello"  << std::endl;
  } catch (...) {
    try {
      std::exception_ptr curr_excp;
      if (curr_excp = std::current_exception())	{
	std::rethrow_exception(curr_excp);
      }
    } catch (const std::exception& e) {
      std::cout << e.what();
    }
  }
}
