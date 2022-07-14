#include <fcntl.h>
#include <string>
#include <unistd.h>

static constexpr int val_size = 1024;
char hoge[val_size] = {};

int main() {
  int fd = open("append", O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
  if (fd < 0)
    throw;
  int n = 5000;
  for (int i = 0; i < n; i++) {
    write(fd, hoge, val_size);
    fdatasync(fd);
  }
  close(fd);
}