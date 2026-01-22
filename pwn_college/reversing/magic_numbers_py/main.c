#include <fcntl.h>
#include <unistd.h>
#define FILE_NAME "image.cimg"

int
main(){
	int fd = open(FILE_NAME, O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if (fd==-1) return 1;
	char header[] = {'<', 'M', 'A', 'G'};
	write(fd, header, sizeof(header));
	close(fd);
	return 0;
}
