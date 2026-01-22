#include <fcntl.h>
#include <unistd.h>

int main() {
	char header[] = {'c', 'I', 'M', 'G', 0x02, 0x00, 0x00, 0x00};
	int fd = open("image.cimg", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    	if (fd < 0) return 1;
	write(fd, header, sizeof(header));
    	close(fd);
   	return 0;
}

