#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 512


void main(){

	int fd;
	ssize_t res;
	char buf[BUFF];

	if (fd = open("fifo_x", O_RDONLY) < 0){
		perror("open");
	}

	while(res = read(fd, buf, BUFF) > 0) {

		if (write(STDOUT_FILENO, buf, res) != res) { 
			exit(1);
		}
	}
	close(fd);
}
