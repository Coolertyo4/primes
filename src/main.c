
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "args.h"
#include "cpu.h"
#include "gpu.h"
#include "log.h"
#include "timing.h"


int main(int argc, char *argv[]) {
  int status;
  long number = (long)0xABCDEFCFD31;

  bool cpu = false;
  bool timer = false;
  bool return_result = false;
  bool no_output = false;
  int result;

  parseArgs(argc, argv, &cpu, &timer, &return_result, &no_output, &number);

  if(cpu && !no_output) Warning("Running on CPU (Much slower)\n");
  startTimer();
  status = cpu ? runCPU(number, &result): run(number, &result);
  endTimer();
  if (!no_output)
    Info("Number %ld is %s!\n", number, result ? "prime" : "not prime");
  if (timer) {
    TimerResult r = getTimerResult();
    Info("%fs %fns\n", r.delta_s, r.delta_ns);
  }

  if (return_result)
    return result;
  else
    return status;
}
