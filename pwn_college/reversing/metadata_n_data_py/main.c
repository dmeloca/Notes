#include <fcntl.h>
#include <unistd.h>

#define FILE_NAME "image.cimg"
#define FLAGS     O_CREAT|O_WRONLY|O_TRUNC

int
main(){
	int image_fd = open(FILE_NAME, FLAGS, 0644);
	if (image_fd == -1) return -1;
	char header[] = {'<', ':', 'M', 'G', 0x01, 0x00, 0x32, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	char data[550] = { 0 };
	write(image_fd, header, sizeof(header));
	write(image_fd, data, sizeof(data));
	close(image_fd);
	return 0;
}
