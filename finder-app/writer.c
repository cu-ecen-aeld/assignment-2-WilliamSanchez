#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>

/*

• Accepts the following arguments: the first argument is a full path to a file (including
filename) on the filesystem, referred to below as writefile; the second argument is a text
string which will be written within this file, referred to below as writestr

• Exits with value 1 error and print statements if any of the arguments above were not
specified

• Creates a new file with name and path writefile with content writestr, overwriting any
existing file and creating the path if it doesn’t exist. Exits with value 1 and error print
statement if the file could not be created.

-----------------------------------------------------------------------------------

* One difference from the write.sh instructions in Assignment 1:  You do not need to make your "writer" utility create directories which do not exist.  You can assume the directory is created by the caller.

* Setup syslog logging for your utility using the LOG_USER facility.

* Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.

* Use the syslog capability to log any unexpected errors with LOG_ERR level.

*/




int main(int arg, char **argv)
{

    int fd;

    openlog(NULL,0,LOG_USER);
    
    if(argv[1] == NULL || argv[2] == NULL)
    {
    	syslog(LOG_ERR,"any of the arguments above were not specified");
    	return 1;
    }
    
    fd = open(argv[1],O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
    write(fd,argv[2],strlen(argv[2]));
    close(fd);    
    syslog(LOG_DEBUG,"Writing %s to %s",argv[1],argv[2]);
    //closelog();
    return 0;

}
