#include <fcntl.h>
#include <unistd.h>
#define FILE_NAME "image.cimg"

int
main(){
	int image_fd = open(FILE_NAME, O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if (image_fd==-1) return -1;
	char header[] = {0x63, 0x6e, 0x7e, 0x52};
	write(image_fd, header, sizeof(header));
	close(image_fd);
	return 0;
}
