#include <fcntl.h>
#include <unistd.h>
#define FILE_NAME "image.cimg"

int
main(){
	int image_fd = open(FILE_NAME, O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if (image_fd == -1) return -1;
	char header[] = {'c', 'm', '6', 'e', 0x87, 0x00};
	write(image_fd, header, sizeof(header));
	return 0;
}
