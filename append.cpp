#include <fcntl.h>
#include <string>
#include <unistd.h>

int main() {
  int fd = open("append", O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
  if (fd < 0)
    throw;
  int val = 5000;
  for (int i = 0; i < val; i++) {
    std::string what_to_write = std::to_string(i) + "\n";
    write(fd, what_to_write.c_str(), what_to_write.size());
    fsync(fd);
  }
  close(fd);
}