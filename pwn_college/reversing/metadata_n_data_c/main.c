#include <fcntl.h>
#include <unistd.h>

#define FILE_NAME "image.cimg"
#define FLAGS O_CREAT|O_WRONLY|O_TRUNC
#define PERMS 0644

int
main(){
	int image_fd = open(FILE_NAME, FLAGS, PERMS);
	if (image_fd == -1) return -1;
	char magic_numbers[] = {'C','m','g', 'E'};
	char version[] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	char size[] = {0x3b, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00};
	char data[59*21] = { 0 };
	write(image_fd, magic_numbers, sizeof(magic_numbers));
	write(image_fd, version, sizeof(version));	
	write(image_fd, size, sizeof(size));
	write(image_fd, data, sizeof(data));
	close(image_fd);
	return 0;
}
