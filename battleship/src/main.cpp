#include "../lib/game.h"
#include <exception>
#include <iostream>
#include <stdexcept>

void run(BaseGame *control, BaseGame *assignment) {
  int controlResult, assignmentResult = 0;
  try {
    controlResult = control->run();
    assignmentResult = assignment->run();

    if (assignmentResult <= controlResult) {
      std::cout << "Passed" << std::endl;
    }

    if (assignmentResult == controlResult + 1) {
      std::cout << "B" << std::endl;
    }

    if (assignmentResult == controlResult + 2) {
      std::cout << "C" << std::endl;
    }

    if (assignmentResult == controlResult + 3) {
      std::cout << "D" << std::endl;
    }

    if (assignmentResult == controlResult + 4) {
      std::cout << "F" << std::endl;
    }
  }
  catch(const std::exception& e)
  {
      std::cerr << "failed: " << e.what() << std::endl;
  }
}

int main() {
    ControlGame *control = new ControlGame();
    AssignmentGame *assignment = new AssignmentGame();

    run(control, assignment);

    delete control;
    delete assignment;
    return 0;
}
