#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define MAX_SOURCE_SIZE (0x100000)

const char *parseArgs(int argc, const char *argv[], int *ret);


int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  int ret = 0;
  const char *filename = parseArgs(argc, argv, &ret);
  if (ret != 0) {
    return ret;
  }
  ret = openKernel(filename);
  ret = compute();
  return ret;
}
const char *parseArgs(int argc, const char *argv[], int *ret) {
  if (argc == 2) {
    return argv[2];
  }
  fprintf(stderr, "Error: No filename provided!\n");
  return -1;
}