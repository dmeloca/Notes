#include <fcntl.h>
#include <unistd.h>
#define FILE_NAME "image.cimg"
int
main(){
	int fd = open(FILE_NAME, O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if (fd==-1) return -1;
	char header[] = {0x5b, 0x4f, 0x4e, 0x72};
	write(fd, header, sizeof(header));
	close(fd);
	return 0;
}
