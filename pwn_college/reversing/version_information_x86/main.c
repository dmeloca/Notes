#include <fcntl.h>
#include <unistd.h>
#define FILE_NAME "image.cimg"
#define FLAGS	O_CREAT|O_WRONLY|O_TRUNC

int
main(){
	int image_fd = open(FILE_NAME, FLAGS, 0644);
	if (image_fd == -1) return -1;
	char header[] = {0x43, 0x4d, 0x61, 0x67, 0x64};
	write(image_fd, header, sizeof(header));
	close(image_fd);
	return 0;
}
