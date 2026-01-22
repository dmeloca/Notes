#include <fcntl.h>
#include <unistd.h>
#define FILE_NAME "image.cimg"

int
main(){
	int fd = open(FILE_NAME, O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if (fd==-1) return 1;
	char header[] = {0x28, 0x7e, 0x6d, 0x36};
	write(fd, header, sizeof(header));
	close(fd);
	return 0;
}
